#include <iostream>
#include <queue>
using namespace std;

void calc_max_min(queue<int> v, int& min, int& max) {
    max = -1000, min = 1000;
    while (!v.empty()) {
        if (max < v.front()) max = v.front();
        if (min > v.front()) min = v.front();
        v.pop();
    }
}

int main() {
    int y, max = -1000, min = 1000;
    double total = 0;
    queue<int> v;
    while (cin >> y and y <= 1000 and y >= -1001) {
        if (y != -1001) {
            v.push(y);
            if (y > max) max = y;
            if (y < min) min = y;
            total += y;      
        } else if (!v.empty()) {
            int num = v.front();
            v.pop();
            total -= num;
            if (num == max or num == min) calc_max_min(v, min, max);
        }
        if (v.empty()) {
            cout << '0' << endl;
            max = -1000, min = 1000;
        } else {
            cout << "min " << min << "; max " << max << "; media " << (total/v.size()) << endl;
        }

    }


}