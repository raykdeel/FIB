/** @file Cjt_Clusters.hh
    @brief Especificació de la classe Cjt_Clusters 
*/

#include "Cluster.hh"
#include "Cjt_Especies.hh"

#ifndef NO_DIAGRAM 
#include <iostream>
#include <map>
#endif


using namespace std;

/** @class Cjt_Clusters
    @brief Representa un conjunt de clusters. 
*/

class Cjt_Clusters {
    
private:
        

    typedef map<string, Cluster>::const_iterator mclu_iterator;
    /** @brief Map que emmagatzema els clusters del conjunt. */
    map<string, Cluster> mclu;
    /** @brief Matriu de les distancies entre els clusters del conjunt. */
    map<string, map<string, double> > table_clusters;
    /** @brief Typedef d'un iterator que recorre una columna (map<string, double>) d'una taula de clusters */
    typedef map<string, double>::const_iterator table_clusters_column_iterator;
    /** @brief Typedef d'un iterator que recorre una taula de clusters (map<string, map<string, double>>) */
    typedef map<string, map<string, double> >::const_iterator table_clusters_iterator;

public:  

    //CONSTRUCTORES

    /** @brief Creadora per defecte. 
      
      S'executa automàticament al declarar un Cjt_Clusters. 
     
      \pre <em>cert</em>
      \post Crea un conjunt de clusters.
   */

    Cjt_Clusters();

    //MODIFICADORES

    /** @brief Afegir un cluster a un conjunt. 
      
      Afegeix el cluster del paràmetre al conjunt de clusters del paràmetre implícit i
      actualiza table_clusters afegint on sigui necessari la distància amb el nou cluster.
     
      \pre El cluster no pertany al conjunt del paràmetre implícit.
      \post Afegeix el cluster al conjunt del paràmetre implícit i actualiza table.
    */

    void add_cluster(const Cluster& A, string id) ;

    /** @brief Esborrar un cluster d'un conjunt. 
     
      Elimina el cluster del paràmetre del conjunt de clusters del paràmetre implícit
      i actualiza table_clusters suprimint qualsevol presència del cluster eliminat.
     
      \pre El cluster pertany al conjunt del paràmetre implícit.
      \post Elimina el cluster del conjunt del paràmetre implícit i actualiza table.
    */

    void erase_cluster(Cluster A);

    /** @brief Inicialitza un conjunt de clusters. 
     
      Primer de tot, buida el map de clusters (mclu) i la matriu de distàncies (table_clusters). 
      Inicialitza el conjunt de clusters amb el conjunt d'espècies del paràmetre i table_clusters
      amb table_species.
     
      \pre <em>cert</em>
      \post Inicialitza el conjunt de clusters amb el conjunt d'espècies i table_clusters amb table_species.
    */

    void initialize_clusters(Cjt_Especies& A);

    /** @brief Executa l'algorisme WPGMA. 

      Fusiona els dos clusters a menor distància i els elimina del conjunt. Afegeix el 
      cluster fusionat al conjunt i afegeix un pair<string, double> a distancies amb 
      l'identificador concatenat i la distància a la qual es trobaven els dos clusters.      

      \pre La mida del conjunt de clusters del paràmetre implícit és > 1.
      \post Fusiona en un nou cluster els dos clusters que es troben a menor distància,
      i els elimina del conjunt. Afegeix al conjunt el cluster resultant i es guarda
      la distància entre els dos clusters fusionats i l'identificador a l'atribut distancies.
    */

    void wpgma_algorithm();

    /** @brief Consultora de la distància entre dos clusters. 
 
      Retorna la distància a la qual es troben els dos clusters.

      \pre El dos clusters pertanyen al conjunt del paràmetre implícit i són diferents.
      \post Retorna la distància entre els dos clusters del paràmetre.
    */

    double cluster_distance(Cluster A, Cluster B);

    /** @brief Actualiza l'element table_clusters d'un conjunt. 
     
      Actualitza table_clusters depenent de si l'indicador és cert o fals. El primer dels casos 
      indica que s'està afegint un cluster, i per tant, dintre de table_clusters, les files amb identificador
      més petit alfabèticament que el cluster afegit (l'identificador d'un cluster és el valor de
      l'arrel del seu arbre) han d'incloure un nou pair<string, double> que emmagatzemi la nova 
      distància. I quan les files de table_clusters tenen un identificador més gran que el del cluster afegit
      s'afegeix a la fila del cluster afegit un nou un pair<string, double> amb la nova distància. 
      Si l'identificador és fals, s'elimina de table_clusters tot parell que inclogui l'identificador del
      cluster eliminat.
     
      \pre La mida del conjunt de clusters del paràmetre implícit és > 1.
      \post Actualitza table_clusters del paràmetre implícit depenent si s'està eliminant un cluster o si s'està afegint.
    */

    void clusters_distance_update(bool indicador, string id);

    /** @brief Consultora dels clusters a menor distància. 

      Retorna un pair<string, string> on tots dos string són els identificadors dels clusters a 
      menor distància. El primer string és menor alfabèticament que el segon. També es guarda la
      distància mínima al paràmetre x.

      \pre <em>cert</em>
      \post Retorna un pair<string, string> amb els identificadors dels dos clusters a menor distància.
    */

    pair<string, string> dmin(double& x);

    //CONSULTORES
    
  /** @brief Consultora de l'existència d'un cluster al conjunt.
    
   Retorna cert o fals depenent de l'existència del cluster al qual pertany
   l'identificador del paràmetre. 
   
      \pre <em>cert</em>
      \post Retorna cert si existeix un cluster amb l'identificador del paràmetre
       o fals en cas contrari.
  */

    bool cluster_exist(string id);

    /** @brief Consultora de la mida d'un conjunt. 

      Retorna la mida del conjunt de clusters del paràmetre implícit.

      \pre <em>cert</em>
      \post El resultat és el nombre de clusters del conjunt de clusters del paràmetre implícit.
    */

    int clusters_set_size() const;

    //ESCRIPTURA

    /** @brief Escriptura del primer/últim cluster d'un conjunt. 

      Cita el mètode de la classe Cluster print_cluster.

      \pre <em>cert</em>
      \post Cita el mètode de la classe Cluster print_cluster.
    */

    void print_final_cluster();

    /** @brief Escriptura del cluster al qual pertany l'id. 

      Cita el mètode de la classe Cluster print_cluster per tal d'imprimir el cluster
      al qual pertany l'identificador del paràmetre.

      \pre <em>cert</em>
      \post Cita el mètode de la classe Cluster print_cluster.
    */

    void find_print_cluster(string id);


    /** @brief Escriptura de table_clusters. 

      Escriu pel canal estàndard de sortida la matriu table_clusters del conjunt del paràmetre
      implícit. Table_clusters està ordenada alfabèticament i primer escriu l'identificador i la 
      distància entre el cluster al qual pertany aquest identificador i els clusters amb 
      identificador més gran.

      \pre <em>cert</em>
      \post Escriu pel canal estàndard de sortida la matriu table_clusters del conjunt del paràmetre
       implícit.
    */

    void print_table_clusters();
};