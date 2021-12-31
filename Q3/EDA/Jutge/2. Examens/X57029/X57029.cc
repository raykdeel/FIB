#include <iostream>
#include <vector>
using namespace std;

void rec(vector<char>& parcial, int idx, int height) {
    if(idx == int(parcial.size())) {
        for(auto& x : parcial) cout << x;
        cout << endl;
    } else {
        if(height > 0) {
            parcial[idx] = 'd';
            rec(parcial, idx+1, height-1);
        }
        parcial[idx] = 'h';
        rec(parcial, idx+1, height);
        parcial[idx] = 'u';
        rec(parcial, idx+1, height+1);
    }

}

int main() {
    int n;
    cin >> n;
    vector<char> parcial(n);
    rec(parcial, 0, 0);

}