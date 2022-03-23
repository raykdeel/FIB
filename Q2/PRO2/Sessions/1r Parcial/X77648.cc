
#include <iostream>
#include "BinTree.hh"
#include <stack>

using namespace std;

bool i_quasi_coincidents(const BinTree<int> &a, const BinTree<int> &b, bool& dif){
	if (a.empty() and b.empty()) return true;
	if ((a.empty() and not b.empty()) or (b.empty() and not a.empty())){
		if (dif) return false;
		else {
			dif = true;
			if (not a.empty() and a.right().empty() and a.left().empty()) return true;
			if (not b.empty() and b.right().empty() and b.left().empty()) return true;
			return false;
		}
	}
	else return (i_quasi_coincidents(a.left(),b.left(),dif) and i_quasi_coincidents(a.right(),b.right(),dif));
}

/* Pre: cert */
/* Post: el resultat indica si a i b son quasi coincidents */

bool quasi_coincidents(const BinTree<int> &a, const BinTree<int> &b){
	bool dif = 0;
	return i_quasi_coincidents(a,b,dif);
}