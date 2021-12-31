#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    long long int value, total;
    cin >> n;
    string action;
    set<long long int> jewels;
    set<long long int>::iterator it;
    while(cin >> action >> value) {
        total = 0;
        if(action == "leave") jewels.insert(value);
        else if(action == "take") {
            jewels.erase(value);
        }
        if(jewels.size() > 0) {
            int i = 0;
            it = jewels.end();
            --it;
            bool leave = false;
            while(i < n and not leave) {
                if(it == jewels.begin()) {leave = true; total += *it;}
                else {
                    total += *it;
                    --it;
                }
                ++i;
            }
            cout << total << endl;
        }

    }

}