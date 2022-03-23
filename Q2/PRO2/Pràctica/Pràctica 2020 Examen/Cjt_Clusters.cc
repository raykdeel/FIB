/** @file Cjt_Clusters.cc
    @brief Implementació de la classe Cjt_Clusters 
*/
#include "Cjt_Clusters.hh"
#include <cmath>
using namespace std;

//CONSTRUCTORA

Cjt_Clusters::Cjt_Clusters() {
}

//MODIFICADORES

void Cjt_Clusters::add_cluster(const Cluster& A, string id) {
    mclu.insert(make_pair(id, A));
    bool indicador = true;
    clusters_distance_update(indicador, id);
}   

void Cjt_Clusters::erase_cluster(Cluster A) {
    string id = A.query_cluster_id();
    mclu.erase(id);
    table_clusters.erase(id);
    bool indicador = false;
    clusters_distance_update(indicador, id);
}

void Cjt_Clusters::initialize_clusters(Cjt_Especies& A) {
    if (mclu.size() != 0) {
        mclu.erase(mclu.begin(), mclu.end());
        table_clusters.erase(table_clusters.begin(), table_clusters.end());
    }
    int i = 0;
    while (i < A.species_set_size()) {
        string id = A.returnid(i);
        Cluster a(id, 0);
        mclu.insert(make_pair(id, a));
        ++i;
    }
    for (mclu_iterator it = mclu.begin(); it != mclu.end(); ++it) {
        map<string, double> aux;
        double x = 0;
        for (mclu_iterator it1 = it; it1 != mclu.end(); ++it1) {
            if (it->first != it1->first) {
                x = A.returndist(it->first, it1->first);
                aux.insert(make_pair(it1->first, x));
            }
        }
        table_clusters.insert(make_pair(it->first, aux));
    }
}

void Cjt_Clusters::wpgma_algorithm() {
    double x;
    pair<string, string> u = dmin(x);
    mclu_iterator it1 = mclu.find(u.first);
    mclu_iterator it2 = mclu.find(u.second);
    if (it1 != mclu.end() and it2 != mclu.end()) {
        Cluster A = it1->second;
        Cluster B = it2->second;
        string id = u.first + u.second;
        Cluster C;
        C.clusters_fusion(A, B, id, x);
        add_cluster(C, id);
        erase_cluster(A);
        erase_cluster(B);
    }
}

double Cjt_Clusters::cluster_distance(Cluster A, Cluster B) {
    double d1 = 0, d2 = 0;
    pair<string, string> aux = B.query_cluster_sub_id();
    string id1 = A.query_cluster_id(), id2 = aux.first, id3 = aux.second;
    if (id2 != id1 and id3 != id1) {
        table_clusters_iterator it3 = table_clusters.begin();
        table_clusters_column_iterator it2 = it3->second.begin();
        if (id2 < id1) {
            it3 = table_clusters.find(id2);
            it2 = it3->second.find(id1);
            d1 = it2->second;
        } else {
            it3 = table_clusters.find(id1);
            it2 = it3->second.find(id2);
            d1 = it2->second;
        }
        if (id3 < id1) {
            it3 = table_clusters.find(id3);
            it2 = it3->second.find(id1);
            d2 = it2->second;            
        } else {
            it3 = table_clusters.find(id1);
            it2 = it3->second.find(id3);
            d2 = it2->second;                
        }   
    }


    BinTree<pair<string, double>> aux14 = B.arbre();
    double x = 2 * aux14.value().second;
    int m1 = A.mida(), m2 = B.mida();
    double first1 = (d1 * m1);
    double first2 = (d2 * m2);
    double y = m1 + m2;
    double second1 = first1+first2;
    double second2 = second1 / y;
    double third = m1 * m2;
    double fourth = pow(y, 2);
    double fifth = third / fourth;
    double sixth = fifth * x;
    return second2 - sixth;
      
    // return (d1+d2) / 2;    
}

void Cjt_Clusters::clusters_distance_update(bool indicador, string id) {
    if (indicador) {
    mclu_iterator it = mclu.find(id);
    double dist;
    map<string, double> aux;
    table_clusters.insert(make_pair(id, aux));
    for(map<string, map<string, double>>::iterator it3 = table_clusters.begin(); it3 != table_clusters.end(); ++it3) {
        table_clusters_column_iterator it4 = it3->second.begin();
        mclu_iterator it1 = mclu.find(it3->first);
        if (it1 != mclu.end()) {
            if (it3 != table_clusters.end()) {
                string s = it3->first;
                if (s < id) {
                    dist = cluster_distance(it1->second, it->second);
                    it3->second.insert(make_pair(id, dist));
                }                    
                s = it1->first;        
                if (s > id) {
                    dist = cluster_distance(it1->second, it->second);
                    map<string, map<string, double>>::iterator it5 = table_clusters.find(id);  
                    if (it5 != table_clusters.end()) {
                        it5->second.insert(make_pair(it1->first, dist));
                    }                     
                }
            }
        }
    }
    } else {
        map<string, map<string, double>>::iterator it3 = table_clusters.begin();
        mclu_iterator it1 = mclu.begin();
        mclu_iterator it = mclu.find(id);
        while (it1 != it) {
            if (it3 != table_clusters.end()) {
                it3->second.erase(id);
                ++it1;
                ++it3;
            }
        }
    }
}

pair<string, string> Cjt_Clusters::dmin(double& d){
    pair<string, string> minimal_dist;
    d = 101;
    for (table_clusters_iterator it1 = table_clusters.begin(); it1 != table_clusters.end(); ++it1) {
        for (table_clusters_column_iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
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
    d /= 2;
    return minimal_dist;
}

//CONSULTORES

bool Cjt_Clusters::cluster_exist(string id) {
    mclu_iterator it = mclu.find(id);
    return it != mclu.end();
}

int Cjt_Clusters::clusters_set_size() const{
    return mclu.size();
}

//ESCRIPTURA

void Cjt_Clusters::find_print_cluster(string id) {
    mclu_iterator it = mclu.find(id);
    Cluster aux = it->second;
    aux.print_cluster();
}

void Cjt_Clusters::print_final_cluster() {
    mclu_iterator it = mclu.begin();
    Cluster aux = it->second;
    aux.print_cluster();
}

void Cjt_Clusters::print_table_clusters() {
    if (mclu.size() != 0) {
        int i = 0;
        for (table_clusters_iterator it1 = table_clusters.begin(); it1 != table_clusters.end(); ++it1) {
            cout << it1->first << ":";
            if (i < table_clusters.size()-1) cout << " ";
            table_clusters_column_iterator it2 = it1->second.begin();
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
}



