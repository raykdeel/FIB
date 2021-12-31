#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<bool> VB;
typedef vector<VB> MB;
const int N DIRS = 4;
const int DI[N DIRS] = { 1, 0, −1, 0};
const int DJ[N DIRS] = { 0, 1, 0, −1};
bool ok(int n, int m, int i , int j) {
return
0 ≤ i and i < n and
0 ≤ j and j < m;
}
int search (const MC& map, int n, int m, int i , int j , MB& marked) {
int t = 0;
if (map[i][j] == ' t ' ) ++t;
marked[i][ j] = true;
for (int k = 0; k < N DIRS; ++k) {
int ii = i + DI[k ];
int jj = j + DJ[k ];
if (ok(n, m, ii , jj ) and map[ii][ jj ] 6= 'X' and not marked[ii][ jj ])
t += search(map, n, m, ii , jj , marked);
}
return t;
}
int main(void) {
int n, m;
cin >> n >> m;
MC map(n, VC(m));
for (int i = 0; i < n; ++i)
for (int j = 0; j < m; ++j)
cin >> map[i][j ];
int f , c ;
cin >> f >> c;
MB marked(n, VB(m, false));
286 Solucions d’Ex`amens d’Ordinador
cout << search(map, n, m, f−1, c−1, marked) << endl;
}