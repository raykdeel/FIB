#include <iostream>
#include "Cluster.hh"
#include <string>
using namespace std;

//CONSTRUCTORES

Cluster::Cluster(BinTree<Especie> aux) {
    arbre = aux;
}

Cluster::Cluster() {
    arbre;
    idcluster;
}

//MODIFICADORES

void Cluster::modificar_arbre(const BinTree<Especie>& b) {
    arbre = b;
}

void Cluster::modificar_idcl(const Especie& a) {
    idcluster += a.consultar_identificador();
}

Cluster Cluster::fusio_clusters(const Cluster& A, const Cluster& B, const Especie& a) {
    BinTree<Especie> d = A.consultar_arbre();
    BinTree<Especie> e = B.consultar_arbre();
    arbre = BinTree<Especie> (a, d, e);
    return Cluster(arbre);
}

//CONSULTORES

int Cluster::consultar_altura(const BinTree<Especie> b) {
    Cluster a;
    a.modificar_arbre(b);
    if (! a.consultar_arbre().empty()) {
        int left = consultar_altura(a.consultar_arbre().left());
        int right = consultar_altura(a.consultar_arbre().right());
        if(left < right) return 1 + right;
        else return 1 + left;
    } else return 0;
}


string Cluster::consultar_idcluster() const{
    return idcluster;
}

BinTree<Especie> Cluster::consultar_arbre() const{
    return arbre;
}

int Cluster::mida_cluster() const{
    if (arbre.empty()) return 0;
    else {
        Cluster aux1, aux2;
        aux1.modificar_arbre(arbre.left());
        aux2.modificar_arbre(arbre.right());
        return 1 + aux1.mida_cluster() + aux2.mida_cluster();
    }
}

// LECTURA I ESCRIPTURA


void Cluster::escriu_cluster(int i) const{
        Cluster a;
        if(!arbre.left().empty()){
            a=Cluster(arbre.left());
            a.escriu_cluster(i);
        }
        if(!arbre.right().empty()){
            a=Cluster(arbre.right());
            a.escriu_cluster(i);
        }
        if (a.consultar_altura(arbre) == i) {
            cout << "  " <<  arbre.value().consultar_identificador();
        } 
}