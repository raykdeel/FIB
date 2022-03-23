#include <iostream>
#include <list>
#include "LlistaIOParInt.hh"
#include "ParInt.hh"
using namespace std;

int main() {
    list<ParInt> a;
    LlegirLlistaParInt(a);
    int x, y = 0, total = 0;
    cin >> x;
    for(list<ParInt>::iterator it = a.begin(); it != a.end(); ++it) {
        if ((*it).primer() == x) {
            ++y;
            total += (*it).segon();
        }
    }
    cout << x << " " << y << " " << total << endl;
}