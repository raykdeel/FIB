#include <iostream>
#include <vector>
using namespace std;

void rec(vector<char>& parcial, int idx, int monedes, int accions) {
    if(idx == int(parcial.size())) {
        for(auto& x: parcial) cout << x;
        cout << endl;
    } else {
        if(monedes > 0) {
            parcial[idx] = 'b';
            rec(parcial, idx+1, monedes-1, accions+1);
        }
        if(accions > 0) {
            parcial[idx] = 's';
            rec(parcial, idx+1, monedes+1, accions-1);
        }
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<char> parcial(n);
    rec(parcial, 0, c, 0);
}