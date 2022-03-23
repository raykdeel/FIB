/** @file Cjt_Clusters.hh
    @brief Especificació de la classe Cjt_Clusters 
*/


#include "Cluster.hh"

#ifndef NO_DIAGRAM 
#include <vector>
#include <iostream>
#endif


using namespace std;

/** @class Cjt_Clusters
    @brief Representa un conjunt de clusters. 
*/

class Cjt_Clusters {
    
private:
        
    /** @brief Vector de clusters */
    //vector<Cluster> vecl;
    /** @brief Nombre de clusters */
    //int ncluster;
    /** @brief Vector que emmagatzema les distancies dels clusters fusionats */
    map<string, double> distancies;
    map<string, Cluster> mclu;
    map<string, map<string, double> > table;

public:

      


    //CONSTRUCTORES

    /** @brief Creadora per defecte. 
      \pre <em>cert</em>
      \post Crea un conjunt de clusters amb ncluster = 0.
   */

    Cjt_Clusters();

    //MODIFICADORES

    /** @brief Afegir un cluster a un conjunt. 
      \pre El paràmetre implícit no està ple
      \post Afegeix el cluster a un conjunt.
    */

    void afegir_cluster(const Cluster& A) ;

    /** @brief Esborrar un cluster d'un conjunt. 
      \pre <em>cert</em>
      \post Elimina el cluster del conjunt si existeix.
    */

    void eliminar_cluster(Cluster A);

    /** @brief Inicialitza un conjunt de clusters. 
      \pre Hi ha un conjunt d'espècies declarat al paràmetre.
      \post Inicialitza el conjunt de cluster amb el conjunt d'espècies.
    */

    void inicialitzar_clusters(const Cjt_Especies T);

    /** @brief Executa un pas de l'algorisme WPGMA. 
      \pre Hi ha un conjunt de clusters no buit, amb ncluster >= 2.
      \post Fusiona en un nou cluster els dos clusters que es troben a menor distància,
      i els eliminar del conjunt. S'ha afegit al conjunt el cluster resultant i s'ha guardat
      la distància entre els dos clusters fusionats en un vector.
    */

    void WPGMA();

    //CONSULTORES

    /** @brief Consultora del vector de clusters d'un conjunt. 
      \pre <em>cert</em>
      \post Retorna el vector de clusters del conjunt del paràmetre implícit.
    */

    //vector<Cluster> consultar_vector() const;

    /** @brief Consultora del vector de distancies d'un conjunt. 
      \pre <em>cert</em>
      \post Retorna el vector de distàncies del conjunt del paràmetre implícit.
    */

    //vector<double> consultar_vector_distancies() const;

    /** @brief Consultora de la mida d'un conjunt. 
      \pre <em>cert</em>
      \post El resultat és el nombre de clusters del paràmetre implícit.
    */

    int mida_cjt_clusters() const;

    /** @brief Consultora de l'existència d'un cluster al conjunt del paràmetre implícit.
      \pre <em>cert</em>
      \post Retorna cert si existeix un cluster amb l'identificador del paràmetre
       o fals en cas contrari.
  */

    bool existeix_Cluster(string id) const;


    /** @brief Consultora de la posició dels clusters a menor distància. 
      \pre El conjunt de clusters no està buit.
      \post Retorna la posició que ocupen els dos clusters que es troben a
      menor distància.
    */

    //void dist_min(int k, Cjt_Especies T, int& x, int& y);

    /** @brief Consultora de la distància entre dos clusters. 
      \pre <em>cert</em>
      \post Retorna la distància entre dos clusters, tenint en compte si 
      contenen un únic element (espècie), o si estàn formats per més clusters.
    */

    double distancia_cluster(Cluster A, Cluster B);

    // LECTURA I ESCRIPTURA

    /** @brief Escriptura d'un arbre filogenètic.
      \pre Al vector distancies hi ha emmagatzedes les distàncies que hi havia
      entre els clusters fusionats.
      \post El contingut previ del conjunt de clusters es descarta i s'inicialitza
      amb el conjunt d'espècies actual. S'ha imprès l'estructura de l'arbre amb els
      identificadors dels clusters i la distància entre cada cluster.
    */

    //void escriu_arbre(int k, vector<double> distancies);

    /** @brief Escriptura de la taula de distàncies d'un conjunt de clusters. 
      \pre <em>cert</em>
      \post Escriu pel canal estàndar de sortida una taula amb les distàncies
      entre cada parell de clusters del conjunt.
    */

    //void escriu_taulac(int k, Cjt_Especies T);

    /** @brief Escriptura d'un cluster. 
      \pre <em>cert</em>
      \post Imprimeix l'estructura de l'arbre que té l'identificador donat, o
      en cas de no existir aquest cluster, escriu un missatge d'error.
    */

    //void imprimir_cluster(string id);

    /** @brief Escriptura d'un conjunt de clusters. 
      \pre <em>cert</em>
      \post S'han escrit pel canal estàndar de sortida els clusters del conjunt
      qye conté el paràmetre implícit.
    */




    /*void taula_distancies();

    void recalcular_distancies(bool indicador, string id);

    void actualitzar_distancies();
    */

    pair<string, string> dmin();

    void write();

    void recalcular_distancies(bool indicador, string id);

    void holaqtal(string id);
    void holaqtal2(Cluster a);
      
    Cluster consultar_cluster_final() ;

};