#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> dirs = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};

bool ok(int i, int j, int n, int m) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

int bfs(const pair<int,int>& orig, const pair<int,int>& dest, int n, int m) {
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
            if(ok(v.first,v.second,n,m) and dist[v.first][v.second] == -1) {
                Q.push(v);
                dist[v.first][v.second] = dist[u.first][u.second] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int n, m, w, l, k;
    while(cin >> n >> m >> w >> l >> k) {
        vector<pair<int,int>> goals(k+1);
        bool first = true;
        for(auto& x: goals) {
            if(first) {x.first = 0; x.second = 0; first = false;}
            else cin >> x.first >> x.second;
        } 
        int dist, total = 0, best_points = 0;
        bool stop = false;
        for(int i = 0; not stop and i < goals.size()-1; ++i) {
            dist = bfs(goals[i],goals[i+1],n,m);
            if(dist == -1) stop = true;
            else {
                total+=w-(dist*l);
                if(total > best_points) best_points = total;
            }
        }
        cout << total << endl;
        
    }
}