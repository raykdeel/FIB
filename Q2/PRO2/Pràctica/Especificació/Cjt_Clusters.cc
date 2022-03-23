#include <iostream>
#include "Cjt_Clusters.hh"
#include <vector>
#include <string>
using namespace std;

 //CONSTRUCTORES

Cjt_Clusters::Cjt_Clusters() {
    ncluster = 0;
}

//MODIFICADORES

void Cjt_Clusters::inicialitzar_clusters(const Cjt_Especies T) {
    for (int i = 0; i < T.consultar_vector().size(); ++i) {
        Especie c = T.consultar_vector()[i];
        Cluster a;
        a.modificar_idcl(c);
        BinTree<Especie> d(c);
        a.modificar_arbre(d);
        vecl.push_back(a);
        ++ncluster;
    }
}

void Cjt_Clusters::afegir_cluster(const Cluster& A) {
    vecl.push_back(A);
    ++ncluster;
}   

void Cjt_Clusters::eliminar_cluster(Cluster A) {
    bool here = false;
    int i = 0;
    while (i < ncluster and not here) {
        if(vecl[i].consultar_idcluster() == A.consultar_idcluster()) {
            here = true;
        }
        i++;
    }
    if (here) {
        for (int j = i; j < ncluster; j++) {
                vecl[j-1] = vecl[j];
        }
        ncluster--;
        vecl.pop_back();
    }
}

void Cjt_Clusters::WPGMA(int k, Cjt_Especies T) {
    cout << "WPGMA" << endl;
    vector<double> distancies(1, 0);
    while (ncluster > 1) {
        int x,y;
        dist_min(k, T, x, y); //treure x, y
        Cluster A = vecl[x];
        Cluster B = vecl[y];
        distancies.push_back(distancia_cluster(A, B, k, T));
        Especie aux;
        Cluster C;
        string s1, s2;
        if (A.mida_cluster() > 1) {
            s1 = A.consultar_arbre().value().consultar_identificador();
        } else s1 = A.consultar_idcluster();
        if (B.mida_cluster() > 1) {
            s2 = B.consultar_arbre().value().consultar_identificador();
        } else s2 = B.consultar_idcluster();
        if (s1 < s2) {
            aux.modificar_id(s1+s2);
            C.fusio_clusters(A, B, aux);
        } else {
            aux.modificar_id(s2+s1);
            C.fusio_clusters(B, A, aux);
        }
        afegir_cluster(C);
        eliminar_cluster(A);
        eliminar_cluster(B);
        escriu_taulac(k, T);
    }        
    escriu_arbre(k, distancies);
}


//CONSULTORES

int Cjt_Clusters::mida_cjt_clusters() const{
    return ncluster;
}

double Cjt_Clusters::distancia_cluster(Cluster A, Cluster B, int& k, Cjt_Especies T) {
    double d1 = 0, d2 = 0;
    if (A.mida_cluster() == 1 and B.mida_cluster() == 1) {
        Especie d = A.consultar_arbre().value();
        Especie e = B.consultar_arbre().value();
        string id1 = d.consultar_identificador();
        string id2 = e.consultar_identificador();
        return T.consultar_distancia(id1, id2, k);
    } else if (A.mida_cluster() == 1 and B.mida_cluster() > 1) {
        d1 = distancia_cluster(B.consultar_arbre().left(), A, k, T);
        d2 = distancia_cluster(B.consultar_arbre().right(), A, k, T);
    } else if (A.mida_cluster() > 1 and B.mida_cluster() == 1) {
        d1 = distancia_cluster(A.consultar_arbre().left(), B, k, T);
        d2 = distancia_cluster(A.consultar_arbre().right(), B, k, T);
    } else {
        d1 = distancia_cluster(A.consultar_arbre(), B.consultar_arbre().left(), k, T); //poder no fa falta
        d2 = distancia_cluster(A.consultar_arbre(), B.consultar_arbre().right(), k, T);

    }
    return (d1+d2) / 2;
}

void Cjt_Clusters::dist_min(int k, Cjt_Especies T, int& x, int& y) {
    bool first = true;
    double dist;
    string s;
    for (int i = 0; i < ncluster; ++i) { //ncluster
        for (int j = ncluster - 1; j > i; --j) {
            if (not first) {
                if (distancia_cluster(vecl[i], vecl[j], k, T) <= dist) {
                    if (distancia_cluster(vecl[i], vecl[j], k, T) == dist) {
                        if (vecl[i].consultar_idcluster() + vecl[j].consultar_idcluster() < s) {
                            dist = distancia_cluster(vecl[i], vecl[j], k, T);
                            x = i, y = j;
                            s = vecl[i].consultar_idcluster() + vecl[j].consultar_idcluster();
                        }
                    } else {
                    dist = distancia_cluster(vecl[i], vecl[j], k, T);
                    x = i, y = j;
                    
                    }
                }
            }
            if (first) {
                dist = distancia_cluster(vecl[i], vecl[j], k, T);
                x = i, y = j;
                s = vecl[i].consultar_idcluster() + vecl[j].consultar_idcluster();
                first = false;
            }
        }
    }
}


// LECTURA I ESCRIPTURA

void Cjt_Clusters::imprimir_cluster(string id) {
    vector<Cluster> aux;
    int i = 0;
    bool found = false;
    while (i < ncluster and not found) {
        if (vecl[i].consultar_idcluster() == id or vecl[i].consultar_arbre().value().consultar_identificador() == id) {
            found = true;
            aux.push_back(vecl[i]);
        }
        ++i;
    }
    if (found) {
    Cluster a;
    for (int j = 1; j <= a.consultar_altura(a.consultar_arbre()); ++j) {
        a.escriu_cluster(j);
        cout << endl;
    }

    } else cout << "NO EXISTEIX CAP CLUSTER AMB L'IDENTIFICADOR " << id << endl;
}

void Cjt_Clusters::escriu_arbre(int k, vector<double> distancies) {
    cout << "ARBRE FILOGENÈTIC :" << endl;
    Cluster aux;
    cout.setf(ios::fixed);
	cout.precision(1);
    aux = Cluster(vecl[0].consultar_arbre());
    bool first= true;
    for (int i = 1; i <= aux.consultar_altura(aux.consultar_arbre()); ++i) {
        cout << distancies[i-1] << "    ";
        aux.escriu_cluster(i);
        cout << endl;

    }
}




void Cjt_Clusters::escriu_taulac(int k, Cjt_Especies T) {
    cout << "TAULA CLUSTERS :" << endl;
    cout << "   ";
    for (int i = 0; i < ncluster; ++i) {
        if (vecl[i].mida_cluster() > 1) {
            cout << vecl[i].consultar_arbre().value().consultar_identificador() << "    ";
        } else cout << vecl[i].consultar_idcluster() << "    "; 
    }
    cout << endl;
    for (int i = 0; i < ncluster; ++i) {
        if (vecl[i].mida_cluster() > 1) {
        cout << vecl[i].consultar_arbre().value().consultar_identificador();
        cout << " ";
        } else cout << vecl[i].consultar_idcluster() << " ";
        for (int j = 0; j < ncluster; ++j) {
            if (i == j) cout << "0.000" << " ";
            else cout << distancia_cluster(vecl[i], vecl[j], k, T) << "  ";
        }
        cout << endl;
    }
}

