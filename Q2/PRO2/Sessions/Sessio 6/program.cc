// (c) FIBerHub, https://fiberhub.tk

#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"
#include "BinTreeIOParInt.hh"
using namespace std;

int cercar(const BinTree<ParInt>& a, int n, int& s) {
    if (not a.empty()) {
        if (a.value().primer() == n) {
            s = a.value().segon();
            return 0;
        }
        int left = cercar(a.left(), n, s);
        if (left != -1) return 1 + left;
        int right = cercar(a.right(), n, s);
        if (right != -1) return 1 + right;
    }
    return -1;
}

int main() {
    BinTree<ParInt> arbre;
    read_bintree_parint(arbre);

    int n, s;
    while (cin >> n) {
        int p = cercar(arbre, n, s);
        if (p != -1) {
            cout << n << ' ' << s << ' '  << p << endl;
        } else cout << -1 << endl;

    }
}
