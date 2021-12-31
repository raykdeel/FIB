#include <iostream>
#include <map>
using namespace std;

void add_word(map<string, int>& bag, string word) {
    map<string, int>::iterator it = bag.find(word);
    if(it != bag.end()) ++it->second;
    else bag.insert(make_pair(word,1));
}

void erase_word(map<string, int>& bag, string word) {
    map<string, int>::iterator it = bag.find(word);
    if(it != bag.end()) {
        if(it->second > 1) --it->second;
        else bag.erase(it);
    }
}

int main() {
    string query;
    string word;
    map<string, int> bag;
    map<string, int>::iterator it;
    while(cin >> query) {
        if(query == "store" or query == "delete") {
            cin >> word;
            if(query == "store") add_word(bag,word);
            else erase_word(bag,word);
        }
        if(query == "minimum?") {
            if(!bag.size()) cout << "indefinite minimum" << endl;
            else {
                it = bag.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        if(query == "maximum?") {
            if(!bag.size()) cout << "indefinite maximum" << endl;
            else {
                it = bag.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
    }
}