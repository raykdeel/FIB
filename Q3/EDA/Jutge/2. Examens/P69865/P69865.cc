#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> matrix;
typedef vector<vector<int>> int_matrix;

struct Pos {
    int x, y;
};

const int di[4] = { 1, -1, 1, -1};
const int dj[4] = { 1, -1, -1, 1};

void read_board(matrix& board, vector<pair<char,Pos>>& pieces, vector<Pos>& coins) {
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); ++j) {
            cin >> board[i][j];
            if(board[i][j] == 'B') {Pos aux; aux.x = i, aux.y = j; pieces.push_back(make_pair('B',aux));}
            else if (board[i][j] == 'K') {Pos aux; aux.x = i, aux.y = j; pieces.push_back(make_pair('K',aux));}
            else if (board[i][j] != 'T' and board[i][j] != '.') {Pos aux; aux.x = i, aux.y = j; coins.push_back(aux);}
        }
    }
}

bool feasible(Pos aux, matrix board, vector<pair<char,Pos>> pieces) {
    for(auto i : pieces) {
        if(i.first == 'B') {
            int_matrix dist(board.size(), vector<int>(board[0].size(),-1));
            queue<Pos> q;
            Pos a; a.x = i.second.x; a.y = i.second.y;
            q.push(a);
            dist[a.x][a.y] = 0;
            while(not q.empty()) {
                Pos p = q.front();
                q.pop();
                int iu = p.x;
                int j = p.y;
                for(int k = 0; k < 4; ++k){
                    int ii = iu + di[k];
                    int jj = j + dj[k];
                    if(ii < board.size() and jj < board[0].size() and board[ii][jj] != 'T' and dist[ii][jj] == -1) {
                        Pos b; b.x = ii; b.y = jj;
                        q.push(b);
                        dist[ii][jj] = 1 + dist[iu][j];
                        if(ii == aux.x and jj == aux.y) return true;
                    }
                }
            }
        }
    }
    return false;
}

void swap(vector<Pos>& coins, int k) {
    Pos aux = coins[k];
    coins[k] = coins[coins.size()-1];
    coins[coins.size()-1] = aux;
}

void remove_coin(int k, vector<Pos>& coins) {
    for(int j = 0; j < coins.size(); ++j) {
        if(k == j) {
            swap(coins, k);
            coins.pop_back();
        }
    }

}

int pick_coins(matrix board, vector<pair<char,Pos>> pieces, vector<Pos>& coins) {
    int total = 0;
    if(!pieces.size() or board.size() == 1 or board[0].size() == 1 or !coins.size()) return 0;
    else {
        for(int k = 0; k < coins.size(); ++k) {
            Pos i = coins[k];
            if(feasible(i, board, pieces)) {total += board[i.x][i.y] - '0'; remove_coin(k, coins);}
        }
    }
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;
    matrix board(n, vector<char>(m));
    vector<pair<char,Pos>> pieces;
    vector<Pos> coins;
    read_board(board, pieces, coins);
    cout << pick_coins(board, pieces, coins);


}

#include <iostream>
#include <vector>
using namespace std;
struct Point {
int r, c ;
Point(int rr, int cc) : r(rr ), c(cc ) {}
};
bool ok(int n, int m, const Point& p) {
return
0 ≤ p.r and p.r < n and
0 ≤ p.c and p. c < m;
}
const int N DIRS KNIGHT = 8;
const int DR KNIGHT[8] = {−2, −1, 2, 1, −2, −1, 2, 1};
const int DC KNIGHT[8] = {−1, −2, −1, −2, 1, 2, 1, 2};
const int N DIRS BISHOP = 4;
const int DR BISHOP[4] = { 1, −1, 1, −1};
const int DC BISHOP[4] = { 1, 1, −1, −1};
int dfs(int n, int m, const Point& p,
vector< vector<char> >& map, vector< vector<bool> >& marked,
const int N DIRS, const int DR[], const int DC[]) {
int s = 0;
marked[p.r][p.c] = true;
for (int i = 0; i < N DIRS; ++i) {
Point q(p.r + DR[i], p.c + DC[i]);
if (ok(n,m,q) and map[q.r][q. c] 6= 'T' and not marked[q.r][ q. c ])
s += dfs(n, m, q, map, marked, N DIRS, DR, DC);
}
if ( ' 0' ≤ map[p.r][p. c] and map[p.r][p. c] ≤ '9' ) {
s += map[p.r][p. c] − '0' ;
map[p.r][p.c] = ' . ' ;
}
return s;
}
int main(void) {
int n, m;
while (cin >> n >> m) {
Solucions d’Ex`amens d’Ordinador 313
vector<Point> knights, bishops ;
vector< vector<char> > map(n, vector<char>(m));
for (int i = 0; i < n; ++i)
for (int j = 0; j < m; ++j) {
cin >> map[i][j ];
switch(map[i][j ]) {
case ' K': knights.push back(Point(i , j )); break;
case 'B' : bishops .push back(Point(i , j )); break;
};
}
int s = 0;
vector< vector<bool> > marked knight(n, vector<bool>(m, false));
for (int k = 0; k < knights. size (); ++k) {
Point p = knights[k ];
if (not marked knight[p.r][ p.c ])
s += dfs(n, m, p, map, marked knight, N DIRS KNIGHT, DR KNIGHT, DC KNIGHT);
}
vector< vector<bool> > marked bishop(n, vector<bool>(m, false));
for (int k = 0; k < bishops. size (); ++k) {
Point p = bishops[k ];
if (not marked bishop[p.r][ p.c ])
s += dfs(n, m, p, map, marked bishop, N DIRS BISHOP, DR BISHOP, DC BISHOP);
}
cout << s << endl;
}
}



