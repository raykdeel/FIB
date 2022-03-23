/** @file Especie.cc
    @brief Implementació de la classe Especie 
*/
#include "Especie.hh"
using namespace std;

Especie::Especie() {
}

Especie::Especie(string id, string g, int k) {
    identifier = id;
    gene = g;
    kmer = create_kmer(gene, k);
}

/*
void Especie::modify_distances(map<string,double> aux) {
    species_distances = aux;
}
*/

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

string Especie::query_identifier() const{
    return identifier;
}

string Especie::query_gene() const{
    return gene;
}

map<string, int> Especie::query_kmer() {
    return kmer;
}

/*map<string, double> Especie::query_distances() {
    return species_distances;
}
*/

void Especie::read_single_species(int k) {
    cin >> identifier >> gene;
    kmer = create_kmer(gene, k);
}

/*
void Especie::print_species_distances() {
    map<string,double>::iterator it1 = species_distances.begin();
    int i = 0;
    while(it1 != species_distances.end()) {
        cout << it1->first << " (" << it1->second << ")";
        if (i < species_distances.size()-1) cout << " ";
        ++it1;
        ++i;
    }
}
*/


