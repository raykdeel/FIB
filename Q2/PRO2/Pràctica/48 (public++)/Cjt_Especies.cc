#include <vector>
#include "Cjt_Especies.hh"
using namespace std;

Cjt_Especies::Cjt_Especies() {
}

void Cjt_Especies::obtener_gen(string id){
    it = mesp.find(id);
    if (it != mesp.end()) {
        cout << it->second.consultar_gen() << endl;
    }
    else cout << "ERROR: La especie "<< id << " no existe." << endl;
}

void Cjt_Especies::afegir_especie(const Especie& a) {
    string id = a.consultar_identificador();
    mesp.insert(make_pair(id, a));
    bool indicador = true;
    recalcular_distancies(indicador, id);
      
}

void Cjt_Especies::recalcular_distancies(bool indicador, string id) {
    map<string,Especie>::iterator it3 = mesp.find(id);
    if (indicador) {
        double dist;
        for(map<string,Especie>::iterator it1 = mesp.begin(); it1 != mesp.end(); ++it1) {
            if (it1->first < id) {
                map<string,double> aux = it1->second.consultar_distancies();
                dist = consultar_distancia(id, it1->first);
                aux.insert(make_pair(id, dist));
                it1->second.modificar_distancies(aux);
            }
            if (it1->first > id) {
                map<string,double> aux = it3->second.consultar_distancies();
                dist = consultar_distancia(it1->first, it3->first);
                aux.insert(make_pair(it1->first, dist));
                it3->second.modificar_distancies(aux);
            }
        } 
    } else {
        map<string,Especie>::iterator it1 = mesp.begin();
        while (it1 != it3) {
            map<string,double> aux = it1->second.consultar_distancies();
            aux.erase(id);
            it1->second.modificar_distancies(aux);
            ++it1;
        }

    }
}

void Cjt_Especies::eliminar_especie(string id) {
    map<string,Especie>::iterator it = mesp.find(id);
    if (it != mesp.end()) {
        bool indicador = false;
        recalcular_distancies(indicador, id);
        mesp.erase(id);
    }
    else cout << "ERROR: La especie " << id << " no existe." << endl;
}

map<string, Especie> Cjt_Especies::consultar_mesp() const {
    return mesp;
}

bool Cjt_Especies::existeix_especie(string id) {
    it = mesp.find(id);
    if (it != mesp.end()) {
        return true;
    }
    else return false;
}

double Cjt_Especies::consultar_distancia(string id1, string id2){
    if (id1 == id2) return 0;
    it = mesp.find(id1);
    Especie a = it->second;
    it = mesp.find(id2);
    Especie b = it->second;
    map<string,int> k1;
    map<string,int> k2;
    map<string,int>::const_iterator it1;
    map<string,int>::const_iterator it2;
    k1 = a.consultar_kmer();
    k2 = b.consultar_kmer();
    double ig = 0, total = 0;
    it1 = k1.begin(), it2 = k2.begin();
    while (it1 != k1.end() and it2 != k2.end()) {
        if (it1->first < it2->first) {
            total += it1->second;
            ++it1;
        }
        else if (it2->first < it1->first) {
            total += it2->second;
            ++it2;
        }
        else {
            ig += min(it1->second, it2->second);
            total += it2->second;
            total += it1->second;
            ++it1;
            ++it2;
        }
    }
    while (it1 != k1.end()) {
        total += it1->second;
        ++it1;
    }
    while (it2 != k2.end()) {
        total += it2->second;
        ++it2; 
    }
    return (1 - (ig / (total-ig))) * 100;
}

void Cjt_Especies::actualitzar_distancies() {
    for(map<string,Especie>::iterator it1 = mesp.begin(); it1 != mesp.end(); ++it1) {
        map<string, double> aux;
        double dist;
        for(map<string,Especie>::iterator it2 = it1; it2 != mesp.end(); ++it2) { //menys iteracions?
            if (it1 != it2) {
                dist = consultar_distancia(it1->first, it2->first);
                aux.insert(make_pair(it2->first, dist));
            }
        }
        it1->second.modificar_distancies(aux);
    }
}

void Cjt_Especies::llegir(int n, int k) {//FALTA COMPROVAR
    it = mesp.begin();
    mesp.erase(it, mesp.end());
    Especie aux;
    int i = 0; 
    while (i < n) {
        aux.llegir(k);
        string s = aux.consultar_identificador();
        it = mesp.find(s); ////^?¿?¿
        mesp.insert(make_pair(s, aux));
        ++i;
    }
    actualitzar_distancies();   
}

void Cjt_Especies::escriu_cjt_especies() {
    it = mesp.begin();
    while(it != mesp.end()) {
        cout << it->first << " " << it->second.consultar_gen() << endl;
        ++it;
    }
}

void Cjt_Especies::taula_distancies() {
    int i = 0;
    for(map<string,Especie>::iterator it1 = mesp.begin(); it1 != mesp.end(); ++it1) {
        cout << it1->first << ":";
        if (i < mesp.size()-1) cout << " ";
        it1->second.escriu_dist();
        ++i;
        cout << endl;
    }
}
