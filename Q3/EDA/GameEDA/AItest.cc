#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AIF3ERG14


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
    int movs = 0;
    
    map<int, pair<vector<Pos>,bool>> movements;
    typedef map<int, pair<vector<Pos>,bool>>::iterator it;

    void translate(vector<Node> nodes,vector<Pos>& path) {
        if(nodes.size() != 0) {
            translate(nodes[0].parent,path);
            path.push_back(nodes[0].x);
        }
    }

    bool alive(int id) {
        for(int i : warriors(me())) if(i == id) return true;
        for(int j : builders(me())) if(j == id) return true;
        return false;
    }

    bool resurected(int id) {
        it itRes= movements.begin();
        while(itRes != movements.end()) {
            if(itRes->first == id) return false;
            ++itRes;
        }
        return true;
    }

    bool shared_objective(Pos p, int d) {
        bool shared = false;
        it itSha= movements.begin();
        while(itSha != movements.end()) {
            if(itSha->second.first.size()==0) shared = false;
            else {
                Pos q = itSha->second.first[itSha->second.first.size()-1];
                shared = q == p;
                if(shared and int(itSha->second.first.size()) < d) return true;
            }
            ++itSha;
        }
        return shared;
    }
    

    void initialize() {
        it itini = movements.begin();
        movements.erase(itini,movements.end());
        vector<Pos> v;
        for(int i : warriors(me())) movements.insert(make_pair(i,make_pair(v,false)));
        for(int j : builders(me())) movements.insert(make_pair(j,make_pair(v,false)));
    }
    bool adjacent_weapon(Pos p) {
        for(int k = 0; k < 8; k++) {
            int ii = p.i + x[k];
            int jj = p.j + y[k];
            if(pos_ok(Pos(ii,jj)) and cell(ii,jj).type != Building
            and cell(ii,jj).weapon >= Gun) return true;
        }
        return false;
    }
    bool decision_confirmed(int id) {
        it itConf= movements.find(id);
        return itConf->second.second;
    }
    
    void confirm_movement(int id, Pos p) {
        it itConf= movements.find(id);
        Pos q = itConf->second.first[0];
        itConf->second.second = true;
        cerr << endl;
        cerr << id << p << " going to " << itConf->second.first[itConf->second.first.size()-1];
        ++movs;
        if(p.i + 1 == q.i) {cerr<<", so down" << endl;move(id,Down);}
        else if(p.i - 1 == q.i) {cerr<<", so up" << endl;move(id,Up);}
        else if(p.j + 1 == q.j) {cerr<<", so right" << endl;move(id,Right);}
        else if(p.j - 1 == q.j) {cerr<<", so left" << endl;move(id,Left);}
        cerr << endl;
    }

    bool Healthcare(int id) {
        vector<Pos> directionFood;
    	Citizen c = citizen(id);
        Pos p = c.pos;
        if((c.type ==  Builder and c.life <= builder_ini_life()/2) or (c.type ==  Warrior and c.life <= warrior_ini_life()/2)) {
            if(not adjacent_weapon(p)) {
                vector<Node> parents;
                directionFood.clear();
                if(findFood(p,parents)){
                    translate(parents,directionFood);
                    if(directionFood.size()-1 < 6) {
                        directionFood.erase(directionFood.begin());
                        it itHea= movements.find(id);
                        itHea->second.first = directionFood;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool ArmYourself(int id) {
        vector<Pos> directionWeapon;
    	Citizen c = citizen(id);
        Pos p = c.pos;
        if(c.weapon <= Bazooka) {
            vector<Node> parents;
            directionWeapon.clear();        
            if(findWeapon(p,parents)) {
                translate(parents,directionWeapon);
                if((cell(directionWeapon[directionWeapon.size()-1]).weapon > c.weapon and directionWeapon.size()-1 < 10) or (directionWeapon.size()-1<5)) {
                    directionWeapon.erase(directionWeapon.begin());
                    it itArm= movements.find(id);
                    itArm->second.first = directionWeapon;
                    return true;
                }
            }
        }
        return false;
    }
    bool FarmingSimulator(int id) {
        vector<Pos> directionMoney;
        vector<Pos> directionWarrior;
        vector<Pos> directionBuilder;
    	Citizen c = citizen(id);
        Pos p = c.pos;
        vector<Node> parents_warrior;
        vector<Node> parents_builder;
    	if(c.type ==  Warrior and (is_round_night(round()) or (round() < num_rounds()  and is_round_night(round()+5)))) {
            bool warrior_found = findWarrior(p,parents_warrior);
            if(warrior_found) { 
                translate(parents_warrior,directionWarrior);
            }
            bool builder_found = findBuilder(p,parents_warrior);
            if(builder_found) {
                translate(parents_warrior,directionBuilder);
            }
            if(directionWarrior.size() <= directionBuilder.size()+5 and directionWarrior.size()!=0) {
                directionWarrior.erase(directionWarrior.begin());
                it itFarm = movements.find(id);
                itFarm->second.first = directionWarrior;
                return true;
            } else if (directionBuilder.size() != 0){
                directionBuilder.erase(directionBuilder.begin());
                it itFarm = movements.find(id);
                itFarm->second.first = directionBuilder;
                return true;
            }
        } else {
            directionMoney.clear();
            if(findMoney(p,parents_builder)) {
                translate(parents_builder,directionMoney);
                directionMoney.erase(directionMoney.begin());
                it itFarm = movements.find(id);
                itFarm->second.first = directionMoney;
                return true;
            }
        }
        return false;
    }

    bool findFood(Pos p, vector<Node>& parents) {
        queue<Node> q;
        vector<vector<int>>dist(board_rows(), vector<int>(board_cols(),-1));
        dist[p.i][p.j] = 0;
        Node a = {p};
        q.push(a);
        while(!q.empty()) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).bonus == Food  and not shared_objective(t,dist[t.i][t.j])) {
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).type != Building
                    and cell(Pos(ii,jj)).id == -1 and dist[ii][jj] == -1) {
                        Node next = {Pos(ii,jj),{aux}};
                        dist[ii][jj] = 1 + dist[t.i][t.j];
                        q.push(next);
                    }
                }
            }
        }
        return false;
    }
    bool findWeapon(Pos p, vector<Node>& parents) {
        queue<Node> q;
        vector<vector<int>>dist(board_rows(), vector<int>(board_cols(),-1));
        dist[p.i][p.j] = 0;
        Node a = {p};
        q.push(a);
        Citizen cit = citizen(cell(p).id);
        while(!q.empty()) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if((cell(t).weapon == Gun or cell(t).weapon == Bazooka)
            and cit.weapon != Bazooka  and not shared_objective(t,dist[t.i][t.j])) {
                p = aux.x;
                parents = {aux};
                return true;
            } else if (cell(t).weapon == Bazooka and cit.weapon == Bazooka  and not shared_objective(t,dist[t.i][t.j])){
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k]; //canvis inhere
                    if(pos_ok(Pos(ii,jj)) and cell(ii,jj).type != Building 
                    and dist[ii][jj] == -1 and ((cell(ii,jj).id == -1 
                    and is_round_day(round())) or (is_round_night(round()) 
                    and cell(ii,jj).id != -1 and citizen(cell(ii,jj).id).weapon < cit.weapon)
                    or cell(ii,jj).id != -1) and 
                    cell(ii,jj).resistance == -1) {
                        Node next = {Pos(ii,jj),{aux}};
                        dist[ii][jj] = 1 + dist[t.i][t.j];
                        q.push(next);
                    }
                }
            }
        }
        return false;
    }
    bool findMoney(Pos p, vector<Node>& parents) {
        queue<Node> q;
        vector<vector<int>>dist(board_rows(), vector<int>(board_cols(),-1));
        dist[p.i][p.j] = 0;
        Node a = {p};
        q.push(a);
        while(!q.empty()) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).bonus == Money  and not shared_objective(t,dist[t.i][t.j])) {
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).type != Building
                    and cell(Pos(ii,jj)).id == -1 and dist[ii][jj] == -1) {
                        Node next = {Pos(ii,jj),{aux}};
                        dist[ii][jj] = 1 + dist[t.i][t.j];
                        q.push(next);
                    }
                }
            }
        }
        return false;
    }

    bool findWarrior(Pos p, vector<Node>& parents) {
        queue<Node> q;
        vector<vector<int>>dist(board_rows(), vector<int>(board_cols(),-1));
        dist[p.i][p.j] = 0;
        Node a = {p};
        q.push(a);
        while(!q.empty()) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).id != -1 
            and citizen(cell(t).id).player != me() 
            and citizen(cell(t).id).weapon < citizen(cell(p).id).weapon
            and citizen(cell(t).id).type == Warrior  and not shared_objective(t,dist[t.i][t.j])) {
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).type != Building 
                    and dist[ii][jj] == -1 and (cell(ii,jj).id == -1 
                    or (cell(ii,jj).id != -1 and citizen(cell(ii,jj).id).player != me() and
                     (citizen(cell(ii,jj).id).weapon < citizen(cell(p).id).weapon or
                      citizen(cell(ii,jj).id).type == Builder)))) {
                        Node next = {Pos(ii,jj),{aux}};
                        dist[ii][jj] = 1 + dist[t.i][t.j];
                        q.push(next);
                    }
                }
            }
        }
        return false;
    }
    bool findBuilder(Pos p, vector<Node>& parents) {
        queue<Node> q;
        vector<vector<int>>dist(board_rows(), vector<int>(board_cols(),-1));
        dist[p.i][p.j] = 0;
        Node a = {p};
        q.push(a);
        while(!q.empty()) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).id != -1 
            and citizen(cell(t).id).player != me() 
            and citizen(cell(t).id).type == Builder  and not shared_objective(t,dist[t.i][t.j])) {
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).type != Building 
                    and dist[ii][jj] == -1 and (cell(ii,jj).id == -1 
                    or (cell(ii,jj).id != -1 and citizen(cell(ii,jj).id).player != me() and
                     (citizen(cell(ii,jj).id).weapon < citizen(cell(p).id).weapon or
                      citizen(cell(ii,jj).id).type == Builder)))) {
                        Node next = {Pos(ii,jj),{aux}};
                        dist[ii][jj] = 1 + dist[t.i][t.j];
                        q.push(next);
                    }
                }
            }
        }
        return false;
    }
    
    void decide_objective() {
        it itDec = movements.begin();
        while(itDec != movements.end()) {
            
            Citizen c = citizen(itDec->first);
            cerr << itDec->first;
            int id =itDec->first;
            cerr << "hola";
            Pos p = c.pos;
            if(Healthcare(id)) confirm_movement(id,p);
            else if(c.type == Warrior and ArmYourself(id)) confirm_movement(id,p);
            else if(FarmingSimulator(id)) confirm_movement(id,p);
            ++itDec;
        }

    }
//mirar si la destinació calculada segueix sent vàlida, 
//si no ho és, recalcular l'objectiu

    virtual void play () {
        initialize();
        decide_objective();
        cerr << movs;
    }  
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);