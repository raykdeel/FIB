//Ricard Guixaró Trancho (Grup 30/33)

/**
 *  @mainpage Pràctica (Primavera 2020).

En aquesta pràctica es crea un arbre filogenètic que reflexa la hipotètica evolució
de varies espècies. S'introdueixen les classes <em>Especie</em>, <em>Cjt_Especies</em>,
<em>Cluster</em> i  <em>Cjt_Clusters</em>.

*/

/** @file program.cc
    @brief Programa principal de la pràtica.
*/

#include "Cjt_Clusters.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif

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
            if (A.species_exist(id)) {
                cout << "ERROR: La especie "<< id << " ya existe." << endl;
            }
            else {
                Especie a(id, g, k);
                A.add_species(a);
            }
            cout << endl;
        }
        else if (opcio == "obtener_gen") {
            string id;
            cin >> id;
            cout << "# obtener_gen " << id << endl;
            if (A.species_exist(id)) {
                Especie a = A.find_species(id);
                cout << a.query_gene() << endl;
            }
            else cout << "ERROR: La especie "<< id << " no existe." << endl;
            cout << endl;
        }
        else if (opcio == "distancia") {
            string id1, id2;
            cin >> id1 >> id2;
            cout << "# distancia " << id1 << " " << id2 << endl;
            if (not A.species_exist(id1) and not A.species_exist(id2)) cout << "ERROR: La especie " << id1 << " y la especie " << id2 << " no existen." << endl;
            else if (not A.species_exist(id2)) cout << "ERROR: La especie " << id2 << " no existe." << endl;
            else if (not A.species_exist(id1)) cout << "ERROR: La especie " << id1 << " no existe." << endl;
            else cout << A.species_distance(id1, id2) << endl;
            cout << endl;

        } 
        else if (opcio == "elimina_especie") {
            string id;
            cin >> id;
            cout << "# elimina_especie " << id << endl;
            if (A.species_exist(id)) {
                A.erase_species(id);
            } else cout << "ERROR: La especie " << id << " no existe." << endl;

            cout << endl;
        }
        else if (opcio == "existe_especie") {
            string id;
            cin >> id;
            cout << "# existe_especie " << id << endl;
            if (A.species_exist(id)) cout << "SI" << endl;
            else cout << "NO" << endl;
            cout << endl;
        } 
        else if (opcio == "lee_cjt_especies") {
            int n;
            cin >> n;
            A.read_species(n, k);
            cout << "# lee_cjt_especies" << endl;
            cout << endl;
            
        }
        else if (opcio == "imprime_cjt_especies") {
            cout << "# imprime_cjt_especies" << endl;
            A.print_species();
            cout << endl;
        }
        else if (opcio == "tabla_distancias") {
            cout << "# tabla_distancias" << endl;
            A.print_table_species();
            cout << endl;
        }
        else if (opcio == "inicializa_clusters") {
            cout << "# inicializa_clusters" << endl;
            B.initialize_clusters(A);
            B.print_table_clusters();
            cout << endl;
        }

        else if (opcio == "ejecuta_paso_clust") {
            cout << "# ejecuta_paso_clust" << endl;
            if (B.clusters_set_size() > 1) {
                B.wpgma_algorithm();
                B.print_table_clusters();
            } else cout << "ERROR: num_clusters <= 1" << endl;
            cout << endl;
        }
        else if (opcio == "imprime_cluster") {
            string id;
            cin >> id;
            cout << "# imprime_cluster " << id << endl;
            if (B.cluster_exist(id)) {
                B.find_print_cluster(id);
                cout << endl;
            } else cout << "ERROR: El cluster " << id << " no existe." << endl;
            cout << endl;
        }
        else if (opcio == "imprime_arbol_filogenetico") {
            cout << "# imprime_arbol_filogenetico" << endl;
            B.initialize_clusters(A);
            if (B.clusters_set_size() < 1) cout << "ERROR: El conjunto de clusters es vacio." << endl;
            else {
                while (B.clusters_set_size() > 1) {
                    B.wpgma_algorithm();
                }
                B.print_final_cluster();
                cout << endl;
            }
            cout << endl;
        }
        else if (opcio == "fin") {
            break;
        }
    }


}
   