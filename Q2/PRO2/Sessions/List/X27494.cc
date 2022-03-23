#include <iostream>
#include <list>
using namespace std;


void calc_max_min(list<int>& l, int& min, int& max) {
    if (!l.empty()) {
        max = *l.begin();
        min = *l.begin();
        for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
            if (*it > max) max = *it;
            if (*it < min) min = *it;
        }
    }
}

void delete_ele(list<int>& l, int& y, double& total) {
    if (!l.empty()) {
        list<int>::iterator it = l.begin();
        while (it != l.end()) {
            if (*it == y) {
                it = l.erase(it);
                total -= y;
                return;
            } else ++it;
        }
    }
}

int main() {
    int op, y, min, max;
    double total = 0;
    list<int> l;
    while (cin >> op >> y and not (op == 0 and y == 0)) {
        if (op  == -1) {
            if (l.empty()) {
                min = max = y;
            } else {
                if (max < y) max = y;
                if (min > y) min = y;
            }   
            l.push_front(y);
            total += y;
        } else if (op == -2) {
            delete_ele(l, y, total);
            if (max == y or min == y) calc_max_min(l, min, max);
        } 
        if (!l.empty()) cout << min << ' ' << max << ' ' << total/l.size() << endl;
        else cout << 0 << endl;
    }
}