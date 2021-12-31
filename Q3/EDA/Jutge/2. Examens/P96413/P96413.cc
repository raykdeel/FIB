#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

const int UNDEF = -1;

int main() {
    int n, t;
    while(cin >> n >> t) {
        vector<unordered_set<int>> g(n);
        while(--t >= 0) {
            int s;
            cin >> s;
            vector<int> pub(s);
            for(int i = 0; i < s; ++i) cin >> pub[i];
            for(int i = 0; i < s; ++i) {
                for(int j = i+1; j < s; ++j) {
                    int u = pub[i];
                    int v = pub[j];
                    g[u].insert(v);
                    g[v].insert(u);
                }
            }
        }
        vector<int> dst(n, UNDEF);
        queue<int> q;
        dst[0] = 0;
        q.push(0);
        while(not q.empty()) {
            int u = q. front();
            q.pop();
            for(int v : g[u]) {
                if(dst[v] == UNDEF) {
                    dst[v] = dst[u] + 1;
                    q.push(v);
                }
            }
        }
        for(int u = 0; u < n; ++u) {
            cout << u << " : ";
            if( dst[u] == UNDEF) cout << "no";
            else cout << dst[u];
            cout << endl;
        }
        for(int k = 0; k < 10; ++k) cout << "-";
        cout << endl;
    }
}