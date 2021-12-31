#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AIF3ERG5   


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

    const vector<Dir> dirs = {Down,Right,Up,Left};

    typedef vector<bool> BooleanRow;
    typedef vector<BooleanRow> BooleanMatrix;

    const int x[4] = {1,0,-1,0};
    const int y[4] = {0,1,0,-1};

    vector<int> w;
    vector<int> b;

    bool alive(Citizen c) {
        if(c.life == 0) return false;
        else return true;
    }

    void initialize() {
        w = warriors(me());
    	b = builders(me());
    }
  
    void FarmingSimulator() {
        vector<int> directionWeapon;
        vector<int> directionFood;
        vector<int> directionMoney;
    	Citizen c;
        Pos p;
    	for (int id : w) {
            c = citizen(id);
            p = c.pos;
            if(alive(c)) {
                directionWeapon.clear();
                directionFood.clear();
                directionMoney.clear();

                cerr << endl;
                cerr << "Warrior " << c.id << " " << c.pos;
                cerr << endl;

                findWeapon(p,directionWeapon);
                //move(id, dirs[directionWeapon[0]]);

                cerr << "Weapon: " << p;
                for(int i : directionWeapon) cerr << directionWeapon[i];
                cerr << endl;

                p = c.pos;
                findFood(p,directionFood);

                cerr << "Food: " << p;
                for(int i : directionFood) cerr << directionFood[i];
                cerr << endl;
                p = c.pos;
                findMoney(p,directionMoney);

                cerr << "Money: " << p;
                for(int i : directionMoney) cerr << directionMoney[i];
                cerr << endl;
                

                if(c.life <= warrior_ini_life()/2 and directionFood.size() < 5 and directionFood.size() != 0) {
                    move(id, dirs[directionFood[0]]);
                } else if (c.weapon < Bazooka and directionWeapon.size() < 6 and directionWeapon.size() != 0) {
                    move(id, dirs[directionWeapon[0]]); //ja esta on ha d'estar screenshot
                } else if (directionMoney.size() < 10 and directionMoney.size() != 0) {
                    move(id, dirs[directionMoney[0]]);
                } else {
                    Dir random_dir = dirs[random(0,3)];
                    move(id, random_dir);
                }
                
            }
        }
	    for (int id : b) {
            c = citizen(id);
            p = c.pos;
            if(alive(c)) {
                directionMoney.clear();
                directionFood.clear();

                cerr << endl;
                cerr << "Builder " << c.id << " " << c.pos;
                cerr << endl;

                findFood(p,directionFood);
                
                cerr << "Food: " << p;
                for(int i : directionFood) cerr << directionFood[i];
                cerr << endl;
                p = c.pos;
                findMoney(p,directionMoney);

                cerr << "Money: " << p;
                for(int i : directionMoney) cerr << directionMoney[i];
                cerr << endl;
                
                if(c.life <= builder_ini_life()/2 and directionFood.size() < 5 and directionFood.size() != 0) {
                    move(id, dirs[directionFood[0]]);
                } else if (directionMoney.size() < 10 and directionMoney.size() != 0) {
                    move(id, dirs[directionMoney[0]]);
                } else {
                    Dir random_dir = dirs[random(0,3)];
                    move(id, random_dir);
                }
            }
	    }
    }

    void findWeapon(Pos& p,vector<int>& direction) {
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
            if(cell(q.i, q.j).weapon == Gun or cell(q.i, q.j).weapon == Bazooka) { //citizen(cell(p.i,p.j).id).weapon
                p.i = q.i; p.j = q.j;             
                found = true;
                direction = t;              
            }
            else {
                int k = 0;
                while(k < 4 and not found) { 
                    int u = q.i + x[k]; //0=DOWN, 1=UP,
                    int v = q.j + y[k]; 
                    if(pos_ok(Pos(u,v)) and cell(u,v).type != Building 
                    and not seen[u][v] and cell(u,v).id == -1) {
                        t.push_back(k);
                        if(cell(q.i, q.j).weapon == Gun or cell(q.i, q.j).weapon == Bazooka){ //
                            found = true;
                            p.i = u; p.j = v;
                            direction = t;
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

    void findFood(Pos& p,vector<int>& direction) {
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
            if(cell(q.i, q.j).bonus == Food) {
                p.i = q.i; p.j = q.j;
                found = true;
                direction = t;              
            }
            else {
                int k = 0;
                while(k < 4 and not found) { 
                    int u = q.i + x[k]; //0=DOWN, 1=UP,
                    int v = q.j + y[k]; 
                    if(pos_ok(Pos(u,v)) and cell(u,v).type != Building 
                    and not seen[u][v] and cell(u,v).id == -1) {
                        t.push_back(k);
                        if(cell(u,v).bonus == Food) {
                            found = true;
                            p.i = u; p.j = v;
                            direction = t;
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

   
    void findMoney(Pos& p,vector<int>& direction) {
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
                p.i = q.i; p.j = q.j;
                direction = t;              
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
                            p.i = u; p.j = v;
                            direction = t;
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

    virtual void play () {
        initialize();
        FarmingSimulator();
        
	
  
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
