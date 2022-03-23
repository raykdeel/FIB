#include <iostream>
#include <vector>
using namespace std;

int suma(const vector<int> &v) {
    int sum = 0;
    for (int i = 1; i < v.size(); ++i) sum += v[i];
    return sum;
}

/* Pre: cert */
/* Post: el resultat es el nombre d'elements frontissa de v */
int comptatge_frontisses(const vector<int> &v) {
    int sant = 0, spos;
    spos = suma(v);
    int i = 0, c = 0;
    while (i < v.size()) {
        if (spos - sant == v[i]) ++c;
        sant += v[i];
        if (i != v.size()-1) spos -= v[i+1];
        ++i;
    }
    return c;
}
