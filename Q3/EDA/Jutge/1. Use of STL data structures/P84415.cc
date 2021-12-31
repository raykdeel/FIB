#include <iostream>
#include <map>
using namespace std;

int main() {
    string inp;
    string let;
    map <string, int> bag;
    map <string, int>::iterator bagIt;
    while (cin >> inp) {
        if (inp == "store") {
            cin >> let;
            bagIt = bag.find(let);
            if (bagIt == bag.end()) {
                bag.insert(make_pair(let, 1));
            }
            else ++bagIt->second;


        } else if (inp == "delete") {
            cin >> let;
            bagIt = bag.find(let);
            if(bagIt != bag.end()) {
                if(bagIt->second != 1) {
                    --bagIt->second;
                } else bag.erase(bagIt);
            }

        } else {
            if(inp == "minimum?") {
                if (!bag.empty()) {
                    bagIt = bag.begin();
                    cout << "minimum: " << bagIt->first << ", " << bagIt->second << " time(s)" << endl;
                } else cout << "indefinite minimum" << endl;
            } else {
                if (!bag.empty()) {
                    bagIt = --bag.end();
                    cout << "maximum: " << bagIt->first << ", " << bagIt->second << " time(s)" << endl;
                } else cout << "indefinite maximum" << endl;
            }


        }
    }
}