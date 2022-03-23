#include <iostream>
#include "BinTree.hh"

using namespace std;

int alcada(const BinTree<int>& a) {
    if (a.empty()) return 0;
    else if (a.left().empty() and a.right().empty()) return 1;
    else {
        return 1 + max(alcada(a.left()), alcada(a.right()));
    }
}

/* Pre: a=A */
/* Post: agd es un arbre amb la mateixa estructura que A on cada
	 node conte el grau de desequilibri del subarbre d'A corresponent */

void arbre_graus_desequilibri(const BinTree<int>& a, BinTree<int>& agd){
	if (not a.empty()){
        BinTree<int> esq;
        BinTree<int> dre;
        int res = alcada(a.left())-alcada(a.right());
        arbre_graus_desequilibri(a.left(), esq);
        arbre_graus_desequilibri(a.right(), dre);
        agd = BinTree<int>(res, esq, dre);
	}
}