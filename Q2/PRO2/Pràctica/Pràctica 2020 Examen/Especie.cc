/** @file Especie.cc
    @brief Implementació de la classe Especie 
*/
#include "Especie.hh"
using namespace std;

//CONSTRUCTORES

Especie::Especie() {
}

Especie::Especie(string id, string g, int k) {
    identifier = id;
    gene = g;
    kmer = create_kmer(gene, k);
}

//MODIFICADORES

map<string, int> Especie::create_kmer(string g, int k) {
    map<string, int> aux;
    int max = g.length() - k + 1;
    vector<string> v(max);
    for (int j = 0; j < max; ++j) {
        for (int i = j; i < k; ++i) {
            v[j] += g[i];
        } 
        ++k;
    }
    map<string, int>::const_iterator it1;
    for (int i = 0; i < max; ++i) {
        string s = v[i];
       it1 = aux.find(s);
       if (it1 == aux.end()) aux.insert(make_pair(s, 1));
       else aux[s] = it1->second + 1;
    }
    return aux;
}

//CONSULTORES

string Especie::query_identifier() const{
    return identifier;
}

string Especie::query_gene() const{
    return gene;
}

map<string, int> Especie::query_kmer() {
    return kmer;
}

//LECTURA

void Especie::read_single_species(int k) {
    cin >> identifier >> gene;
    kmer = create_kmer(gene, k);
}



