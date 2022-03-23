#include <iostream>
using namespace std;

main() {
    int x;
    int* p, q;
    cout << &(*p) << "(&(*p)) " << p << "(p)" << endl;
    if (&(*p) == p) cout << "True" << endl;
    else cout << "Fake;"
}