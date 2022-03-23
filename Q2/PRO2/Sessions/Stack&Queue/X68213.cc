#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void write_stack(stack<string> u, int cat) {
    cout << "Pila de la categoria " << cat << endl;
    while (not u.empty()) {
        cout << u.top() << endl;
        u.pop();
    }
    cout << endl;
}

int main() {
    int n, op, cat, num;
    cin >> n;
    vector < stack<string> > v(n);
    string nom;
    while (cin >> op and op != -4) {
        if (op == -1) {
            cin >> nom >> cat;
             v[cat-1].push(nom);
        } else if (op == -2) {
            cin >> num >> cat;
            for (int i = 0; i < num; ++i) {
                v[cat-1].pop();
            }
        } else {
            cin >> cat;
            write_stack(v[cat-1], cat);
        }
    }
}