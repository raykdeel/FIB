#include <iostream>
#include <set>
using namespace std;

int main() {
    int x;
    int maxsq = 0;
    set<int> sq;
    set<int>::iterator sqIt, sqItplus;
    while (cin >> x) {
        sqIt = sq.find(x);
        if (sqIt == sq.end()) sq.insert(x);
    }
    sqIt = sq.begin();
    sqItplus = sqIt;
    ++sqItplus;
    while(sqItplus != sq.end()) {
        if (*sqIt % 2 == 0 and *sqIt % 2 == 1) ++maxsq;
        else if (*sqIt % 2 == 1 and *sqIt % 2 == 0) ++maxsq;
        else maxsq = 0;
        ++sqIt;
        ++sqItplus;
    }
    cout << maxsq << endl;

}

// 8 8 8 5 5 3
// 3 5 5 8 8 8
// 3 5 8