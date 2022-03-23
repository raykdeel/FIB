/** @file Cjt_Especies.hh
    @brief Especificació de la classe Cjt_Especies 
*/

#include "Especie.hh"

#ifndef NO_DIAGRAM 
#include <iostream>
#include <vector>
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
  /** @brief Nombre d'espècies */

public:

    //Constructores

    /** @brief Creadora per defecte. 
      \pre <em>cert</em>
      \post Crea un conjunt d'espècies buit amb nesp = 0.
   */

    Cjt_Especies();
    
    //Modificadores

    /** @brief Afegir una espècie a un conjunt. 
      \pre El paràmetre implícit no està ple
      \post Afegeix l'espècie a un conjunt si no hi era.
    */

    void afegir_especie(const Especie& a);

    /** @brief Esborrar una espècie d'un conjunt. 
      \pre <em>cert</em>
      \post Si l'espècie existeix al conjunt, l'elimina, si no existeix, 
      escriu un missatge d'error informant que no existeix cap espècie amb
      aquest identificador.s
    */

    void eliminar_especie(string id); //WORKS


    void actualitzar_distancies();

    //Consultores

  /** @brief Consultora del vector d'espècies d'un conjunt. 
      \pre <em>cert</em>
      \post Retorna el vector d'espècies del conjunt del paràmetre implícit.
  */

    map<string, Especie> consultar_mesp() const;

  /** @brief Consultora de l'existència d'una espècie al conjunt del paràmetre implícit.
      \pre <em>cert</em>
      \post Retorna cert si existeix una espècie amb l'identificador del paràmetre
       o fals en cas contrari.
  */

    bool existeix_especie(string id) ;
    
  /** @brief Consultora de la distància entre dues espècies.
      \pre <em>cert</em>
      \post Retorna la distància entre les dues espècies a les que pertanyen els
      identificadors donats, i en cas de que alguna no existeixi, retorna found com a fals.
  */

    double consultar_distancia(string id1, string id2); //WORKS

    // Lectura i escriptura

  /** @brief Lectura d'un conjunt d'espècies.

    \pre Elimina el contingut del conjunt previ i al canal estàndar d'entrada
    hi ha preparat el nombre d'espècies a llegir (nesp).
    \post El paràmetre implícit conté el conjunt d'espècies llegits
     del canal estàndar d'entrada.
  */

    void llegir(int n, int k);

  /** @brief Escriptura d'un gen.
      \pre Està preparat pel canal estàndar d'entrada un identificador.
      \post Escriu al canal estàndar de sortida el gen associat a l'identificador
      donat. En cas que no existeixi cap espècie amb l'identificador donat,
      escriu un missatge d'error.
  */
     
    void obtener_gen(string id);

  /** @brief Escriptura d'un conjunt d'espècies. 
      \pre <em>cert</em>
      \post S'han escrit pel canal estàndar de sortida 
     les espècies del conjunt que conté el paràmetre 
     implícit.
  */

    void escriu_cjt_especies();

  /** @brief Escriptura de la taula de distàncies d'un conjunt d'espècies. 
      \pre <em>cert</em>
      \post Escriu pel canal estàndar de sortida una taula amb les distàncies
      entre cada parell d'espècies del conjunt.
  */

    void taula_distancies();


    void recalcular_distancies(bool indicador, string id);

    
};