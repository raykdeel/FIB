/** @file Cluster.cc
    @brief Implementació de la classe Cluster 
*/
#include "Cluster.hh"
using namespace std;

//CONSTRUCTORES

Cluster::Cluster() {
}

Cluster::Cluster(string id, double x) {
    pair<string, double> y;
    y.first = id;
    y.second = x;
    tree = BinTree<pair<string, double>> (y);

}

//MODIFICADORES

void Cluster::clusters_fusion(const Cluster& A, const Cluster& B, string a, double x) {
    pair<string, double> y(a, x);
    tree = BinTree<pair<string, double> > (y, A.tree, B.tree);
    midacl += 1;
}

//CONSULTORES

string Cluster::query_cluster_id() const {
    return tree.value().first;
}

pair<string, string> Cluster::query_cluster_sub_id() const {
    return pair<string, string> (tree.right().value().first, tree.left().value().first);
}

int Cluster::mida() const {
    return midacl;
}

BinTree<pair<string, double>>  Cluster::arbre() const {
    return tree;
}
//ESCRIPTURA

void Cluster::print_cluster() {
    print_tree(tree);
}

void Cluster::print_tree(const BinTree<pair<string, double>> a){
    cout << "[";
    string id = a.value().first;
    double dist = a.value().second;
    if (not a.left().empty() and not a.right().empty()) {
        cout << "(" << id << ", ";
        cout << dist << ") ";
        print_tree(a.left());
        print_tree(a.right());
        cout << "]";
    } else cout << id << "]";;
}
