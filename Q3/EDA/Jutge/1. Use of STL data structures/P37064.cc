#include <iostream>
#include <set>
using namespace std;

int main() {
    string inp;
    set<string> serie;
    set<string>::iterator it = serie.begin(), mid;
    cin >> inp;
    if (inp != "END") {
        it = serie.insert(it, inp);
        mid = serie.begin();
        cout << inp << endl;
        while (cin >> inp and inp != "END") {
            serie.insert(it, inp);
            if (inp < *mid and serie.size() % 2 == 0) --mid;
            else if (inp > *mid and serie.size() % 2 != 0) ++mid;
            cout << *mid << endl;
            }
    }
    
}