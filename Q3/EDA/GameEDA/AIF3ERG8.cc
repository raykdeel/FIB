#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AIF3ERG8


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

    struct Node {
      Pos x;
      vector<Node> parent;
  };

    typedef vector<bool> BooleanRow;
    typedef vector<BooleanRow> BooleanMatrix;

    const vector<Dir> dirs = {Down,Right,Up,Left};

    const int x[8] = {1,0,-1,0,1,-1,1,-1};
    const int y[8] = {0,1,0,-1,1,-1,-1,1};
    
    map<int, bool> movements;
    map<int, bool>::iterator it;
    int movs = 0;


    vector<int> w;
    vector<int> b;

    bool alive(Citizen c) {
        if(c.life == 0) return false;
        else return true;
    }
    void translate(vector<Node> nodes,vector<Pos>& path) {
        if(nodes.size() != 0) {
            translate(nodes[0].parent,path);
            path.push_back(nodes[0].x);
        }
    }
    void initialize() {
        w = warriors(me());
        b = builders(me());
        if(round()==0) {
            for(int i : w) movements.insert(make_pair(i,false));
            for(int j : b) movements.insert(make_pair(j,false));
        } else {
            for(int i : w) {if(alive(citizen(i))){it=movements.find(i); it->second = false;}}
            for(int j : b) {if(alive(citizen(j))){it=movements.find(j); it->second = false;}}
        }
    }
    bool nothingAround(Pos p) {
        for(int k = 0; k < 8; k++) {
            int ii = p.i + x[k];
            int jj = p.j + y[k];
            if(pos_ok(Pos(ii,jj)) and cell(ii,jj).type != Building
            and cell(ii,jj).weapon >= Gun) return false;
        }
        return true;
    }
    void movementDone(int id) {
        it = movements.find(id);
        it->second = true;
    }
    bool movedAlready(int id) {
        it = movements.find(id);
        return it->second;
    }


    void Healthcare() {
        vector<Pos> directionFood;
    	Citizen c;
        Pos p;
    	for (int id : w) {
            c = citizen(id);
            p = c.pos;
            if(alive(c) and c.life <= warrior_ini_life()/2 and nothingAround(p) and !movedAlready(id)) {
                vector<Node> parents;
                bool found = false;
                directionFood.clear();
                findFood(p,parents,found);
                if(found) {
                    translate(parents,directionFood);
                    directionFood.erase(directionFood.begin());
                    if(directionFood.size() < 6) {
                    Pos q = directionFood[0];
                    ++movs;
                    cerr << endl;cerr << "Warrior " << c.id << " " << c.pos << " going to " << q <<", nearest food " << directionFood[directionFood.size()-1]  << " at " << directionFood.size();
                    if(p.i + 1 == q.i) {cerr << ", so moving down" << endl;movementDone(id);move(id,Down);}
                    else if(p.i - 1 == q.i) {cerr << ", so moving up" << endl;movementDone(id);move(id,Up);}
                    else if(p.j + 1 == q.j) {cerr << ", so moving right" << endl;movementDone(id);move(id,Right);}
                    else if(p.j - 1 == q.j) {cerr << ", so moving left" << endl;movementDone(id);move(id,Left);}
                    }
                }
            }
        }
	    for (int id : b) {
           c = citizen(id);
            p = c.pos;
            if(alive(c) and c.life <= builder_ini_life()/2 and !movedAlready(id)) {
                vector<Node> parents;
                bool found = false;
                directionFood.clear();
                findFood(p,parents,found);
                if(found) {
                    translate(parents,directionFood);
                    directionFood.erase(directionFood.begin());
                    if(directionFood.size() < 6) {
                    Pos q = directionFood[0];
                    ++movs;
                    cerr << endl;cerr << "Builder " << c.id << " " << c.pos << " going to " << q <<", nearest food " << directionFood[directionFood.size()-1]  << " at " << directionFood.size();
                    if(p.i + 1 == q.i) {cerr << ", so moving down" << endl;movementDone(id);move(id,Down);}
                    else if(p.i - 1 == q.i) {cerr << ", so moving up" << endl;movementDone(id);move(id,Up);}
                    else if(p.j + 1 == q.j) {cerr << ", so moving right" << endl;movementDone(id);move(id,Right);}
                    else if(p.j - 1 == q.j) {cerr << ", so moving left" << endl;movementDone(id);move(id,Left);}
                    }
                }
            }      
        }
    }
    void ArmYourself() {
        vector<Pos> directionWeapon;
    	Citizen c;
        Pos p;
    	for (int id : w) {
            c = citizen(id);
            p = c.pos;
            if(alive(c) and c.weapon <= Bazooka and !movedAlready(id)) {
                vector<Node> parents;
                bool found = false;
                directionWeapon.clear();
                findWeapon(p,parents,found);
                if(found) {
                    translate(parents,directionWeapon);
                    directionWeapon.erase(directionWeapon.begin());
                    if((cell(p).weapon > c.weapon and directionWeapon.size() < 10) or (directionWeapon.size()<5)) {
                    Pos q = directionWeapon[0];
                    p = c.pos;
                    ++movs;
                    cerr << endl;cerr << "Warrior " << c.id << " " << c.pos << " going to " << q <<", nearest weapon " << directionWeapon[directionWeapon.size()-1]  << " at " << directionWeapon.size() ;
                    if(p.i + 1 == q.i) {cerr << ", so moving down" << endl;movementDone(id);move(id,Down);}
                    else if(p.i - 1 == q.i) {cerr << ", so moving up" << endl;movementDone(id);move(id,Up);}
                    else if(p.j + 1 == q.j) {cerr << ", so moving right" << endl;movementDone(id);move(id,Right);}
                    else if(p.j - 1 == q.j) {cerr << ", so moving left" << endl;movementDone(id);move(id,Left);}
                    }
                }
            }
        }
    }
    void FarmingSimulator() {
        vector<Pos> directionMoney;
        vector<Pos> directionEnemy;
    	Citizen c;
        Pos p;
    	for (int id : w) {
            c = citizen(id);
            p = c.pos;
            if(alive(c) and !movedAlready(id)) {
                vector<Node> parents;
                bool found = false;
                if(is_round_night(round()) or (round() < num_rounds()  and is_round_night(round()+1))) {
                    directionEnemy.clear();
                    findEnemy(p,parents,found);
                    if(found) {
                        translate(parents,directionEnemy);
                        directionEnemy.erase(directionEnemy.begin());
                        Pos q = directionEnemy[0];
                        ++movs;
                        cerr << endl;cerr << "Warrior " << c.id << " " << c.pos << " going to " << q <<", nearest enemy " << directionEnemy[directionEnemy.size()-1]  << " at " << directionEnemy.size();
                        if(p.i + 1 == q.i) {cerr << ", so moving down" << endl;movementDone(id);move(id,Down);}
                        else if(p.i - 1 == q.i) {cerr << ", so moving up" << endl;movementDone(id);move(id,Up);}
                        else if(p.j + 1 == q.j) {cerr << ", so moving right" << endl;movementDone(id);move(id,Right);}
                        else if(p.j - 1 == q.j) {cerr << ", so moving left" << endl;movementDone(id);move(id,Left);}
                    }

                } else {
                    directionMoney.clear();
                    findMoney(p,parents,found);
                    if(found) {
                        translate(parents,directionMoney);
                        directionMoney.erase(directionMoney.begin());
                        Pos q = directionMoney[0];
                        ++movs;
                        cerr << endl;cerr << "Warrior " << c.id << " " << c.pos << " going to " << q <<", nearest money " << directionMoney[directionMoney.size()-1]  << " at " << directionMoney.size();
                        if(p.i + 1 == q.i) {cerr << ", so moving down" << endl;movementDone(id);move(id,Down);}
                        else if(p.i - 1 == q.i) {cerr << ", so moving up" << endl;movementDone(id);move(id,Up);}
                        else if(p.j + 1 == q.j) {cerr << ", so moving right" << endl;movementDone(id);move(id,Right);}
                        else if(p.j - 1 == q.j) {cerr << ", so moving left" << endl;movementDone(id);move(id,Left);}
                    }
                }
            }
        }
	    for (int id : b) {
            c = citizen(id);
            p = c.pos;
            if(alive(c) and !movedAlready(id)) {
                vector<Node> parents;
                bool found = false;
                directionMoney.clear();
                findMoney(p,parents,found);
                if(found) {
                    translate(parents,directionMoney);
                    directionMoney.erase(directionMoney.begin());
                    Pos q = directionMoney[0];
                    ++movs;
                    cerr << endl;cerr << "Builder " << c.id << " " << c.pos << " going to " << q <<", nearest money " << directionMoney[directionMoney.size()-1]  << " at " << directionMoney.size();
                    if(p.i + 1 == q.i) {cerr << ", so moving down" << endl;movementDone(id);move(id,Down);}
                    else if(p.i - 1 == q.i) {cerr << ", so moving up" << endl;movementDone(id);move(id,Up);}
                    else if(p.j + 1 == q.j) {cerr << ", so moving right" << endl;movementDone(id);move(id,Right);}
                    else if(p.j - 1 == q.j) {cerr << ", so moving left" << endl;movementDone(id);move(id,Left);}
                }             
                
            }
	    }
    }
       

    void findFood(Pos p, vector<Node>& parents, bool& found) {
        queue<Node> q;
        BooleanMatrix seen(board_rows(), BooleanRow(board_cols(), false));
        Node a = {p};
        q.push(a);
        seen[p.i][p.j] = true;
        while(!q.empty() and !found) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).bonus == Food) {
                p = aux.x;
                parents = {aux};
                found = true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).type != Building
                    and cell(Pos(ii,jj)).id == -1 and seen[ii][jj] == false) {
                        Node next = {Pos(ii,jj),{aux}};
                        seen[ii][jj] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    void findWeapon(Pos& p, vector<Node>& parents, bool& found) {
        queue<Node> q;
        BooleanMatrix seen(board_rows(), BooleanRow(board_cols(), false));
        Node a = {p};
        q.push(a);
        seen[p.i][p.j] = true;
        Citizen cit = citizen(cell(p).id);
        while(!q.empty() and !found) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if((cell(t).weapon == Gun or cell(t).weapon == Bazooka)
            and cit.weapon != Bazooka) {
                p = aux.x;
                parents = {aux};
                found = true;
            } else if (cell(t).weapon == Bazooka and cit.weapon == Bazooka){
                p = aux.x;
                parents = {aux};
                found = true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(ii,jj).type != Building 
                    and not seen[ii][jj] and ((cell(ii,jj).id == -1 
                    and is_round_day(round())) or (cell(ii,jj).id != -1 
                    and is_round_night(round()))) and 
                    cell(ii,jj).resistance == -1) {
                        Node next = {Pos(ii,jj),{aux}};
                        seen[ii][jj] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    void findMoney(Pos p, vector<Node>& parents, bool& found) {
        queue<Node> q;
        BooleanMatrix seen(board_rows(), BooleanRow(board_cols(), false));
        Node a = {p};
        q.push(a);
        seen[p.i][p.j] = true;
        while(!q.empty() and !found) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).bonus == Money) {
                p = aux.x;
                parents = {aux};
                found = true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).type != Building
                    and cell(Pos(ii,jj)).id == -1 and seen[ii][jj] == false) {
                        Node next = {Pos(ii,jj),{aux}};
                        seen[ii][jj] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    void findEnemy(Pos p, vector<Node>& parents, bool& found) {
        queue<Node> q;
        BooleanMatrix seen(board_rows(), BooleanRow(board_cols(), false));
        Node a = {p};
        q.push(a);
        seen[p.i][p.j] = true;
        while(!q.empty() and !found) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).id != -1 
            and citizen(cell(t).id).player != me() 
            and (citizen(cell(t).id).weapon < citizen(cell(p).id).weapon
            or citizen(cell(t).id).type == Builder)) {
                p = aux.x;
                parents = {aux};
                found = true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).type != Building 
                    and seen[ii][jj] == false and (cell(ii,jj).id == -1 
                    or (cell(ii,jj).id != -1 and citizen(cell(ii,jj).id).player != me() and
                     (citizen(cell(ii,jj).id).weapon < citizen(cell(p).id).weapon or
                      citizen(cell(ii,jj).id).type == Builder)))) {
                        Node next = {Pos(ii,jj),{aux}};
                        seen[ii][jj] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    
//MAP OR NO MAP, but save on a vector<Pos>, the pos of money, food, eeapons, maybe even enemies.


    virtual void play () {
        initialize();
        Healthcare();
        ArmYourself();
        FarmingSimulator();
        cerr << movs;
        //if(is_round_night(round()+1) nighttime)


        
        
	
  
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
