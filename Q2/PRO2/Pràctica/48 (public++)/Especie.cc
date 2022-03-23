#include "Especie.hh"
using namespace std;

Especie::Especie() {
}

Especie::Especie(string id, string g, int k) {
    identificador = id;
    gen = g;
    kmer_def = kmer(gen, k);
}

void Especie::llegir(int k) {
    cin >> identificador >> gen;
    kmer_def = kmer(gen, k);
}

void Especie::escriu() const { //NECESSARY?
    //cout << identificador << " " << gen << endl;
    for(map<string, int>::const_iterator it2 = kmer_def.begin(); it2 != kmer_def.end(); ++it2) {
        cout << it2->first << " " << it2->second << endl;
    }
}
void Especie::modificar_id(string id) {
        identificador = id;
}

string Especie::consultar_identificador() const{
    return identificador;
}

string Especie::consultar_gen() const{
    return gen;
}

map<string, int> Especie::consultar_kmer() {
    return kmer_def;
}

map<string, double> Especie::consultar_distancies() {
    return distancies;
}

void Especie::modificar_distancies(map<string,double> aux) {
    distancies = aux;
}

void Especie::escriu_dist() {
    map<string,double>::iterator it1 = distancies.begin();
    int i = 0;
    while(it1 != distancies.end()) {
        cout << it1->first << " (" << it1->second << ")";
        if (i < distancies.size()-1) cout << " ";
        ++it1;
        ++i;
    }
}

map<string, int> Especie::kmer(string g, int k) {
    map<string, int> aux;
    int max = g.length() - k + 1;
    vector<string> v(max);
    for (int j = 0; j < max; ++j) {
        for (int i = j; i < k; ++i) {
            v[j] += g[i]; //comprovar que g[i] == 'A' or 'T' or 'C' or 'G'
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

