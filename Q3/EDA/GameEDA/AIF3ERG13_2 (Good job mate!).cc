#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AIF3ERG14_1


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
    
    map<int, pair<vector<Pos>,bool>> movements;
    typedef map<int, pair<vector<Pos>,bool>>::iterator it;  

    void initialize() {
        it itini = movements.begin();
        movements.erase(itini,movements.end());
        vector<Pos> v;
        for(int i : warriors(me())) movements.insert(make_pair(i,make_pair(v,false)));
        for(int j : builders(me())) movements.insert(make_pair(j,make_pair(v,false)));
    }
    
    void translate(vector<Node> nodes,vector<Pos>& path) {
        if(nodes.size() != 0) {
            translate(nodes[0].parent,path);
            path.push_back(nodes[0].x);
        }
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
    bool adjacent_weapon(Pos p) {
        for(int k = 0; k < 8; k++) {
            int ii = p.i + x[k];
            int jj = p.j + y[k];
            if(pos_ok(Pos(ii,jj)) and cell(ii,jj).type != Building
            and cell(ii,jj).weapon >= Gun) return true;
        }
        return false;
    }
    bool safe_position(int id, Pos p) {
        bool safe = true;
        if(is_round_night(round()) or (round() < num_rounds() and is_round_night(round()+5))) {
            for(int k = 0; k < 4; k++) {
                int ii = p.i + x[k];
                int jj = p.j + y[k];
                if(pos_ok(Pos(ii,jj)) and cell(ii,jj).id != -1 and citizen(cell(ii,jj).id).player != me()) {
                    if(citizen(id).type == Builder and citizen(cell(ii,jj).id).type != Builder) safe = false;
                    else {
                        if(stronger_weapon(citizen(cell(ii,jj).id), citizen(id))) safe = false;
                    }
                }
            }
        } else safe = true;
        return safe;
    }
    bool stronger_weapon(Citizen c1, Citizen c2) {
        if((c1.weapon == Bazooka and c2.weapon == Bazooka) or (c1.weapon == Gun and c2.weapon == Gun) or (c1.weapon == Hammer and c2.weapon == Hammer)) return false;
        else if (c1.weapon == Bazooka and (c2.weapon == Gun or c2.weapon == Hammer)) return true;
        else if (c1.weapon == Gun and c2.weapon == Hammer) return true;
        else return false;
    }

    bool decision_confirmed(int id) {
        it itConf= movements.find(id);
        return itConf->second.second;
    }
    void confirm_movement(int id, Pos p) {
        it itConf= movements.find(id);
        Pos q = itConf->second.first[0];
        itConf->second.second = true;
        if(p.i + 1 == q.i) move(id,Down);
        else if(p.i - 1 == q.i) move(id,Up);
        else if(p.j + 1 == q.j) move(id,Right);
        else if(p.j - 1 == q.j) move(id,Left);
    }

    bool Healthcare(int id) {
        vector<Pos> directionFood;
    	Citizen c = citizen(id);
        Pos p = c.pos;
        if((c.type ==  Builder and c.life <= builder_ini_life()/2) or (c.type ==  Warrior and c.life <= warrior_ini_life()/2)) {
            if(not adjacent_weapon(p)) {
                vector<Node> parents;
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
            if(findWeapon(p,parents)) {
                translate(parents,directionWeapon);
                if((is_round_day(round()) and cell(directionWeapon[directionWeapon.size()-1]).weapon > c.weapon and directionWeapon.size()-1 < 10) or (is_round_night(round()) and directionWeapon.size()-1<5) or directionWeapon.size()-1<5) {
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
    bool make_bunker(int id, Pos p) {
                if(cell(p).b_owner == me() and not safe_position(id,p) and cell(p).resistance < 40) {
            for(int k = 0; k < 4; k++) {
                int ii = p.i + x[k];
                int jj = p.j + y[k];
                Pos q = Pos(ii,jj);
                if(pos_ok(q) and safe_position(id,q)) {
                    if(p.i + 1 == q.i) move(id,Down);
                    else if(p.i - 1 == q.i) move(id,Up);
                    else if(p.j + 1 == q.j) move(id,Right);
                    else if(p.j - 1 == q.j) move(id,Left);
                    return true;
                }
            }
        }
        for(int k = 0; k < 4; k++) {
            int ii = p.i + x[k];
            int jj = p.j + y[k];
            if(pos_ok(Pos(ii,jj)) and cell(ii,jj).id == -1 and cell(ii,jj).type == Street and safe_position(id,Pos(ii,jj)) and cell(ii,jj).b_owner == -1 and is_round_day(round())) {
                Pos q = Pos(ii,jj);
                if(p.i + 1 == q.i) build(id,Down);
                else if(p.i - 1 == q.i) build(id,Up);
                else if(p.j + 1 == q.j) build(id,Right);
                else if(p.j - 1 == q.j) build(id,Left);
                return true;
            } else if (pos_ok(Pos(ii,jj)) and cell(ii,jj).id == -1 and cell(ii,jj).type == Street and cell(ii,jj).b_owner == me() /*and cell(ii,jj).resistance > 40 */and is_round_night(round())) {
                Pos q = Pos(ii,jj);
                if(p.i + 1 == q.i) move(id,Down);
                else if(p.i - 1 == q.i) move(id,Up);
                else if(p.j + 1 == q.j) move(id,Right);
                else if(p.j - 1 == q.j) move(id,Left);
                return true;
            } else if(pos_ok(Pos(ii,jj)) and cell(ii,jj).id == -1 and cell(ii,jj).type == Street and is_round_night(round()) and cell(p).b_owner != me()) {
                Pos q = Pos(ii,jj);
                if(p.i + 1 == q.i) move(id,Down);
                else if(p.i - 1 == q.i) move(id,Up);
                else if(p.j + 1 == q.j) move(id,Right);
                else if(p.j - 1 == q.j) move(id,Left);
                return true;
            } else if (pos_ok(Pos(ii,jj)) and cell(ii,jj).id == -1 and cell(ii,jj).type == Street and cell(ii,jj).b_owner == me() and is_round_day(round())) {
                Pos q = Pos(ii,jj);
                if(p.i + 1 == q.i) build(id,Down);
                else if(p.i - 1 == q.i) build(id,Up);
                else if(p.j + 1 == q.j) build(id,Right);
                else if(p.j - 1 == q.j) build(id,Left);
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
        Citizen c = citizen(cell(p).id);
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
                    and safe_position(c.id,Pos(ii,jj)) and dist[ii][jj] == -1 and ((is_round_day(round()) and cell(ii,jj).resistance == -1)or is_round_night(round()))) {
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
            } else if (cell(t).weapon == Bazooka and cit.weapon == Bazooka and not shared_objective(t,dist[t.i][t.j])){
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k]; //canvis inhere
                    if(pos_ok(Pos(ii,jj)) and cell(ii,jj).type != Building and dist[ii][jj] == -1 and ((cell(ii,jj).id == -1 
                    and is_round_day(round()) and cell(ii,jj).resistance == -1) or (is_round_night(round()) 
                    and cell(ii,jj).id != -1 and citizen(cell(ii,jj).id).weapon < cit.weapon)
                    or cell(ii,jj).id != -1 or (is_round_night(round()) and cell(ii,jj).id == -1))) {
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
        Citizen c = citizen(cell(p).id);
        Node a = {p};
        q.push(a);
        while(!q.empty()) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).bonus == Money and not shared_objective(t,dist[t.i][t.j])) {
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).type != Building
                    and safe_position(c.id,Pos(ii,jj)) and dist[ii][jj] == -1 and ((is_round_day(round()) and cell(ii,jj).resistance == -1) or is_round_night(round()))) {
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
        //Citizen c = citizen(cell(p).id);
        Node a = {p};
        q.push(a);
        while(!q.empty()) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).id != -1 
            and citizen(cell(t).id).player != me() 
            and citizen(cell(t).id).weapon < citizen(cell(p).id).weapon
            and citizen(cell(t).id).type == Warrior and not shared_objective(t,dist[t.i][t.j])) {
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).resistance == -1 and cell(Pos(ii,jj)).type != Building 
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
        //Citizen c = citizen(cell(p).id);
        Node a = {p};
        q.push(a);
        while(!q.empty()) {
            Node aux = q.front();
            q.pop();
            Pos t = aux.x;
            if(cell(t).id != -1 and citizen(cell(t).id).player != me() and cell(t).resistance <= 80
            and citizen(cell(t).id).type == Builder and not shared_objective(t,dist[t.i][t.j])) {
                p = aux.x;
                parents = {aux};
                return true;
            } else {
                for(int k = 0; k < 4; k++) {
                    int ii = t.i + x[k];
                    int jj = t.j + y[k];
                    if(pos_ok(Pos(ii,jj)) and cell(Pos(ii,jj)).resistance == -1 and cell(Pos(ii,jj)).type != Building 
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
            int id =itDec->first;
            Pos p = c.pos;
            bool bunker = false;
            if(is_round_day(round()) and round() < num_rounds() and is_round_night(round()+3) and not safe_position(id,p) and int(barricades(me()).size()) < max_num_barricades()) {
                make_bunker(id,p);
            }
            if(not decision_confirmed(id) and Healthcare(id)) confirm_movement(id,p);
            else if(c.type == Warrior and ArmYourself(id)) confirm_movement(id,p);
            else if(FarmingSimulator(id)) confirm_movement(id,p);
            else if (c.type == Builder) {
                make_bunker(id,p);
            }
            ++itDec;
        }

    }
    virtual void play () {
        initialize();
        decide_objective();
    }  
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);