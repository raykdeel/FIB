#include <iostream>
#include <vector>
using namespace std;

void rec(vector<char>& parcial, int idx, int As, int Bs) {
    if(idx == int(parcial.size())) {
        for(auto& x: parcial) cout << x;
        cout << endl;
    } else {
        if(As - Bs < 2) {
            parcial[idx] = 'a';
            rec(parcial, idx+1, As+1, Bs);
        }
        if(Bs - As < 2) {
            parcial[idx] = 'b';
            rec(parcial, idx+1, As, Bs+1);
        }
    }

}

int main() {
    int n;
    cin >> n;
    vector<char> parcial(n);
    rec(parcial, 0, 0, 0);

}
