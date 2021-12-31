#include <iostream>
#include <vector>
using namespace std;

void rec(vector<int>& v, int m, int idx, int pos) {
    if(pos >= -m/2 and pos <= m/2) {
        if(idx == int(v.size())) {
            cout << pos << endl;
        }
        else {
            rec(v, m, idx+1, pos+v[idx]);
            rec(v, m, idx+1, pos-v[idx]);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    for(int& i : v) cin >> i;
    rec(v, m, 0, 0);

}