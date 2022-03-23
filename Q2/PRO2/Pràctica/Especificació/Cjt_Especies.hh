/** @file Cjt_Especies.hh
    @brief Especificació de la classe Cjt_Especies 
*/


#ifndef NO_DIAGRAM 
#include <iostream>
#include <vector>

#endif

#include "Especie.hh"
using namespace std;

/** @class Cjt_Especies
    @brief Representa un conjunt d'espècies. 
*/

class Cjt_Especies {

private:

  /** @brief Vector d'espècies */
  vector<Especie> vesp;
  /** @brief Nombre d'espècies */
  int nesp;

  /** @brief Cerca d'un identificador. 
      \pre <em>cert</em>
      \post Si id hi és vesp, el resultat és la posició que
     hi ocupa, si no, retorna -1.
  */

  static int cerca_esp(const vector<Especie>& v, string id);


  /** @brief Conjunt de subseqüències contigües de g de longitud k. 
      \pre <em>cert</em>
      \post Retorna un vector d'strings amb totes les subseqüències contigües de g (gen) de longitud k.
  */

  vector<string> kmer(string g, int k) const;

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

    void afegir_Especie(const Especie& a);

    /** @brief Esborrar una espècie d'un conjunt. 
      \pre <em>cert</em>
      \post Si l'espècie existeix al conjunt, l'elimina, si no existeix, 
      escriu un missatge d'error informant que no existeix cap espècie amb
      aquest identificador.s
    */

    void eliminar_Especie(string id); //WORKS


    //Consultores

  /** @brief Consultora del vector d'espècies d'un conjunt. 
      \pre <em>cert</em>
      \post Retorna el vector d'espècies del conjunt del paràmetre implícit.
  */

    vector<Especie> consultar_vector() const;

  /** @brief Consultora de l'existència d'una espècie al conjunt del paràmetre implícit.
      \pre <em>cert</em>
      \post Retorna cert si existeix una espècie amb l'identificador del paràmetre
       o fals en cas contrari.
  */

    bool existeix_Especie(string id) const;
    
  /** @brief Consultora de la distància entre dues espècies.
      \pre <em>cert</em>
      \post Retorna la distància entre les dues espècies a les que pertanyen els
      identificadors donats.
  */

    double consultar_distancia(string id1, string id2, int k) const; //WORKS

  /** @brief Consultora de la mida d'un conjunt. 
      \pre <em>cert</em>
      \post El resultat és el nombre d'espècies del paràmetre implícit.
  */

    int mida() const;

    // Lectura i escriptura

  /** @brief Lectura d'un conjunt d'espècies.

    \pre Elimina el contingut del conjunt previ i al canal estàndar d'entrada
    hi ha preparat el nombre d'espècies a llegir (nesp).
    \post El paràmetre implícit conté el conjunt d'espècies llegits
     del canal estàndar d'entrada.
  */

    void llegir();

  /** @brief Escriptura d'un gen.
      \pre Està preparat pel canal estàndar d'entrada un identificador.
      \post Escriu al canal estàndar de sortida el gen associat a l'identificador
      donat. En cas que no existeixi cap espècie amb l'identificador donat,
      escriu un missatge d'error.
  */

    void obtenir_gen(string id);

  /** @brief Escriptura d'un conjunt d'espècies. 
      \pre <em>cert</em>
      \post S'han escrit pel canal estàndar de sortida 
     les espècies del conjunt que conté el paràmetre 
     implícit.
  */

    void escriu_cjt_especies() const;

  /** @brief Escriptura de la taula de distàncies d'un conjunt d'espècies. 
      \pre <em>cert</em>
      \post Escriu pel canal estàndar de sortida una taula amb les distàncies
      entre cada parell d'espècies del conjunt.
  */

    void taula_distancies(int k);
};