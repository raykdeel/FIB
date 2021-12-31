#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> CVec;
typedef vector<CVec> CMat;
typedef vector<bool> BVec;
typedef vector<BVec> BMat;

const int NDIRS = 4;
const int DR[NDIRS] = { 0,-1, 0, 1};
const int DC[NDIRS] = { 1, 0,-1, 0};

struct Point {
    int r,c;
    Point(int rr, int cc) : r(rr), c(cc) { }
};

bool ok(int r, int c , int n, int m) {
    return 0 <= r and r < n and 0 <= c and c < m;
}

void search (int re, int ce, int n, int m, const CMat& t, vector<Point>& v, BMat& seen) {
    Point p = v.back ();
    if (p.r == re and p.c == ce) {
        for (int i = 0; i < v.size (); ++i)
            cout << t[v[i].r][v[i].c];
        cout << endl;
    }
    else {
        for (int k = 0; k < NDIRS; ++k) {
            int rr = p.r + DR[k];
            int cc = p.c + DC[k];
            if (ok(rr,cc,n,m) and not seen[rr][cc]) {
                seen[rr][cc] = true;
                v.push_back(Point(rr,cc));
                search (re,ce,n,m,t,v,seen);
                v.pop_back();
                seen[rr][cc] = false ;
            } 
        }
    }
}

int main(void){
    int n,m;
    cin >> n >> m;
    CMat t(n,CVec(m));
    BMat seen(n,BVec(m,false));
    for(int i = 0;i<n; ++i)
        for(int j = 0;j<m; ++j)
            cin >>t[i][j];
    int ri,ci,re,ce;
    cin >> ri >> ci >> re >> ce;
    seen[ri][ci] = true;
    vector<Point>v(1, Point(ri,ci));
    search(re,ce,n,m,t,v,seen);
}