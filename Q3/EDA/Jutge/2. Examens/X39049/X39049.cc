#include <iostream>
#include <vector>
#include <set>
using namespace std;

void permutation_product(vector<int> v, vector<int> aux, int k) {
    if(k == 0) {
        for(int i = 0; i < v.size(); ++i) {
            aux[i] = i;
        }
    } else {
        int i = 1;
        while(i < k) {
            for(int i = 0; i < v.size(); ++i) {
                aux[i] = v[aux[i]];
            }
            ++i;
        }
    }
    for(int i = 0; i < v.size(); ++i) {
        cout << aux[i];
        if(i < v.size()-1) cout << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    while(cin >> n) {
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];
        cin >> k;
        vector<int> aux = v;
        permutation_product(v,aux,k);
    }
}