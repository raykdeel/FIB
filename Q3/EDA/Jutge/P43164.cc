#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> DIRS = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
const int UNDEF = -1;

int dist_2on_tresor_mes_llunya(int i0,int j0,vector<vector<char>>& mapa) {
    int max_dist = UNDEF;
    int max_dist2 = UNDEF;
    queue<pair< pair<int, int>, int>> q;
    q.push({{i0,j0},0});
    mapa[i0][j0] = 'X';
    while (!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;
        q.pop ();   
        for (auto dir : DIRS) {
            int ii = i + dir.first;
            int jj = j + dir.second;
            if (mapa[ii][jj] != 'X') {
                if (mapa[ii][jj] == 't') {
                    max_dist2 = max_dist;
                    max_dist = d+1;
                }
            q.push({{ii,jj}, d+1});
            mapa[ii][jj] = 'X';
            }
        }
    }
    return max_dist2;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mapa(n+2, vector<char>(m+2, 'X'));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mapa[i][j];
    int f,c;
    cin >> f >> c;
    int d2 = dist_2on_tresor_mes_llunya(f,c,mapa);
    if (d2 == UNDEF) cout << "we cannot reach two or more treasures" << endl;
    else cout << "second maximum distance: " << d2 << endl;
}
