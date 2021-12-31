#include <iostream>
#include <queue>
using namespace std;


struct OwnComp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first + p1.second < p2.first + p2.second;
    }
};

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q; //ordena de - a +
    //no greater -> OwnComp
    
}