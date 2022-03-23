/**
 * @mainpage Pràctica (Primavera 2020).
 
En aquesta pràctica es crea un arbre filogenètic que reflexa la hipotètica evolució de varies espècies. S'introdueixen les classes <em>Especie</em>,
<em>Cjt_Especies</em>, <em>Cluster</em> i <em>Cjt_Clusters</em>.

*/

/** @file program.cc
    @brief Programa principal de la pràctica.
*/


#include "Cjt_Clusters.hh"

#ifndef NO_DIAGRAM 

#include "BinTree.hh"
#include <iostream>
#include <string>
#include <vector>
#endif

using namespace std;

/** @brief Programa principal de la pràctica.
*/

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
            Especie a(id, g);
            if (not B.existeix_especie(id)) {
                B.afegir_especie(a);
            } else cout << "Ja existeix una espècie amb aquest identificador al conjunt d'espècies" << endl;
        }
        else if (opcio == "obtener_gen") {
            string id;
            cin >> id;
            int i = B.cerca_esp(vesp, id);
            if (i != -1) cout << vesp[i].consultar_gen() << endl;
            else cout << "No existeix una espècie amb aquest identificador" << endl;
        }
        else if (opcio == "distancia") {

        } 
        else if (opcio == "elimina_especie") {

        }
        else if (opcio == "existe_especie") {

        } 
        else if (opcio == "lee_cjt_especies") {

        }
        else if (opcio == "tabla_distancias") {

        } 
        else if (opcio == "inicializa_clusters") {

        }
        else if (opcio == "ejecuta_paso_wpgma") {

        }
        else if (opcio == "imprime_cluster") {

        }
        else if (opcio == "imprime_arbol_filogenetico") {

        }
        else if (opcio == "fin") {
            cout << opcio << endl;
            break;
        }
    }
}