#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& v, const vector<bool>& sol) {
    cout << '{';
    bool first = true;
    for(int i = 0; i < int(v. size ()); ++i) {
        if(sol[i]) {
            if(first) first = false ;
            else cout << ',';
            cout << v[i];
        }
    }
    cout << '}' << endl;
}


void bt(int s, int k, const vector<int>& v, int sp, int sn, vector<bool>& sol) {
    if(sp > s or sp + sn < s) return;
    if(k == int(v.size())) write(v, sol);
    sol[k] = false;
    bt(s, k+1, v, sp, sn-v[k], sol);
    sol[k] = true;
    bt(s, k+1, v, sp+v[k], sn-v[k], sol);
}

int main() {
    int s, n, sum = 0;
    cin >> s >> n;
    vector<int> v(n);
    for(int& x : v) {cin >> x; sum+= x;}
    vector<bool>sol(n);
    bt(s, 0, v, 0, sum, sol);
}