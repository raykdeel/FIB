#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<string> c;
typedef vector<c> matrix;

vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

bool ok(const vector<vector<string>>& M, int i, int j) {
    return i >= 0 and i < int(M.size()) and j >= 0 and j < int(M[0].size()) and M[i][j] != "*";
}

int bfs(const vector<vector<string>>& M, pair<int,int>& orig, pair<int,int>& dest) {
    int n = M.size();
    int m = M[0].size();
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> Q;
    Q.push(orig);
    dist[orig.first][orig.second] = 0;
    while(not Q.empty()) {
        pair<int,int> u = Q.front();
        Q.pop();
        if(u == dest) return dist[u.first][u.second];
        for (auto& d : dirs) {
            pair<int,int> v = u;
            v.first += d.first;
            v.second += d.second;
            if(ok(M,v.first,v.second) and dist[v.first][v.second] == -1) {
                Q.push(v);
                dist [v.first][v.second] = dist[u.first][u.second] + 1;
            }
        }
    }
    return -1;
}


pair<int,int> position(const vector<vector<string>>& M, const string& s){
    for (uint i = 0; i < M.size(); ++i){
        for (uint j = 0; j < M[0].size(); ++j){
            if (M[i][j] == s) return {i,j};
        }
    }
    return {-1,-1};
}
int main() {
    int n, m;
    while(cin >> n >> m) {
        matrix v(n, c(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> v[i][j];
            }
        }
        int p;
        cin >> p;
        vector<string> title(p);
        for(auto& x: title) cin >> x;
        vector<pair<int,int>> positions(p+1);
        positions[0] = {0,0};
        for(int i = 0; i < p; ++i) positions[i+1] = position(v,title[i]);
        
        int total = 0;
        bool ok = true;
        for (uint i = 0; ok and i < positions.size()-1; ++i) {
            int d = bfs(v,positions[i], positions[i+1]);
            if (d == -1) ok = false;
            else total += d;
        }
        if(ok) cout << (total+p) << endl;
        else cout << "impossible" << endl;

    }

}