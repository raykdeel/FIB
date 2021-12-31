#include <iostream>
#include <map>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    string inp;
    double average = 0, numt = 0;
    map<int, int> serie;
    map<int, int>::iterator it;
    int num;
    while (cin >> inp) {
        if (inp == "number") {
            cin >> num;
            it = serie.find(num);
            average += num;
            ++numt;
            if (it == serie.end()) {
                serie.insert(make_pair(num, 1));
            } else ++it->second;
        } else if (serie.begin() != serie.end()) {
            --numt;
            average -= serie.begin()->first;
            --serie.begin()->second;
            if (serie.begin()->second == 0) serie.erase(serie.begin());

        } 
        if (serie.size() == 0) cout << "no elements" << endl;
        else cout << "minimum: " << serie.begin()->first << ", maximum: " << (--serie.end())->first << ", average: " << average/numt << endl;
    }



}