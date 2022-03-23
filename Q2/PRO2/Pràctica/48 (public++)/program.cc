#include "Cjt_Clusters.hh"

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    int k;
    cin >> k;
    Cjt_Especies A;
    Cjt_Clusters B;
    string opcio;
    while (cin >> opcio) {
        if (opcio == "crea_especie") {
            string id, g;
            cin >> id >> g;
            cout << "# crea_especie " << id << " " << g << endl;
            if (A.existeix_especie(id)) {
                cout << "ERROR: La especie "<< id << " ya existe." << endl;
            }
            else {
                Especie a(id, g, k);
                A.afegir_especie(a);
            }
            cout << endl;
        }
        else if (opcio == "obtener_gen") {
            string id;
            cin >> id;
            cout << "# obtener_gen " << id << endl;
            A.obtener_gen(id);
            cout << endl;
        }
        else if (opcio == "distancia") {
            string id1, id2;
            cin >> id1 >> id2;
            cout << "# distancia " << id1 << " " << id2 << endl;
            if (not A.existeix_especie(id1) and not A.existeix_especie(id2)) cout << "ERROR: La especie " << id1 << " y la especie " << id2 << " no existen." << endl;
            else if (not A.existeix_especie(id2)) cout << "ERROR: La especie " << id2 << " no existe." << endl;
            else if (not A.existeix_especie(id1)) cout << "ERROR: La especie " << id1 << " no existe." << endl;
            else cout << A.consultar_distancia(id1, id2) << endl;
            cout << endl;

        } 
        else if (opcio == "elimina_especie") {
            string id;
            cin >> id;
            cout << "# elimina_especie " << id << endl;
            A.eliminar_especie(id);
            cout << endl;
        }
        else if (opcio == "existe_especie") {
            string id;
            cin >> id;
            cout << "# existe_especie " << id << endl;
            if (A.existeix_especie(id)) cout << "SI" << endl;
            else cout << "NO" << endl;
            cout << endl;
        } 
        else if (opcio == "lee_cjt_especies") {
            int n;
            cin >> n;
            A.llegir(n, k);
            cout << "# lee_cjt_especies" << endl;
            cout << endl;
            
        }
        else if (opcio == "imprime_cjt_especies") { //falta buidar
            cout << "# imprime_cjt_especies" << endl;
            A.escriu_cjt_especies();
            cout << endl;
        }
        else if (opcio == "tabla_distancias") {
            cout << "# tabla_distancias" << endl;
            A.taula_distancies();
            cout << endl;
        }
        else if (opcio == "inicializa_clusters") {
            cout << "# inicializa_clusters" << endl;
            B.inicialitzar_clusters(A);
            B.write();
            cout << endl;
        }

        else if (opcio == "ejecuta_paso_wpgma") {
            cout << "# ejecuta_paso_wpgma" << endl;
            B.WPGMA();
            if (B.mida_cjt_clusters() > 1) {
                B.write();
            }
            cout << endl;
        }
        else if (opcio == "imprime_cluster") {
            string id;
            cin >> id;
            cout << "# imprime_cluster " << id << endl;
            B.holaqtal(id);
            cout << endl;
        }
        else if (opcio == "imprime_arbol_filogenetico") {
            cout << "# imprime_arbol_filogenetico" << endl;
            B.inicialitzar_clusters(A);
            if (B.mida_cjt_clusters() < 1) cout << "ERROR: El conjunto de clusters es vacio." << endl;
            else {
                while (B.mida_cjt_clusters() > 1) {
                    B.WPGMA();
                }
                Cluster aux = B.consultar_cluster_final();
                B.holaqtal(aux.consultar_arbre().value());
            }
            cout << endl;
        }
        else if (opcio == "fin") {
            break;
        }
    }


}
   