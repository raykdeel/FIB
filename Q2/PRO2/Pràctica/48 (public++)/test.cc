#include "Cjt_Especies.hh"

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    int k, n;
    cin >> k >> n;
    Cjt_Especies A;
    A.llegir(n, k);
    A.escriu_cjt_especies();

}
void Cjt_Especies::afegir_especie(const Especie& a) {
    string s = a.consultar_identificador();
    mesp.insert(make_pair(s, a));
    it = mesp.find(s);
    cout << "aqui1";
    double dist;
    for(map<string,Especie>::iterator it1 = mesp.begin(); it1 != mesp.end(); ++it1) {
        if (it1->first < s) {
            cout << "less";
            map<string,double> aux = it1->second.consultar_distancies();
            dist = consultar_distancia(s, it1->first);
            cout << dist << endl;
            aux.insert(make_pair(s, dist));
            it1->second.modificar_distancies(aux);
            //actualitzar ell mateix
        }
        if (it1->first > s) {
            cout << "more" << it->first;
            map<string,double> aux = it->second.consultar_distancies();
            dist = consultar_distancia(it->first, it1->first);
            cout << dist << endl;
            aux.insert(make_pair(s, dist));
            it->second.modificar_distancies(aux);
            //actualitzar ell mateix
        }
    }
    
}