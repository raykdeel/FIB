/** @file Cluster.hh
    @brief Especificació de la classe Cluster 
*/

#ifndef NO_DIAGRAM 
#include <iostream>
#include "BinTree.hh"
#endif

using namespace std;

/** @class Cluster
    @brief Representa un cluster format per un idcluster i BinTree.

     Conté l'identificador del cluster i un BinTree d'espècies anomenat
     arbre.
*/

class Cluster {

private:

    /** @brief Arbre binari d'strings que representa l'estructura d'un cluster. */
    BinTree<pair<string, double>> tree;

    
      
public:

    //CONSTRUCTORES

    /** @brief Constructora per defecte.
      
      S'executa automàticament al declarar un cluster.

      \pre <em>cert</em>
      \post El resultat és un cluster amb un idcluster i un arbre buits.
    */

    Cluster();

    /** @brief Copiadora per defecte. 

      S'introdueix un arbre i retorna un cluster.

      \pre <em>cert</em>      
      \post El resultat és un cluster amb l'arbre donat pel paràmetre.
    */

    Cluster(string id, double x);

    Cluster(BinTree<string> aux);  //no

    //MODIFICADORES

    /** @brief  Fusió de dos clusters. 
     
      Fusió de dos clusters en un de nou.
     
      \pre <em>cert</em>
      \post Retorna un nou cluster amb el cluster A com a fill esquerra, i 
      l'arbre B com a fill dret i li assigna l'espècie donada.
    */

    void clusters_fusion(const Cluster& A, const Cluster& B, string a, double x);
        
    //CONSULTORES

    /** @brief  Consulta de l'arbre d'un cluster. 
      
      Retorna l'arbre del paràmetre implícit tree.

      \pre <em>cert</em>
      \post El resultat és l'arbre del paràmetre implícit
    */

    BinTree<pair<string, double> > query_tree() const; //no
    
    /** @brief Consulta de la mida d'un arbre.
     
      Retorna la mida de l'arbre. 
     
      \pre <em>cert</em>
      \post El resultat és el nombre de nodes de l'arbre del paràmetre implícit.
    */

    //int cluster_size() const;

    string query_cluster_id() const;

    /** @brief Escriptura d'un arbre. 

      Imprimeix l'estructura de l'arbre del paràmetre i en cas que l'arbre tingui
      un fill dret i un fill esquerra, també escriu la distància que hi havia entre
      els dos fills (anteriorment clusters). 

      \pre El cluster al qual pertany l'identificador del paràmetre existeix.
      \post Imprimeix l'estructura de l'arbre del paràmetre.
    */

    void print_tree(const BinTree<pair<string, double>>& a);

    pair<string, string> query_cluster_sub_id() const;

};
  

