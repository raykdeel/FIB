/** @file Cjt_Especies.cc
    @brief Implementació de la classe Cjt_Especies 
*/
#include "Cjt_Especies.hh"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

//CONSTRUCTORES

Cjt_Especies::Cjt_Especies() {
}

//MODIFICADORESS

void Cjt_Especies::add_species(const Especie& a) {
    string id = a.query_identifier();
    mesp.insert(make_pair(id, a));
    bool indicador = true;
    species_distance_update(indicador, id);    
}

void Cjt_Especies::erase_species(string id) {
    bool indicador = false;
    species_distance_update(indicador, id);
    mesp.erase(id);
    table_species.erase(id);
}

void Cjt_Especies::initialize_distances() {
    for(map<string,Especie>::iterator it1 = mesp.begin(); it1 != mesp.end(); ++it1) {
        map<string, double> aux;
        double dist;
        for(map<string,Especie>::iterator it2 = it1; it2 != mesp.end(); ++it2) {
            if (it1 != it2) {
                dist = species_distance(it1->first, it2->first);
                aux.insert(make_pair(it2->first, dist));
            }
            
        }
        string id = it1->first;
        table_species.insert(make_pair(id, aux));
    }
}

void Cjt_Especies::species_distance_update(bool indicador, string id) {
    if (indicador) {
        map<string,Especie>::iterator it = mesp.find(id);
        double dist;
        map<string, double> aux;
        table_species.insert(make_pair(id, aux));
        for(map<string, map<string, double>>::iterator it3 = table_species.begin(); it3 != table_species.end(); ++it3) {
            table_species_column_iterator it4 = it3->second.begin();
            map<string, Especie>::iterator it1 = mesp.find(it3->first);
            if (it1 != mesp.end()) {
                string s = it3->first;
                if (s < id) {
                    dist = species_distance(id, s);                        
                    it3->second.insert(make_pair(id, dist));
                }
                if (s > id) {
                    dist = species_distance(s, it->first);
                    map<string, map<string, double>>::iterator it5 = table_species.find(id);
                    if (it5 != table_species.end()) {                            
                        it5->second.insert(make_pair(it1->first, dist));
                    }
                }
            }
        } 
    } else {
        map<string, map<string, double>>::iterator it3 = table_species.begin();
        map<string, Especie>::iterator it1 = mesp.begin();
        map<string,Especie>::iterator it = mesp.find(id);
        while (it1 != it) {
            if (it3 != table_species.end()) {
                it3->second.erase(id);
                ++it1;
                ++it3;
            }        
        }
    }
}

double Cjt_Especies::species_distance(string id1, string id2){
    if (id1 == id2) return 0;
    map<string,Especie>::iterator it = mesp.find(id1);
    Especie a = it->second;
    it = mesp.find(id2);
    Especie b = it->second;
    map<string,int> k1;
    map<string,int> k2;
    map<string,int>::const_iterator it1;
    map<string,int>::const_iterator it2;
    k1 = a.query_kmer();
    k2 = b.query_kmer();
    // it1 = k1.begin(), it2 = k2.begin();
    double up = 0, downk1 = 0, downk2 = 0, down = 0;
    map<string,int>::const_iterator it3 = k2.begin();
    for (it1 = k1.begin(); it1 != k1.end(); ++it1) {
    for (it2 = k2.begin(); it2 != k2.end(); ++it2) {
        if (it1->first == it2->first) {
            up += (it1->second * it2->second);
        }
    }
    }
    for (it1 = k1.begin(); it1 != k1.end(); ++it1) {
        downk1 += pow(it1->second, 2);
    }
    for (it2 = k2.begin(); it2 != k2.end(); ++it2) {
        downk2 += pow(it2->second, 2);
    }
    downk1 = sqrt(downk1);
    downk2 = sqrt(downk2);
    down = downk1 * downk2;
    // cout << down;
    double almost = up / down;
    double pi = 3.14159265358979323846264338327950288419716939937510582097;
    double almost2 = acos(almost);
    double almost3 = 1 / pi;
    double almost4 = almost3*almost2;
    double almost5 = 1 - almost4;
    return almost5*100;

    /*while (it1 != k1.end() and it2 != k2.end()) {
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
    */
    // return (1 - (ig / (total-ig))) * 100;
}

//CONSULTORES

string Cjt_Especies::returnid(int i) {
    if (i == 0) {
        it = mesp.begin();
    } else {
        ++it;
    }
    return it->first;
}

double Cjt_Especies::returndist(const string id1, const string id2) {
    table_species_iterator it1 = table_species.find(id1);
    table_species_column_iterator it2 = it1->second.find(id2);
    return it2->second;
}

int Cjt_Especies::species_set_size() const{
    return mesp.size();
}

bool Cjt_Especies::species_exist(string id) {
    map<string,Especie>::iterator it = mesp.find(id);
    return it != mesp.end();
}

Especie Cjt_Especies::find_species(string id) {
    map<string,Especie>::iterator it = mesp.find(id);
    return it->second;
}

//LECTURA I ESCRIPTURA

void Cjt_Especies::read_species(int n, int k) {
    if (mesp.size() != 0) {
        mesp.erase(mesp.begin(), mesp.end());
        table_species.erase(table_species.begin(), table_species.end());
    }
    Especie aux;
    int i = 0; 
    while (i < n) {
        aux.read_single_species(k);
        string id = aux.query_identifier();
        mesp.insert(make_pair(id, aux));
        ++i;
    }
    initialize_distances();
}

void Cjt_Especies::print_species() {
    map<string,Especie>::iterator it = mesp.begin();
    while(it != mesp.end()) {
        cout << it->first << " " << it->second.query_gene() << endl;
        ++it;
    }
}

void Cjt_Especies::print_table_species() {
    if (mesp.size() != 0) {
        int i = 0;
        for(table_species_iterator it1 = table_species.begin(); it1 != table_species.end(); ++it1) {
            cout << it1->first << ":";
            if(i < mesp.size()-1) cout << " ";
            table_species_column_iterator it2 = it1->second.begin();
            int j = 0;
            while(it2 != it1->second.end()) {
                cout << it2->first << " (" << it2->second << ")";
                if(j < it1->second.size()-1) cout << " ";
                ++it2;
                ++j;
            }
            ++i;
            cout << endl;
        }
    }
}

