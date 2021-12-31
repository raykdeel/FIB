#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AIF3ERG6


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
    vector<Pos> moneyPos;
    vector<Pos> FoodPos;
    vector<Pos> BuilderPos;
    vector<Pos> WarriorPos;
    vector<Pos> BazookaPos;
    vector<Pos> GunPos;

    bool alive(Citizen c) {
        if(c.life == 0) return false;
        else return true;
    }

    void initialize() {
        w = warriors(me());
        b = builders(me());
        for(int i = 0; i < board_rows(); ++i) {
            for(int j = 0; j < board_cols(); ++j) {
                Cell c = cell(Pos(i,j));
                if(c.bonus != NoBonus) {
                    if(c.bonus == Money) moneyPos.push_back(Pos(i,j));
                    else FoodPos.push_back(Pos(i,j));
                } else if (c.weapon != NoWeapon and c.weapon != Hammer) {
                    if(c.weapon == Gun) GunPos.push_back(Pos(i,j));
                    else BazookaPos.push_back(Pos(i,j));
                } else if (c.id != -1 and c.id != me()) {
                    Citizen ci = citizen(c.id);
                    if(ci.type == Builder) BuilderPos.push_back(Pos(i,j));
                    else WarriorPos.push_back(Pos(i,j));
                }
            }
        }
    }
  
    void FarmingSimulator() {
        vector<int> directionMoney;
    	Citizen c;
        Pos p;
    	for (int id : w) {
            c = citizen(id);
            p = c.pos;
            if(alive(c)) {
                directionMoney.clear();

                //cerr << endl;
                ////cerr << "Warrior " << c.id << " " << c.pos;
                cerr << endl;

                findMoney(p,directionMoney);

                //cerr << "Money: " << p;
                //for(int i : directionMoney) cerr << dirs[directionMoney[i]];
                //cerr << endl;
                
                if(directionMoney.size() != 0) {cerr<<"goingIn";move(id, dirs[directionMoney[0]]);}
            }
        }
	    for (int id : b) {
            c = citizen(id);
            p = c.pos;
            if(alive(c)) {
                directionMoney.clear();

                //cerr << endl;
                //cerr << "Builder " << c.id << " " << c.pos;
                //cerr << endl;

                findMoney(p,directionMoney);

                //cerr << "Money: " << p;
                //for(int i : directionMoney) cerr << dirs[directionMoney[i]];
                //cerr << endl;

                if(directionMoney.size() != 0) {cerr<<"goingIn";move(id, dirs[directionMoney[0]]);}
            }
	    }
    }

    void FarmingSimulatorNight() {
        vector<int> directionEnemy;
        vector<int> directionMoney;
    	Citizen c;
        Pos p;
    	for (int id : w) {
            c = citizen(id);
            p = c.pos;
            if(alive(c)) {
                directionEnemy.clear();

                cerr << endl;
                cerr << "Warrior " << c.id << " " << c.pos;
                cerr << endl;
                Attack(p,directionEnemy);

                cerr << "Enemy: " << p;
                for(int i : directionEnemy) cerr << dirs[directionEnemy[i]];
                cerr << endl;
                
                if(directionEnemy.size() != 0) {
                    move(id, dirs[directionEnemy[0]]);
                    cerr << "doneit";
                }
            }
        }
	    for (int id : b) {
            c = citizen(id);
            p = c.pos;
            if(alive(c)) {
                directionMoney.clear();

                //cerr << endl;
                //cerr << "Builder " << c.id << " " << c.pos;
                //cerr << endl;

                findMoney(p,directionMoney);

                //cerr << "Money: " << p;
                //for(int i : directionMoney) cerr << dirs[directionMoney[i]];
                //cerr << endl;

                if(directionMoney.size() != 0) {cerr<<"goingIn";move(id, dirs[directionMoney[0]]);}
            }
	    }
    }
        
    void Healthcare() {
        vector<int> directionFood;
    	Citizen c;
        Pos p;
    	for (int id : w) {
            c = citizen(id);
            p = c.pos;
            if(alive(c) and c.life <= warrior_ini_life()/2) {
                directionFood.clear();

                //cerr << endl;
                //cerr << "Warrior " << c.id << " " << c.pos;
                //cerr << endl;

                findFood(p,directionFood);

                //cerr << "Food: " << p;
                //for(int i : directionFood) cerr << dirs[directionFood[i]];
                //cerr << endl;

                if(directionFood.size() != 0 and directionFood.size() < 6) {cerr<<"goingIn";move(id, dirs[directionFood[0]]);}
            }
        }
	    for (int id : b) {
            c = citizen(id);
            p = c.pos;
            if(alive(c) and c.life <=  builder_ini_life()/2) {
                directionFood.clear();
                
                cerr << endl;
                cerr << "Builder " << c.id << " " << c.pos;
                cerr << endl;

                findFood(p,directionFood);

                cerr << "Food: " << p;
                for(int i : directionFood) cerr << dirs[directionFood[i]];
                cerr << endl;
                
                if(directionFood.size() != 0 and directionFood.size() < 6) {cerr<<"goingIn";move(id, dirs[directionFood[0]]);}
            }
        }
    }

    void ArmYourself() {
        vector<int> directionWeapon;
    	Citizen c;
        Pos p;
    	for (int id : w) {
            c = citizen(id);
            p = c.pos;
            if(alive(c) and c.weapon <= Bazooka) {
                directionWeapon.clear();

                //cerr << endl;
                //cerr << "Warrior " << c.id << " " << c.pos;
                //cerr << endl;

                findWeapon(p,directionWeapon);

                //cerr << "Weapon: " << p;
                //for(int i : directionWeapon) cerr << dirs[directionWeapon[i]];
                //cerr << endl;

                if(directionWeapon.size() != 0 and directionWeapon.size() < 10) {cerr<<"goingIn";move(id, dirs[directionWeapon[0]]);}
            }
        }

    }

    void findWeapon(Pos& p,vector<int>& direction) {
        queue<pair<Pos,vector<int>>> Q;
        vector<int> test;
        Citizen cit = citizen(cell(p).id);
        Q.push(make_pair(p, test));
        BooleanMatrix seen(board_rows(), BooleanRow(board_cols(), false));
        seen[p.i][p.j] = true;
        bool found = false;
        while(!Q.empty() and not found) {
            Pos q = Q.front().first;
            vector<int> t = Q.front().second;
            Q.pop();
            if((cell(q.i, q.j).weapon == Gun or cell(q.i, q.j).weapon == Bazooka)
            and cit.weapon != Bazooka) { //citizen(cell(p.i,p.j).id).weapon 
                p.i = q.i; p.j = q.j;             
                found = true;
                direction = t;              
            } else if(cell(q.i,q.j).weapon == Bazooka and cit.weapon == Bazooka) {
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
                    and not seen[u][v] and ((cell(u,v).id == -1 
                    and is_round_day(round())) or (cell(u,v).id != -1 
                    and is_round_night(round()))) and 
                    cell(u,v).resistance == -1) {
                        t.push_back(k);
                        if((cell(q.i, q.j).weapon == Gun or cell(q.i, q.j).weapon == Bazooka)
                        and cit.weapon != Bazooka){ // or cell(q.i, q.j).weapon == Bazooka
                            found = true;
                            p.i = u; p.j = v;
                            direction = t;
                        } else if(cell(q.i,q.j).weapon == Bazooka and cit.weapon == Bazooka) {
                            p.i = u; p.j = v;             
                            found = true;
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
                    int u = q.i + x[k]; //0=DOWN, 1=UP, 2=LEFT, 3=RIGHT
                    int v = q.j + y[k]; 
                    if(pos_ok(Pos(u,v)) and cell(u,v).type != Building 
                    and not seen[u][v] and cell(u,v).id == -1 and cell(u,v).resistance == -1) {
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
                    and not seen[u][v] and cell(u,v).id == -1 and cell(u,v).resistance == -1) {
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

   void Attack(Pos& p,vector<int>& direction) {
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
            if(cell(q.i, q.j).id != -1 and citizen(cell(q.i,q.j).id).player != me() and 
            citizen(cell(q.i,q.j).id).weapon < citizen(cell(p).id).weapon) {
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
                    and not seen[u][v]) {
                        t.push_back(k);
                        if(cell(u,v).id != -1 and citizen(cell(u,v).id).player != me() and 
            citizen(cell(q.i,q.j).id).weapon < citizen(cell(p).id).weapon) {
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

//MAP OR NO MAP, but save on a vector<Pos>, the pos of money, food, eeapons, maybe even enemies.


    virtual void play () {
        initialize();
        if(is_round_day(round())){
            Healthcare();
            ArmYourself();
            FarmingSimulator();
        } else {
            Healthcare();
            FarmingSimulatorNight(); //if(is_round_night(round()+1) nighttime)
        }
        
        
	
  
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
