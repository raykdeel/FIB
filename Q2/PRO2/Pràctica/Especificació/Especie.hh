/** @file Especie.hh
    @brief Especificació de la classe Especie 
*/



#ifndef NO_DIAGRAM 
#include <iostream>
#include <vector>
#endif
using namespace std;

/** @class Especie
    @brief Representa una espècie amb un identificador i un gen.

     Conté l'identificador d'una espècie, i el seu gen, tots dos strings.
*/


class Especie {
    
  private: 

    /** @brief Identificador de l'espècie */ 
    string identificador;
    /** @brief Gen de l'espècie */
    string gen;
    
  public:

    //Constructores

  /** @brief Constructora per defecte. 
      \pre <em>cert</em>
      \post El resultat és una espècie amb identificador i gen no vàl·lids
  */

    Especie();

  /** @brief Constructora d'una espècie. 
      \pre <em>cert</em>
      \post El resultat és una espècie amb identificador = id i gen = g.
  */

    Especie(string id, string g);

    //Modificadores

  /** @brief  Modificadora de l'identificador. 
      \pre <em>cert</em>
      \post L'id del paràmetre implícit passa a ser l'identificador de l'espècie.
  */

    void modificar_id(string id);

    //Consultores

  /** @brief  Consulta de l'identificador d'una espècie. 
      \pre <em>cert</em>
      \post El resultat és l'identificador del paràmetre implícit
  */

    string consultar_identificador() const;

  /** @brief  Consulta del gen d'una espècie. 
      \pre <em>cert</em>
      \post El resultat és el gen del paràmetre implícit
  */

    string consultar_gen() const;

    //Lectura i escriptura

  /** @brief  Lectura d'una espècie.
      \pre Hi ha preparats al canal estandar d'entrada dos strings
      \post El paràmetre implícit passa a tenir els atributs llegits 
     del canal estàndard d'entrada.
  */

    void llegir();

  /** @brief  Escriptura d'una espècie.
      \pre <em>cert</em>
      \post S'han escrit els atributs del paràmetre implícit 
     al canal estàndard de sortida.
  */

    void escriu() const ;

    
};