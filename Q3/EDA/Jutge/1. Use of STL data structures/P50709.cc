#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    int x;
    map<int, int> serie;
    map<int, int>::iterator it;
    while (cin >> s) {
        if (s == "S") {
            cin >> x;
            it = serie.find(x);
            if (it == serie.end()) {
                serie.insert(make_pair(x, 1));
            } else ++it->second;
        } else if (serie.end() != serie.begin()) {
            if (s == "R") {
                it = serie.end();
                --it;
                --it->second;
                if(it->second == 0) serie.erase(it);
            } else if (s == "I") {
                it = serie.end();
                --it;
                cin >> x;
                it->first+ x;
            } else if (s == "D") {
                it = serie.end();
                --it;
                cin >> x;
                it->first-x;
            } else if (s == "A") {
                it = serie.end();
                --it;
                cout << it->first << endl;
            }
        } else cout << "error!" << endl;
        
    }
}