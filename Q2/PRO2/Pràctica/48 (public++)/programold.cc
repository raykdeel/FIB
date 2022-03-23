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
            if (not A.existeix_Especie(id)) {
                A.afegir_Especie(a);
            } else cout << "Ja existeix una espècie amb aquest identificador al conjunt d'espècies" << endl;
        }
        else if (opcio == "obtener_gen") {
            string id;
            cin >> id;
            int i = A.cerca_esp(A.consultar_vector(), id);
            if (i != -1) cout << A.consultar_vector()[i].consultar_gen() << endl;
            else cout << "No existeix una espècie amb aquest identificador" << endl;
        }
        else if (opcio == "distancia") {
            string id1, id2;
            cin >> id2 >> id2;
            if (not A.existeix_Especie(id1) or not A.existeix_Especie(id2)) cout << "Alguna de les espècies no existeix" << endl;
            else cout << A.consultar_distancia(id1, id2, k) << endl;

        } 
        else if (opcio == "elimina_especie") {
            string id;
            cin >> id;
            if (not A.existeix_Especie(id)) cout << "No existeix cap espècie amb aquest identificador" << endl;
            else A.eliminar_Especie(id);
        }
        else if (opcio == "existe_especie") {
            string id;
            cin >> id;
            if (A.existeix_Especie(id)) cout << "L'espècie existeix" << endl;
            else cout << "No existeix cap espècie amb aquest identificador" << endl;
        } 
        else if (opcio == "lee_cjt_especies") {
            int n;
            cin >> n;
            A.llegir(n);
            
        }
        else if (opcio == "imprime_cjt_especies") { //falta buidar
            A.escriu_cjt_especies();
        }
        else if (opcio == "tabla_distancias") {
            A.taula_distancies(k);
        } 

        /*else if (opcio == "inicializa_clusters") {
            B.inicialitzar_clusters(A);
            B.escriu_cjt_clusters();
            B.escriu_taulac(k,A);
        }
        else if (opcio == "ejecuta_paso_wpgma") {
            if(B.mida_cjt_clusters() <= 1) cout << "No hi ha prous clusters" << endl;
            else {
                vector<double> aux = B.consultar_vector_distancies();
                B.WPGMA(k,A, aux);
                B.escriu_taulac(k,A);
                B.consultar_vector_distancies() = aux;
            }
            
        }
        else if (opcio == "imprime_cluster") {
            string id;
            cin >> id;
            if (not B.existeix_Cluster(id)) cout << "No existeix cap cluster amb aquest identificador" << endl;
            else B.imprimir_cluster(id);
        }
        else if (opcio == "imprime_arbol_filogenetico") {
            for(int i = 0; i < B.mida_cjt_clusters(); ++i) B.eliminar_cluster(B.consultar_vector()[i]);
            B.inicialitzar_clusters(A);
            if(B.mida_cjt_clusters() == 0) cout << "El conjunt de clusters està buit" << endl;
            else {
                vector<double> aux = B.consultar_vector_distancies();
                while(B.mida_cjt_clusters() > 1) {
                    B.WPGMA(k, A, aux);
                }
                B.escriu_arbre(k, aux);
            }
        }
        */
        else if (opcio == "fin") {
            cout << opcio << endl;
            break;
        }
        
    }
}