#include <iostream>
#include "Cjt_Clusters.hh"
#include <vector>
#include <string>
using namespace std;

 //CONSTRUCTORES

Cjt_Clusters::Cjt_Clusters() {
}

//MODIFICADORES

void Cjt_Clusters::inicialitzar_clusters(const Cjt_Especies T) {
    map<string, Cluster>::iterator it = mclu.begin();
    mclu.erase(it, mclu.end());
    map<string, double>::iterator it1 = distancies.begin();
    distancies.erase(it1,distancies.end());
    map<string, map<string, double>>::iterator it2 = table.begin();
    table.erase(it2, table.end());
    map<string, Especie> aux = T.consultar_mesp();
    for (map<string, Especie>::iterator it1 = aux.begin(); it1 != aux.end(); it1++) { //not vector anymore
        Especie c = it1->second;
        string s = it1->first;
        BinTree<string> b(s);
        table.insert(make_pair(s, c.consultar_distancies())); //no copiar map x map, sino element x element / pair x pair
        Cluster a(b);
        mclu.insert(make_pair(s, a));
    }
}

void Cjt_Clusters::afegir_cluster(const Cluster& A) {
    string s = A.consultar_arbre().value();
    map<string,Cluster>::iterator it = mclu.find(s);
    mclu.insert(make_pair(s, A));
    bool indicador = true;
    recalcular_distancies(indicador, s);
}   

void Cjt_Clusters::eliminar_cluster(Cluster A) {
    string s = A.consultar_arbre().value();
    map<string,Cluster>::iterator it = mclu.find(s);
    if (it != mclu.end()) {
        mclu.erase(s);
        table.erase(s);
        bool indicador = false;
        recalcular_distancies(indicador, s);
    }
    else cout << "ERROR: El cluster " << s << " no existe." << endl;
}

void Cjt_Clusters::WPGMA() {
    if (mclu.size() > 1) {
        pair<string, string> u = dmin();
        map<string,Cluster>::iterator it1 = mclu.find(u.first);
        map<string,Cluster>::iterator it2 = mclu.find(u.second);
        if (it1 != mclu.end() and it2 != mclu.end()) {
            Cluster A = it1->second;
            Cluster B = it2->second;
            string s = u.first + u.second;
            Cluster C;
            C.fusio_clusters(A, B, s);
            afegir_cluster(C);
            eliminar_cluster(A);
            eliminar_cluster(B);
        }
    } else cout << "ERROR: num_clusters <= 1" << endl;
}

//CONSULTORES

int Cjt_Clusters::mida_cjt_clusters() const{
    return mclu.size();
}

Cluster Cjt_Clusters::consultar_cluster_final() {
    map<string,Cluster>::iterator it1 = mclu.begin();
    return it1->second;
}

double Cjt_Clusters::distancia_cluster(Cluster A, Cluster B) {
    double d1 = 0, d2 = 0;
    if (A.mida_cluster() == 1 and B.mida_cluster() == 1) {
        double d = 0;
        string id1 = A.consultar_arbre().value();
        string id2 = B.consultar_arbre().value();
        map<string, map<string, double> >::iterator it3;
        map<string, double>::iterator it2;
        if (id2 < id1) {
            it3 = table.find(id2);
            it2 = it3->second.find(id1);
            d = it2->second;
        } else {
            it3 = table.find(id1);
            it2 = it3->second.find(id2);;
            d = it2->second;
        }
        return d;
    } else {
        string id1 = A.consultar_arbre().value();
        string id2 = B.consultar_arbre().left().value();
        string id3 = B.consultar_arbre().right().value();
        map<string, map<string, double> >::iterator it3 = table.begin();
        map<string, double>::iterator it2 = it3->second.begin();
        if (id2 < id1) {
            it3 = table.find(id2);
            if (it3 != table.end()) {
                it2 = it3->second.find(id1);
                if (it2 != it3->second.end()) {
                    d1 = it2->second;
                }
            }
        } else {
            it3 = table.find(id1);
            if (it3 != table.end()) {
                it2 = it3->second.find(id2);
                if (it2 != it3->second.end()) {
                    d1 = it2->second;
                }
            }
        }
        if (id3 < id1) {
            it3 = table.find(id3);
            if (it3 != table.end()) {
                it2 = it3->second.find(id1);
                if (it2 != it3->second.end()) {
                    d2 = it2->second;
                }
            }
        } else {
            it3 = table.find(id1);
            if (it3 != table.end()) {
                it2 = it3->second.find(id3);
                if (it2 != it3->second.end()) {
                    d2 = it2->second;
                }
            }
        }   
    } 
    return (d1+d2) / 2;
}

void Cjt_Clusters::recalcular_distancies(bool indicador, string id) {
    if (indicador) {
        map<string,Cluster>::iterator it = mclu.find(id);
        double dist;
        map<string, double> aux;
        table.insert(make_pair(id, aux));
        for(map<string, map<string, double> >::iterator it3 = table.begin(); it3 != table.end(); ++it3) { //NO mclu.end -> it
            map<string, double>::iterator it4 = it3->second.begin();
            map<string,Cluster>::iterator it1 = mclu.find(it3->first);
            if (it3->first < id) {
                if(it->second.consultar_arbre().left().value() != it3->first and it->second.consultar_arbre().right().value() != it3->first) {
                    dist = distancia_cluster(it1->second, it->second);
                    it3->second.insert(make_pair(id, dist));
                }
            }            
            if (it3->first > id) {
                if (it->second.consultar_arbre().left().value() != it1->first and it->second.consultar_arbre().right().value() != it1->first) {
                    dist = distancia_cluster(it1->second, it->second);
                    map<string, map<string, double> >::iterator it5 = table.find(id);  
                    it5->second.insert(make_pair(it1->first, dist));                         
                }
            }
        }
    } else {
        map<string, map<string, double> >::iterator it3 = table.begin();
        map<string,Cluster>::iterator it1 = mclu.begin();
        map<string,Cluster>::iterator it = mclu.find(id);
        while (it1 != it) {
            it3->second.erase(id);
            ++it1;
            ++it3;
        }
    }
}

void Cjt_Clusters::write() {
    int i = 0;
    for (map<string, map<string, double> >::iterator it1 = table.begin(); it1 != table.end(); ++it1) {
        cout << it1->first << ":";
        if (i < table.size()-1) cout << " ";
        map<string, double>::iterator it2 = it1->second.begin();
        int j = 0;
        while (it2 != it1->second.end()) {
            cout << it2->first << " (" << it2->second << ")";
            if (j < it1->second.size() - 1) cout << " ";
            ++it2;
            ++j;
        }
        
        ++i;
        cout << endl;
    }
}
pair<string, string> Cjt_Clusters::dmin(){
    pair<string, string> minimal_dist;
    double d = 0;
    bool firsttime = true;
    for (map<string, map<string, double> >::iterator it1 = table.begin(); it1 != table.end(); ++it1) {
        if (not it1->second.empty()) {
            for (map<string, double>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
                if (firsttime) {
                    minimal_dist.first = it1->first;
                    minimal_dist.second = it2->first;
                    d = it2->second;
                    firsttime = false;
                }
                else {
                    if (it2->second <= d) {
                        if (it2->second == d) {
                            if (it1->first < minimal_dist.first) {
                                minimal_dist.first = it1->first;
                                minimal_dist.second = it2->first;
                                d = it2->second;
                            }
                        } else {
                            minimal_dist.first = it1->first;
                            minimal_dist.second = it2->first;
                            d = it2->second;
                        }

                    }              
                }
            }
        }
    }
    distancies.insert(make_pair(minimal_dist.first+minimal_dist.second, d/2));
    distancies.insert(make_pair(minimal_dist.first, 0));
    distancies.insert(make_pair(minimal_dist.second, 0));
    return minimal_dist;
}

void Cjt_Clusters::holaqtal2(Cluster a){
    cout << "[";
    string s = a.consultar_arbre().value();
    if (a.mida_cluster() > 1) {
        map<string, double>::iterator it2 = distancies.find(s);
        cout << "(" << s << ", ";
        cout << it2->second << ") ";
        holaqtal2(a.consultar_arbre().left());
        holaqtal2(a.consultar_arbre().right());
        cout << "]";
    } else cout << s << "]";;
}

void Cjt_Clusters::holaqtal(string id) {
    map<string, Cluster>::iterator it1 = mclu.find(id);
    if (it1 != mclu.end()) {
        holaqtal2(it1->second);
        cout << endl;
    } else cout << "ERROR: El cluster " << id << " no existe." << endl;
}