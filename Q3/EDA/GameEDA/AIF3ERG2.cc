#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AIF3ERG2


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
  const vector<Dir> dirs = {Down,Up,Right,Left};

  typedef vector<char> Row;
  typedef vector<Row> Matrix;
  Matrix Map;

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




  
    void FarmingSimulator() {
        vector<int> w = warriors(me());
    	vector<int> b = builders(me());
        vector<int> path1;
        vector<int> path2;
    	//Dir GoForIt;
    	Citizen c;
    	//bool Confirmed = false;
    	for (int id : w) {
            path1.clear();
            path2.clear();
            c = citizen(id);
		    Pos p = c.pos;
            Pos p2;
            pair<int,int> d = findMoney(p,p2,path1, path2);
            if(d.first > 0) {
                objective obj;
                obj.p1 = p;
                obj.p2 = p2;
                obj.d2 = d.second;
                obj.d1 = d.first;
                obj.path1 = path1;
                obj.path2 = path2;
                objectives.insert(make_pair(id, obj));
                if(round() <= int(obj.path1.size())) move(id, dirs[obj.path1[round()]]);

                //it = objectives.find(id);
                //it->second.p = p;
                //it->second.dist = d;
                cerr <<endl;
                cerr<<"Objective  1 of Warrior (" << c.pos.i << "," << c.pos.j << ") is (" 
                << p.i << "," << p.j << "), Distance is " << d.first << " and the Path is: ";
                for(auto i : obj.path1) { cerr << obj.path1[i] << ",";};
                cerr <<endl;
                cerr <<endl;
                cerr<<"Objective  2 of Warrior (" << c.pos.i << "," << c.pos.j << ") is (" 
                << p2.i << "," << p2.j << "), Distance is " << d.second << " and the Path is: ";
                for(auto i : obj.path2) { cerr << obj.path2[i] << ",";};
                cerr <<endl;
            } else cerr << "no treasure can be reached" << endl;
        
            
        }

	    
	    for (int id : b) {
            //move(id,dirs[1]);1=k
            path1.clear();
            path2.clear();
            c = citizen(id);
		    Pos p = c.pos;
            Pos p2;
            pair<int, int> d = findMoney(p,p2,path1,path2);
            if(d.first > 0) {
                objective obj;
                obj.p1 = p;
                obj.p2 = p2;
                obj.d2 = d.second;
                obj.d1 = d.first;
                obj.path1 = path1;
                obj.path2 = path2;
                objectives.insert(make_pair(id, obj));
                if(round() <= int(obj.path1.size())) move(id, dirs[obj.path1[round()]]);
                //it = objectives.find(id);
                //it->second.p = p;
                //it->second.dist = d;
                cerr<< endl; 
                cerr<<"Objective  1 of Builder (" << c.pos.i << "," << c.pos.j << ") is (" 
                << p.i << "," << p.j << "), Distance is " << d.first << " and the Path is: ";
                for(long unsigned int i = 0; i < obj.path1.size(); ++i) { cerr << obj.path1[i] << ",";};
                cerr <<endl;
                cerr <<endl;
                cerr<<"Objective  2 of Builder (" << c.pos.i << "," << c.pos.j << ") is (" 
                << p2.i << "," << p2.j << "), Distance is " << d.second << " and the Path is: ";
                for(long unsigned int i = 0; i < obj.path2.size(); ++i) { cerr << obj.path2[i] << ",";};
                cerr <<endl;
            } else cerr << "no treasure can be reached" << endl;
    		// Contact(id, GoForIt, Confirmed);
		    // if(Confirmed) move(id, GoForIt);
		    // else GetMoving(id);
	    }
    }

    /*bool findMoney(Pos& p) {
        queue<Pos> Q;
        if(Map[p.i][p.j] == 'P') return false;
        Map[p.i][p.j] = 'P';
        Q.push(p);
        while(!Q.empty()) {
            Pos q = Q.front();
            Q.pop();
            for(int i= 0; i < 4; ++i) {
                int u = q.i + x[i];
                int v = q.j + y[i];
                if(pos_ok(Pos(u,v))) {
                    if(Map[u][v] == 'M') {
                        p.i = u;
                        p.j = v;
                        return true; 
                        }
                    if(Map[u][v] != 'P') {Q.push(Pos(i,v));}
                }
            }
        }
        return false;
    }
    */

   bool notSeen(Pos p) {
       itObj it = objectives.begin();
       while(it != objectives.end()) {if(it->second.p1 == p or it->second.p2 == p) return false;}
       return true;
   }
   
   pair<int,int> findMoney(Pos& p, Pos& p2, vector<int>& path1, vector<int>& path2) {
       pair<int,int> d{0,0};
        queue<pair<Pos,vector<int>>> Q;
        //if(Map[p.i][p.j] == 'P') return false;
        //Map[p.i][p.j] = 'P';
        vector<int> test;
        Q.push(make_pair(p, test));
        vector<vector<int>>dist(board_rows(), vector<int>(board_cols(),-1));
        dist[p.i][p.j] = 0;
        while(!Q.empty()) {
            Pos q = Q.front().first;
            vector<int> t = Q.front().second;
            Q.pop();
            if(Map[q.i][q.j] == 'M' and dist[q.i][q.j] == -1/*and notSeen(Pos(q.i,q.j))*/) {
                if(!d.first) {
                    p.i = q.i; p.j = q.j; d.first= dist[q.i][q.j];
                    path1 = t;
                    //if(d.first == static_cast<int>(t.size()) - 1) path1 = t;
                } else if(!d.second and q.i != p.i and q.j != p.j) {
                    p2.i = q.i; p2.j = q.j; d.second = dist[q.i][q.j];
                    path2 = t;
                    //if(d.second == t.size() - 1) path2 = t;
                } else {
                    if(dist[q.i][q.j] < d.second) {
                        p2.i = q.i; p2.j = q.j; d.second = dist[q.i][q.j];
                        path2 = t;
                        // if(d.second == t.size() - 1) path2 = t;
                    }
                }
            }
            else {
                for(int k = 0; k < 4; ++k) {
                    int u = q.i + x[k];
                    int v = q.j + y[k]; 
                    if(pos_ok(Pos(u,v)) and Map[u][v] != 'P' and Map[u][v] != 'B' and Map[u][v] != 'Y' and Map[u][v] != 'W' and dist[u][v] == -1) {
                        t.push_back(k);
                        if(Map[u][v] == 'M'/* and notSeen(Pos(u,v))*/) {
                            if(!d.first) {
                                p.i = u; p.j = v; d.first= 1+dist[q.i][q.j];
                                path1 = t;
                                // if(d.first == t.size() - 1) path1 = t;
                            } else if(!d.second and q.i != p.i and q.j != p.j) {
                                p2.i = u; p2.j = v; d.second =1+ dist[q.i][q.j];
                                path2 = t;
                                // if(d.second == t.size() - 1) path2 = t;
                            } else {
                                if(dist[q.i][q.j] < d.second) { 
                                    p2.i = u; p2.j = v; d.second = 1+dist[q.i][q.j];
                                    path2 = t;
                                    // if(d.second == t.size() - 1) path2 = t;
                                }
                            }
                        }
                        Q.push(make_pair(Pos(u,v),t));
                        dist[u][v] = 1 + dist[q.i][q.j];
                        t.clear();

                        
                    }
                }
            }
        }
        return d;
   }
 /*
   int findMoney(Pos& p, vector<Dir>& path) {
        queue<Pos> Q;
        //if(Map[p.i][p.j] == 'P') return false;
        //Map[p.i][p.j] = 'P';
        path.clear();
        Q.push(p);
        vector<vector<int>>dist(board_rows(), vector<int>(board_cols(),-1));
        dist[p.i][p.j] = 0;
        while(!Q.empty()) {
            Pos q = Q.front();
            Q.pop();
            if(Map[q.i][q.j] == 'M') {p.i = q.i; p.j = q.j; return dist[q.i][q.j]; }
            else {
                for(int k = 0; k < 4; ++k) {
                    int u = q.i + x[k];
                    int v = q.j + y[k]; 
                    if(pos_ok(Pos(u,v)) and Map[u][v] != 'P' and Map[u][v] != 'B' and Map[u][v] != 'Y' and Map[u][v] != 'W' and dist[u][v] == -1) {
                        if(Map[u][v] == 'M') {
                            switch(k){
                                case 0: path.push_back(Down);
                                case 1: path.push_back(Right);
                                case 2: path.push_back(Up);
                                case 3: path.push_back(Left);
                            }
                            p.i = u; p.j = v;
                            return 1+dist[q.i][q.j];
                        }
                        Q.push(Pos(u,v));
                        dist[u][v] = 1 + dist[q.i][q.j];
                        
                    }
                }
            }
        }
        return -1;
   }
   
  
*/




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
        if(!round()) initializeMap();
        else actualizeMap();
        if((is_day() or !is_day()) and round()<10) {
            FarmingSimulator();
            for(int i = 0; i < board_rows(); ++i) {
            cerr << endl;
            for(int j = 0; j < board_cols(); ++j) {
                cerr << Map[i][j];
            }

        }
        cerr << endl;
            
        }
        

        



        


	
	
	//per cert jugador, mirar si destinacio valida.
	
  
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
