/** @file Cjt_Especies.hh
    @brief Especificació de la classe Cjt_Especies 
*/
#include "Especie.hh"

#ifndef NO_DIAGRAM 
#include <iostream>
#include <map>
#endif


using namespace std;

/** @class Cjt_Especies
    @brief Representa un conjunt d'espècies. 
*/

class Cjt_Especies {

private:

  /** @brief Map d'espècies */
  map<string, Especie> mesp;
  /** Iterador del map d'espècies */
  map<string, Especie>::iterator it;
  /** @brief Taula de distàncies entre les espècies */
  map<string, map<string, double> > table_species;
  /** @brief Typedef d'un iterator que recorre una columna (map<string, double>) d'una taula d'espècies */
  typedef map<string, double>::const_iterator table_species_column_iterator;
  /** @brief Typedef d'un iterator que recorre una taula d'espècies (map<string, map<string, double>>) */
  typedef map<string, map<string, double> >::const_iterator table_species_iterator;

public:

    //CONSTRUCTORES

    /** @brief Creadora per defecte. 
     
      S'executa automàticament al declarar un Cjt_Especies.
     
      \pre <em>cert</em>
      \post Crea un conjunt d'espècies.
   */

    Cjt_Especies();
    
    //MODIFICADORES

    /** @brief Afegir una espècie a un conjunt. 
      
      Afegeix l'espècie del paràmetre al conjunt d'espècies del paràmetre implícit i
      cita a l'operació species_distance_update per tal d'actualizar table_species.
     
      \pre L'espècie no pertany al conjunt del paràmetre implícit.
      \post Afegeix l'espècie al conjunt del paràmetre implícit.
    */

    void add_species(const Especie& a);

    /** @brief Esborrar una espècie d'un conjunt. 
     
      Elimina l'espècie del paràmetre del conjunt d'espècies del paràmetre implícit
      i cita a l'operació species_distance_update per tal d'actualizar table_species.
     
      \pre L'espècie pertany al conjunt del paràmetre implícit.
      \post Elimina l'espècie del conjunt del paràmetre implícit.
    */

    void erase_species(string id); //WORKS

    /** @brief Inicializa species_distancies de cada espècie d'en conjunt. 
     
      Inicialitza table_species calculant la distància entre cada parell d'espècies possible.
     
      \pre <em>cert</em>
      \post Inicialitza table_species amb les distància entre les espècies del conjunt.
    */

    void initialize_distances();

    /** @brief Actualiza species_distancies de cada espècie d'en conjunt. 
     
      Actualitza table_species depenent de si l'indicador és cert o fals. El primer dels casos 
      indica que s'està afegint una espècie, i per tant, dintre de table_species, les files amb identificador
      més petit alfabèticament que l'espècie afegida han d'incloure un nou pair<string, double> que emmagatzemi
      la nova distància. I quan les files de table_species tenen un identificador més gran que el de l'espècie
      afegida, es crea a la fila del la nova espècie un pair<string, double> amb la nova distància. 
      Si l'identificador és fals, s'elimina de table_species tot parell que inclogui l'identificador de
      l'espècie eliminada.
     
      \pre <em>cert</em>
      \post Actualitza table_species depenent si s'està eliminant un espècie o si s'està afegint.
    */

    void species_distance_update(bool indicador, string id);

    /** @brief Distància entre dues espècies. 
     
      Calcula la distància que hi ha entre les dues espècies a les quals pertanyen els identificadors
      del paràmetre.
     
      \pre Les dues espècies pertanyen al conjunt del paràmetre implícit.
      \post Retorna la distància entre les dues espècies a les quals pertanyen els identificadors.
    */

    double species_distance(string id1, string id2);

    //CONSULTORES

  /** @brief Consulta de l'identificador d'una espècie. 
 
    Retorna l'identificador d'una espècie del conjunt del paràmetre implícit.

      \pre L'espècie pertany al conjunt.
      \post Retorna l'identificador d'una espècie del conjunt.
  */

    string returnid(int i);

  /** @brief Consulta de la distància entre dues espècies. 
 
    Retorna la distància entre les dues espècies a les quals pertanyen els identificadors
    del paràmetre.

      \pre Les dues espècies pertanyen al conjunt i són diferents.
      \post Retorna la distància entre dues espècies.
  */

    double returndist(const string id1, const string id2);

  /** @brief Consultora de la mida d'un conjunt. 

      Retorna la mida del conjunt d'espècies del paràmetre implícit.

      \pre <em>cert</em>
      \post El resultat és el nombre d'espècies del conjunt d'espècies del paràmetre implícit.
  */

    int species_set_size()const;

  /** @brief Consultora de l'existència d'una espècie al conjunt.
    
   Retorna cert o fals depenent de l'existència de l'espècie a la qual pertany
   l'identificador del paràmetre. 
   
      \pre <em>cert</em>
      \post Retorna cert si existeix una espècie amb l'identificador del paràmetre
       o fals en cas contrari.
  */

    bool species_exist(string id) ;
    
  /** @brief Consultora de l'espècie a la qual pertany l'identificador.

   Retorna l'espècie a la qual pertany l'identificador del paràmetre.

      \pre L'espècie existeix dintre del conjunt del paràmetre implícit.
      \post Retorna l'espècie a la qual pertany l'identificador del paràmetre.
  */

    Especie find_species(string id);

    //LECTURA I ESCRIPTURA

  /** @brief Lectura d'un conjunt d'espècies.
 
    Primer de tot, buida el conjunt d'especies mesp i la taula table_species.
    Llegeix tantes espècies com indica l'element n del paràmetre, i les afegeix
    al conjunt del paràmetre implícit. Després d'haver llegit totes les espècies, 
    inicialitza les distàncies entre elles mitjançant el mètode initialize_distances.

    \pre <em>cert</em>
    \post El paràmetre implícit conté el conjunt d'espècies llegit.
  */

    void read_species(int n, int k);

  /** @brief Escriptura d'un conjunt d'espècies. 
    
    Escriu pel canal estàndard de sortida l'identificador i gen de cada espècie del 
    conjunt del paràmetre implícit.

      \pre <em>cert</em>
      \post S'han escrit pel canal estàndar de sortida les espècies del conjunt del paràmetre 
     implícit.
  */

    void print_species();

  /** @brief Escriptura de table_species. 
 
    Escriu pel canal estàndard de sortida la matriu table_species del conjunt del paràmetre
    implícit. table_species està ordenada alfabèticament i primer escriu l'identificador i la 
    distància entre la espècie a la qual pertany aquest identificador i la resta d'espècies amb
    identificador més gran.

      \pre <em>cert</em>
      \post Escriu pel canal estàndard de sortida la matriu table_species del conjunt del paràmetre
       implícit.
  */

    void print_table_species();


    



    

};