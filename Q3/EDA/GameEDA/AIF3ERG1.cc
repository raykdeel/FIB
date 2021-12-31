#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME AIF3ERG1


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
  const vector<Dir> dirs = {Up,Down,Left,Right};

  /**
   * Play method, invoked once per each round.
   * 
   * 
   */
  
/*
  map<int, Moves> Objectives;
  map<int, Moves>::iterator it;

  bool collectPhase() {
	double YES = num_rounds_per_day()*3/8;
	if(round()%YES <= 1) return true;
	else if (round()%YES)
  }	struct Moves {
		//Cell c;
		Pos p;
		string object;
		Dir d;
	};
  


 

  void findObjectivesWarriors() {
	vector<int> w = warriors(me());
	for (int id : w) {
		BeenThere(id);
		Citizen c = citizen(id);
		Moves m;
		for(Dir d : dirs) {
			Pos p = c.pos;
	  		if (pos_ok(p+d) and (cell(p+d).bonus == Money or cell(p+d).weapon > c.weapon)) {
				if(cell(p+d).bonus != NoBonus) {
					m.p = p+d; m.object = "Money", m.d = d;
				}	
				else {
					m.p = p+d; m.object = "Weapon", m.d = d;
				}
			}
  		}
		Objectives.insert(make_pair(id,m));
  	}
  }

  void findObjectivesBuilders() {
	vector<int> b = builders(me());
	for (int id : b) {
		BeenThere(id);
		Citizen c = citizen(id);
		Moves m;
		for(Dir d : dirs) {
			Pos p = c.pos;
	  		if (pos_ok(p+d) and (cell(p+d).bonus == Money)) {
				m.p = p+d; m.object = "Money", m.d = d;
			}
		}
		Objectives.insert(make_pair(id,m));
	}
  }

  void BeenThere(int id) {
	  it = Objectives.find(id);
	  Citizen c = citizen(id);
	  if(it->second.p == c.pos) Objectives.erase(it);
  }
  
  */


 void KillerInstinct() {
	vector<int> w = warriors(me());
	Citizen Soldier;
	Citizen Enemy;
	Cell ce;
	for (int id : w) {
		Soldier = citizen(id);
		for(Dir d : dirs) {
			Pos p = Soldier.pos;
			ce = cell(p+d); 
			if(pos_ok(p+d) and ce.id != -1) {
				Enemy = citizen(ce.id);
				if(Enemy.type == Builder or (Enemy.weapon < Soldier.weapon)) move(id,d);
			}
		}
	}
 }

 void MedicAssistance() {
 	vector<int> w = warriors(me());
	vector<int> b = builders(me());
	Citizen c;
	for (int id : w) {
		c = citizen(id);
		if (c.life <= warrior_ini_life()/2) goForLife(id);
	}
	for (int id : b) {
		c = citizen(id);
		if (c.life <= builder_ini_life()/2) goForLife(id);
	}
 }

 void goForLife(int id) {

 }

 void Contact(int id, Dir& GoForIt, bool& Confirmed) {
	Citizen c = citizen(id);
	Pos p = c.pos;
	for(Dir d : dirs) {
		if(pos_ok(p+d) and cell(p+d).bonus == Money) {
			GoForIt = d; 
			Confirmed = true;
		}
	}
 }
 const int di[4] = { 1, 0, -1, 0 };
 const int dj[4] = { 0, 1, 0, -1 };

  struct Objective {
	 int dist;
	 Pos p;
	 vector<int> path;
	 string bonus;
 };	

 map<int, Objective> Objectives;

 struct Destination {
	 Pos p;
	 vector<int> path;
 };

 map<int, Destination> Destinations;
 map<int, Destination>::iterator it;

 struct Posi{
  int i, j; 
  Posi (int ii = -1, int jj = -1):i (ii), j (jj){ }
};

const int xf[8] = {-1,-1,-1,0,0,1,1,1};
const int yf[8] = {-1,0,1,-1,1,-1,0,1};
const int x[4] = {0,0,1,-1};
const int y[4] = {1,-1,0,0};



 void FindNearestBonus(int id) {
	Citizen cit = citizen(id);
	Pos citizenPos = cit.pos;
	queue<Posi>q;
	vector<vector<int>>dist (board_rows(),vector<int>(board_cols(),-1));
	q.push(Posi(citizenPos.i, citizenPos.j));
	dist[citizenPos.i][citizenPos.j] = 0;
	while(not q.empty() and q.size() <13) {
		Posi p = q.front();
		q.pop();
		int i = p.i;
		int j = p.j;
		for(int k = 0; k < 4; ++k){
			int ii = i + di[k];
			int jj = j + dj[k];
			if(pos_ok(ii, jj) and cell(ii, jj).id == -1 and cell(ii,jj).type == Street) {
				q.push(Posi(ii, jj));
				dist[ii][jj] = 1+dist[i][j];
				if(cell(ii,jj).bonus == Money) {
					Objective obj; obj.dist=dist[ii][jj]; obj.bonus = Money; obj.p = Pos(p.i, p.j);
					Objectives.insert(make_pair(id, obj));
				}
			}
		}
	}
 }

 void Decode(int id) {
	map<int, Objective>::iterator it = Objectives.find(id);
	if(it != Objectives.end()) {
		Objective obj = it->second;
		Citizen c = citizen(id);
		Pos p = c.pos;
		Pos q = obj.p;
		if(p.i < q.i) move(id, Down);
		else if(p.i > q.i) move(id, Up);
		else if(p.j > q.j) move(id, Left);
		else move(id, Right);
	}
 }

 /*bool IsItPosible(int id, Pos p) {
	queue<Pos>Q;
	Q.push(p);
	while(not Q.empty()) {
		Pos q = Q.front();
		Q.pop();
		for(int i = 0; i < 4; ++i) {
			int u = q.i + x[i];
			int v = q.j + y[i];
			if(M[u][v] == "M") return true;
			if(M[u][v] == 'X' or M[u][v] == 'W') {
				M[u][v] = 'X';
				Q.push(pos(u,v));
			}	
		}
	}
	return false;
 }

 void GetMoving(int id) {
	 Citizen c = citizen(id);
	 if(IsItPosible(id, c.pos))
	//if(round()%15 == 0)FindNearestBonus(id);
	//Decode(id);
	
 }

 void FarmingSimulator() {
	vector<int> w = warriors(me());
	vector<int> b = builders(me());
	Dir GoForIt;
	Citizen c;
	bool Confirmed = false;
	for (int id : w) {
		Pos p = c.pos;
		Contact(id, GoForIt, Confirmed);
		if(Confirmed) move(id, GoForIt);
		else {
			if(IsItPosible(id, p));
			}
	}
	for (int id : b) {
		Contact(id, GoForIt, Confirmed);
		if(Confirmed) move(id, GoForIt);
		else GetMoving(id);
	}
 }

 void Analize() {
	 for(int i = 0; i < board_rows(); ++i) {
		 for(int j = 0; j < board_cols(); ++j) {
			 Cell c = cell(i,j);
			 if(c.id != -1) {
				Citizen Enemy = citizen(c.id);
				if(Enemy.type == Builder) M[i][j] = 'B';
				else if(Enemy.type == Warrior) {
					M[i][j] = 'W';
					for(int k = 0; k < 8; ++k) M[i+xf[k]][j+yf[k]] = 'X';
				}
			 }
			 if(c.bonus == Money) M[i][j] = 'M';
			 else if(c.bonus == Food) M[i][j] = 'F';
			 else if(c.weapon == Hammer) M[i][j] = 'H';
			 else if(c.weapon == Gun) M[i][j] = 'G';
			 else if(c.weapon == Bazooka) M[i][j] = 'Z';
		 }
	 }
 }
 */

  virtual void play () {
	if(!round()) {
		vector<vector<char>> M(board_rows(),vector<char>());
		for(int i = 0; i < board_rows();++i) {
			vector<char> m(board_cols());
			for(int j = 0; j < board_cols(); ++j) {
				Cell c = cell(i,j);
				if(c.type == Building) m[j] = 'P';
				else if(c.id != -1) {
					Citizen Enemy = citizen(c.id);
					if(Enemy.player != me()) {
						if(Enemy.type == Warrior) m[j] = 'W';
						else m[j] = 'B';
					}
				}
				else if(c.weapon != NoWeapon) {
					if(c.weapon == Hammer) m[j] = 'H';
			 		else if(c.weapon == Gun) m[j] = 'G';
			 		else m[j] = 'Z';
				}
				else if(c.bonus != NoBonus) {
					if(c.bonus == Money) m[j] = 'M';
					else m[j] = 'F';
				}
				else m[j] = '.';
				M[i] = m;

			}

		}
	}
	// char c = M[1]][23];
	
	//per cert jugador, mirar si destinacio valida.
	
	  /*
	if(round() == 0) {
		Analize();
	}
	if(is_night()) KillerInstinct();
	else {
		//MedicAssistance();
		FarmingSimulator();
	}
    */


    /*if (is_day()) {
      
      // At day take care of builders
      vector<int> b = builders(me());
      for (int id : b) { // Iterate over all builders
	      Pos p = citizen(id).pos;


	
	// If there is food nearby, move there
	      bool food_nearby = false;
	      Dir food_dir;
	      for (Dir d : dirs) {
  	      if (pos_ok(p+d) and cell(p+d).bonus == Food) {
	          food_nearby = true;
	          food_dir = d;
	        }
	      }
	      if (food_nearby) move(id,food_dir);	
	      else { // No food nearby
    	    if (random(0,3) <= 1) {// Do this with 25% probability [try to build in random position]
    	      bool some_dir = false;
	          for (uint i = 0; not some_dir and i < dirs.size(); ++i){
      	      Dir d = dirs[i];
	            Pos np = p + d;
	            if (pos_ok(np)) { // pos_ok checks np is in the board, but here something else would be needed to make   
    		        build(id,d);    // sure we can construct
		            cerr << "build " << id << " dir " << d << endl;
		            some_dir = true;
	            }
	          }
	        } 
	        else { // Do this with 75% probability [move to money if possible, otherwise randomly]
  	        Dir random_dir = dirs[random(0,3)];
	          if (pos_ok(p+random_dir) and (cell(p+random_dir).id == -1 or 
  					  citizen(cell(p+random_dir).id).type == Builder)) { // Move there if no citizen or builder	     
    	        move(id,random_dir);
	            cerr << "move " << id << " dir " << random_dir << endl;
	          }
	        }
	      }
      }
    }
    else {
      // At night take care of warriors
      vector<int> w = warriors(me());
      for (int id : w) { // Iterate over all warriors
	      if (random(0,9) < 6) {// 60 % probability move randomly, otherwise do nothing
	        Dir random_dir = dirs[random(0,3)];
    	    Pos p = citizen(id).pos;
      	  if (pos_ok(p+random_dir)) {
      	    cerr << "move " << id << " dir " << random_dir << endl;
      	    move(id,random_dir);
	        }
	      }	
      }
    }
	*/
  
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
