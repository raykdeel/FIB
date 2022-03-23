#include <iostream>
#include <vector>
using namespace std;


 /* Pre: v.size() > 0 */
 /* Post: el resultat es el nombre de solitaris a v */
int solitaris(const vector<int> &v) {
    int num = 0;
    int i = 0;
    while(i < v.size()){
        if(i == 0) {
            if (v[i] != v[i+1]) ++num;
        }
        else if (i == v.size()-1) {
            if (v[i-1] != v[i]) ++num;
        }
        else {
            if (v[i] != v[i+1] and v[i] != v[i-1]) ++num;
        }
        ++i;
    }
    return num;
}

