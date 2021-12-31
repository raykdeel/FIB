#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int UNDEF = -1;
const int NDIRS = 4;
const int DI[NDIRS] = { 1, 0, -1, 0};
const int DJ[NDIRS] = { 0, 1, 0, -1};

struct Pos {
    int i,j;
    Pos(int ii,int jj ) : i(ii), j(jj) { }
};

bool ok(int n,int m,int i ,int j) {
    return 0 <= i and i < n and 0 <= j and j < m;
}

int bfs(const vector<vector<char>>& map, int i0, int j0) {
    int n = map.size();
    int m = map[0].size();
    queue<Pos> q;
    q.push(Pos(i0,j0));
    vector<vector<int>>dist(n, vector<int>(m, UNDEF));
    dist[i0][j0]=0;
    while (not q.empty()) {
        Pos p = q.front();
        q.pop();
        int i = p.i;
        int j = p.j;
        if(map[i][j] == 't') return dist[i][j];
        else {
            for(int k = 0; k < NDIRS; ++k) {
                int ii = i + DI[k];
                int jj = j + DJ[k];
                if (ok(n, m, ii , jj ) and map[ii][jj] != 'X' and dist[ii][jj] == UNDEF) {
                    q.push(Pos(ii,jj));
                    dist[ii][jj] = 1 + dist[i][j];
                }
            }
        }
    }
    return UNDEF;
}
int main(void) {
    int n, m;
    cin >> n >> m;
    vector < vector<char> > map(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> map[i][j];
    int f,c;
    cin >> f >> c;
    int dist = bfs(map, f-1, c-1);
    if (dist > 0) cout << "minimum distance: " << dist << endl;
    else cout << "no treasure can be reached" << endl;
}
