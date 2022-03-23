/** @file Cluster.hh
    @brief Especificació de la classe Cluster 
*/


#include "Cjt_Especies.hh"

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

    /** @brief Identificador del cluster */ 
    //string idcluster;
    /** @brief Arbre binari d'espècies */
    BinTree<string> arbre2;
    map<string, double> idk;
        
        

public:

  Cluster(BinTree<string> aux, map<string, double> aux1);

  void write2();







    //CONSTRUCTORES

    /** @brief Constructora per defecte. 
      \pre <em>cert</em>
      \post El resultat és un cluster amb un idcluster i un arbre buits.
    */

    Cluster();

    /** @brief Constructora d'un cluster amb un arbre. 
      \pre <em>cert</em>
      \post El resultat és un cluster amb l'arbre donat pel paràmetre.
    */

    Cluster(BinTree<string> aux); 

    //MODIFICADORES

    /** @brief  Modificadora de l'arbre. 
      \pre <em>cert</em>
      \post Substitueix l'arbre del cluster per l'arbre donat pel paràmetre.
    */
    
    void modificar_arbre(const BinTree<string>& b);

    /** @brief  Modificadora de l'identificador del cluster. 
      \pre <em>cert</em>
      \post Li assigna a idcluster l'identificador de l'espècie del parèmentre.
    */

    void modificar_idcl(const Especie& a);

    /** @brief  Fusió de dos clusters. 
      \pre <em>cert</em>
      \post Retorna un nou cluster amb el cluster A com a fill esquerra, i 
      l'arbre B com a fill dret i li assigna l'espècie donada.
    */

    void fusio_clusters(const Cluster& A, const Cluster& B, const string& a);
        
    //CONSULTORES

    /** @brief  Consulta de l'altura d'un arbre.
      \pre <em>cert</em>
      \post Si l'arbre està buit, retorna 0, sino, retorna 
      l'altura de l'arbre (incloent els fills).
    */

    int consultar_altura(const BinTree<string> b);

    /** @brief  Consulta de l'identificador d'un cluster. 
      \pre <em>cert</em>
      \post El resultat és l'idcluster del paràmetre implícit
    */

    string consultar_idcluster() const;

    /** @brief  Consulta de l'arbre d'un cluster. 
      \pre <em>cert</em>
      \post El resultat és l'arbre del paràmetre implícit
    */

    BinTree<string> consultar_arbre() const;
    
    /** @brief Consulta de la mida d'un arbre. 
      \pre <em>cert</em>
      \post El resultat és el nombre de nodes de l'arbre del paràmetre implícit.
    */

    int mida_cluster() const;
    

    // LECTURA I ESCRIPTURA

    /** @brief  Escriptura d'un cluster.
      \pre <em>cert</em>
      \post S'han escrit els atributs del paràmetre implícit 
     al canal estàndard de sortida.
    */

    void escriu_cluster(int i) const;


map<string, double> consultar_distancies();

void modificar_distancies(map<string,double> aux);
};
  

