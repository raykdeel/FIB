#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AIF3ERG4    


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }


  /**
   * Types and attributes for your player can be defined here.
   */
  const vector<Dir> dirs = {Down,Right,Up,Left};

  typedef vector<char> Row;
  typedef vector<Row> Matrix;
  Matrix Map;

    typedef vector<bool> BooleanRow;
    typedef vector<BooleanRow> BooleanMatrix;

  //const int x[4] = {0,0,1,-1};
  //const int y[4] = {1,-1,0,0};

  const int x[4] = {1,0,-1,0};
  const int y[4] = {0,1,0,-1};

  struct objective {
      Pos p1,p2;
      vector<int> path1;
      vector<int> path2;
      int d1;
      int d2;
      //int prio;
  };

  map<int,objective> objectives;
  typedef map<int,objective>::iterator itObj;

  bool alive(int id) {
      if(citizen(id).life == 0) return false;
      else return true;
  }




  
    void FarmingSimulator() {
        vector<int> w = warriors(me());
    	vector<int> b = builders(me());
        vector<int> path1;
        vector<int> path2;
    	//Dir GoForIt;
    	Citizen c;
    	//bool Confirmed = false;
    	for (int id : w) {
            if(alive(id)) {
            path1.clear();
            path2.clear();
            c = citizen(id);
		    Pos p = c.pos;
            Pos p2;
            findMoney(p,p2,path1, path2);
            if(path1.size() > 0) {
                objective obj;
                obj.p1 = p;
                obj.p2 = p2;
                obj.d2 = path2.size(); //d.second;
                obj.d1 = path1.size(); //d.first;
                obj.path1 = path1;
                obj.path2 = path2;
                objectives.insert(make_pair(id, obj));
                //move(id, dirs[obj.path1[round()]]);
                move(id, dirs[obj.path1[0]]);

                /*cerr <<endl;
                cerr<<"Warrior's (" << c.pos.i << "," << c.pos.j << ") dir is (" 
                << p.i << "," << p.j << "), distance is " << path1.size() << " and the path is: ";
                for(int i : obj.path1) cerr << obj.path1[i];
                cerr <<endl;
                cerr <<endl;*/        
            }
            }
        }

	    
	    for (int id : b) {
            if(alive(id)) {
            //move(id,dirs[1]);1=k
            path1.clear();
            path2.clear();
            c = citizen(id);
		    Pos p = c.pos;
            Pos p2;
            findMoney(p,p2,path1,path2);
            if(path1.size() > 0) {
                objective obj;
                obj.p1 = p;
                obj.p2 = p2;
                obj.d2 = path2.size(); //d.second;
                obj.d1 = path1.size(); //d.first;
                obj.path1 = path1;
                obj.path2 = path2;
                objectives.insert(make_pair(id, obj));
                //move(id, dirs[obj.path1[round()]]);
                move(id, dirs[obj.path1[0]]);
                /*cerr <<endl;
                cerr<<"Builder's (" << c.pos.i << "," << c.pos.j << ") dir is (" 
                << p.i << "," << p.j << "), distance is " << path1.size() << " and the path is: ";
                for(int i : obj.path1) cerr << obj.path1[i];
                cerr <<endl;
                cerr <<endl;*/
    		// Contact(id, GoForIt, Confirmed);
		    // if(Confirmed) move(id, GoForIt);
		    // else GetMoving(id);
	    }
        }
    }
        }
   
    void findMoney(Pos& p, Pos& p2, vector<int>& path1, vector<int>& path2) {
        pair<int,int> d{0,0};
        queue<pair<Pos,vector<int>>> Q;

        vector<int> test;
        Q.push(make_pair(p, test));
        BooleanMatrix seen(board_rows(), BooleanRow(board_cols(), false));
        seen[p.i][p.j] = true;
        bool found = false;
        while(!Q.empty() and not found) {
            Pos q = Q.front().first;
            vector<int> t = Q.front().second;
            Q.pop();
            if(cell(q.i, q.j).bonus == Money) {
                found = true;
                p.i = q.i; p.j = q.j; d.first = 1;
                path1 = t;
                
            }
            else {
                int k = 0;
                while(k < 4 and not found) { 
                    int u = q.i + x[k]; //0=DOWN, 1=UP,
                    int v = q.j + y[k]; 
                    if(pos_ok(Pos(u,v)) and cell(u,v).type != Building 
                    and not seen[u][v] and cell(u,v).id == -1) {
                        t.push_back(k);
                        if(cell(u,v).bonus == Money) {
                            found = true;
                            p.i = u; p.j = v; d.first = 1;
                            path1 = t;
                        }
                        vector<int> t2 = t;
                        Q.push(make_pair(Pos(u,v),t2));
                        seen[u][v] = true;
                        t.clear();
                        
                    }
                    ++k;
                
                }
            }
        }
   }




    /**********************\
        MAP MANAGEMENT

    \**********************/

  void initializeMap(){
      Cell ce;
      for(int i = 0; i < board_rows(); ++i) {
          Row m(board_cols());
          for(int j = 0; j < board_cols(); ++j) {
            ce = cell(i,j);
            if(ce.type == Building) m[j]='P';
            else if(ce.id != -1) {
                Citizen Enemy = citizen(ce.id);
                if(Enemy.player != me()) {
                    if(Enemy.type == Warrior) m[j]='W';
                    else m[j]='B';
                }else m[j]='Y';
            }
            else if(ce.weapon != NoWeapon) {
                if(ce.weapon == Hammer) m[j]='H';
                else if(ce.weapon == Gun) m[j]='G';
                else m[j]='Z';
            }
            else if(ce.bonus != NoBonus) {
                if(ce.bonus == Money) m[j]='M';
                else m[j]='F';
            }
            else m[j]='.';
          }
          Map.push_back(m);
      }
  }

  void actualizeMap() {
      Cell ce;
      for(int i = 0; i < board_rows(); ++i) {
          for(int j = 0; j < board_cols(); ++j) {
            ce = cell(i,j);
            if(ce.type != Building) {
                if(ce.id != -1) {
                    Citizen Enemy = citizen(ce.id);
                    if(Enemy.player != me()) {
                        if(Enemy.type == Warrior and Map[i][j] != 'W') Map[i][j]='W';
                        else if (Enemy.type == Builder and Map[i][j] !='B') Map[i][j]='W';
                    } else Map[i][j]='Y';
                }   
                else if(ce.weapon != NoWeapon) {
                    if(ce.weapon == Hammer and Map[i][j] != 'H') Map[i][j] = 'H';
                    else if(ce.weapon == Gun and Map[i][j] != 'G') Map[i][j] = 'G';
                    else if(ce.weapon == Bazooka and Map[i][j] != 'Z') Map[i][j] = 'Z';
                }
                else if(ce.bonus != NoBonus) {
                    if(ce.bonus == Money and Map[i][j] != 'M') Map[i][j] = 'M';
                    if(ce.bonus == Food and Map[i][j] != 'F') Map[i][j] = 'F';
                }
                else Map[i][j] = '.';
            }
        }
    }
  }

    /**********************\
            MAIN

    \**********************/


    

  /**
   * Play method, invoked once per each round.
   */

    virtual void play () {
        //if(!round()) initializeMap();
        //else actualizeMap();
        FarmingSimulator();
        /*for(int i = 0; i < board_rows(); ++i) {
            cerr << endl;
            for(int j = 0; j < board_cols(); ++j) {
                cerr << Map[i][j];
            }
        }
        cerr << endl;
        */

	
	
	//per cert jugador, mirar si destinacio valida.
	
  
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
