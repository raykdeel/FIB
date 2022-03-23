#include <stack>
#include "BinTree.hh"
using namespace std;

void i_cami_preferent(const BinTree<int>& a, stack<int>& c) {
    int nodes;
    if (a.empty()) nodes = 0;
    else {
        nodes = 1 + i_cami_preferent(a.left(), c) + i_cami_preferent(a.right(), c);
    }
    if (not a.empty()) {
        int left = i_cami_preferent(a.left(), c)
        int right = i_cami_preferent(a.right(), c);
        if (right > left) c.push(a.right().value());
        else c.push(a.left().value());
    }
}


 /* Pre: c is empty */
 /* Post: c contains the preferential path of a; if it is non-empty, the
          first element of the path is on the top of c */
void cami_preferent(const BinTree<int>& a, stack<int>& c) {
    if (not a.empty()) {
        i_cami_preferent(a, c);
    }
}

