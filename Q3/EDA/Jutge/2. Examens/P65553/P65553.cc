#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m;
    while(cin >> n) {
        map<string, int> v;
        string aux;
        int total_instances = 0;
        for(int i = 0; i < n; ++i) {
            cin >> aux;
            auto it = v.find(aux);
            if(it != v.end()) {
                ++(it->second);
            } else v.insert({aux,1});
            ++total_instances;
        }
        cin >> m;
        int i = 0;
        while(i < m) {
            cin >> aux;
            auto it = v.find(aux);
            if(it == v.end() and v.size() > 0) {
                v.insert({aux,1});
                ++total_instances;
            } else {
                if(it->second+1 <= total_instances-(it->second)) {
                    ++(it->second);
                    ++total_instances;
                }
            }
            ++i;
        }
        for(auto x : v) {
            cout << x.first << " " << x.second << endl;
        }
        cout << "--------------------" << endl;
    }

}