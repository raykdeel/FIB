/** @file Cluster.hh
    @brief Especificació de la classe Cluster 
*/

#ifndef NO_DIAGRAM 
#include <iostream>
#include "BinTree.hh"
#endif

using namespace std;

/** @class Cluster
    @brief Representa un cluster format per un arbre binari d'un parell string, double.

     Conté un BinTree de pair<string, double> anomenat tree.
*/

class Cluster {

private:

    /** @brief Arbre binari de parells string-double que representen l'estructura d'un cluster. */
    BinTree<pair<string, double>> tree;
    int midacl = 1;

    /** @brief Escriptura d'un arbre. 

      Imprimeix l'estructura de l'arbre del paràmetre i en cas que l'arbre tingui
      un fill dret i un fill esquerra, també escriu la distància que hi havia entre
      els dos fills (anteriorment clusters). 

      \pre <em>cert</em>
      \post Imprimeix l'estructura de l'arbre del paràmetre.
    */

    static void print_tree(const BinTree<pair<string, double>> a);
      
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

    //MODIFICADORES

    /** @brief  Fusió de dos clusters. 
     
      Retorna un nou cluster amb l'arbre del cluster A com a fill esquerra, i 
      l'arbre del cluster B com a fill dret i a l'arrel li assigna la distància
      entre aquests dos clusters i l'indentificador concatenat.
     
      \pre <em>cert</em>
      \post Retorna un nou cluster amb el cluster A com a fill esquerra, i 
      l'arbre B com a fill dret.
    */

    void clusters_fusion(const Cluster& A, const Cluster& B, string a, double x);
        
    //CONSULTORES

    /** @brief Consultora de l'identificador d'un cluster. 

      Retorna l'identificador d'un cluster.

      \pre El cluster existeix.
      \post Retorna l'indentificador del cluster del paràmetre implícit.
    */

    string query_cluster_id() const;

    /** @brief Consultora dels identificadors dels subarbres d'un cluster. 

      Retorna els indentificadors dels fills de l'arbre del cluster.

      \pre El cluster existeix.
      \post Retorna els indentificadors dels fills de l'arbre del cluster del paràmetre implícit.
    */

    pair<string, string> query_cluster_sub_id() const;

    /** @brief Escriptura d'un cluster. 

      Cita la operació privada static print_tree per tal d'escriure el cluster del paràmetre.

      \pre El cluster del paràmetre existeix.
      \post Cita la operació privada que imprimirà l'arbre del paràmetre.
    */

    void print_cluster();

  int mida() const;

BinTree<pair<string, double>>  arbre() const;

};
  

