#include <iostream>
#include "Cluster.hh"
#include <string>
using namespace std;

//CONSTRUCTORES

Cluster::Cluster(BinTree<string> aux) {
    arbre2 = aux;
}

Cluster::Cluster(BinTree<string> aux, map<string, double> aux1) {
    arbre2 = aux;
    idk = aux1;
}

Cluster::Cluster() {
}

//MODIFICADORES

void Cluster::modificar_arbre(const BinTree<string>& b) {
    arbre2 = b;
}

/*void Cluster::modificar_idcl(const Especie& a) {
    idcluster += a.consultar_identificador();
}
*/

void Cluster::fusio_clusters(const Cluster& A, const Cluster& B, const string& a) {
    BinTree<string> d = A.consultar_arbre();
    BinTree<string> e = B.consultar_arbre();
    arbre2 = BinTree<string> (a, d, e);
}

//CONSULTORES

int Cluster::consultar_altura(const BinTree<string> b) {
    Cluster a(b);
    if (! a.consultar_arbre().empty()) {
        int left = consultar_altura(a.consultar_arbre().left());
        int right = consultar_altura(a.consultar_arbre().right());
        if(left < right) return 1 + right;
        else return 1 + left;
    } else return 0;
}


/*string Cluster::consultar_idcluster() const{
    return idcluster;
}
*/

BinTree<string> Cluster::consultar_arbre() const{
    return arbre2;
}

int Cluster::mida_cluster() const{
    if (arbre2.empty()) return 0;
    else {
        Cluster aux1(arbre2.left()), aux2(arbre2.right());

        return 1 + aux1.mida_cluster() + aux2.mida_cluster();
    }
}

// LECTURA I ESCRIPTURA


void Cluster::escriu_cluster(int i) const{
        Cluster a;
        if(!arbre2.left().empty()){
            a=Cluster(arbre2.left());
            a.escriu_cluster(i);
        }
        if(!arbre2.right().empty()){
            a=Cluster(arbre2.right());
            a.escriu_cluster(i);
        }
        if (a.consultar_altura(arbre2) == i) {
            cout << "  " <<  arbre2.value();
        } 
}

void Cluster::modificar_distancies(map<string,double> aux) {
    idk = aux;
}

map<string, double> Cluster::consultar_distancies() {
    return idk;
}

void Cluster::write2() {
    map<string,double>::iterator it1 = idk.begin();
    int i = 0;
    while(it1 != idk.end()) {
        cout << it1->first << " (" << it1->second << ")";
        if (i < idk.size()-1) cout << " ";
        ++it1;
        ++i;
    }
}

