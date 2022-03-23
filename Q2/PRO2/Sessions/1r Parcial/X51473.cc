#include <list>
using namespace std;

/* Pre: l is not empty, sol is empty */
/* Post: sel is the result of extracting from l the elements weak on average */
 
void seleccio(const list<double>& l, list<double>& sel) {
    double average = *(l.begin()), c = 1;
    sel.push_back(average);
    for (list<double>::const_iterator it = ++l.begin(); it != l.end(); ++it) {
        if (average/c <= *it) sel.push_back(*it);
        average += *it;
        ++c;
    }
}