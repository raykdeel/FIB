/** @file Estudiant.hh
    @brief Especificació de la classe Estudiant 
*/

#ifndef ESTUDIANT_HPP
#define ESTUDIANT_HPP

#ifndef NO_DIAGRAM 
#include "utils.PRO2"
#endif

/** @class Estudiant
    @brief Representa un estudiant amb DNI i la possibilitat de tenir nota

     Conté el DNI d'un estudiant, que és un enter positiu,
     i pot tenir nota, que seria un double.
     Les notes vàlides són les de l'interval 0..nota_maxima()
*/

class Estudiant {

  // Tipus de m�dul: dades
  // Descripci� del tipus: cont� el DNI d'un estudiant, 
  // que �s un enter positiu, i pot tenir nota, que seria un double 
  // Les notes v�lides s�n les de l'interval 0..nota_maxima() 

private:   

  /** @brief DNI de l'estudiant (0 <= DNI) */ 
  int dni;
  /** @brief Nota de l'estudiant */
  double nota;
  /** @brief Si amb_nota, llavors 0 <= nota <= MAX_NOTA  */
  bool amb_nota;
  /** @brief Nota màxima que pot tenir un estudiant */
  static const int MAX_NOTA = 10;

public:

  //Constructores

  /** @brief Constructora per defecte. 
      \pre <em>cert</em>
      \post El resultat és un estudiant amb DNI = 0 i sense nota
  */

  Estudiant();

  /** @brief Constructora d'un estudiant amb DNI. 
      \pre dni >= 0
      \post El resultat és un estudiant amb DNI=dni i sense nota
  */

  Estudiant(int dni);

  /** @brief Destructora per defecte
      \pre <em>cert</em>
      \post Esborra automàticament els objectes locals en sortir d'un àmbit de visibilitat
  */
   
  ~Estudiant();

  //Modificadores

  /** @brief  Modificadora de nota. 
      \pre El parametre implicit no té nota, 0 <= "nota" <= nota_maxima()
      \post La nota del parametre implicit passa a ser "nota"
  */

  void afegir_nota(double nota);

  /** @brief  Modificadora de nota. 
      \pre El parametre implicit té nota, 0 <= "nota" <= nota_maxima()
      \post La nota del paràmetre implícit passa a ser "nota"
  */
  void modificar_nota(double nota);
                                    
  //Consultores

  /** @brief  Consulta del DNI d'un estudiant. 
      \pre <em>cert</em>
      \post El resultat és el DNI del paràmetre implícit
  */

  int consultar_DNI() const;

  /** @brief  Consulta de la nota d'un estudiant. 
      \pre El paràmetre implícit té nota
      \post El resultat és la nota del paràmetre implícit
  */

  double consultar_nota() const;

  /** @brief  Consultora de la nota màxima que pot tenir un estudiant. 
      \pre <em>cert</em>
      \post El resultat és la nota màxima dels elements de la classe
  */

  static double nota_maxima();

  /** @brief  Consultora de l'existència de la nota d'un estudiant. 
      \pre <em>cert</em>
      \post El resultat indica si el paràmetre implícit té nota o no
  */

  bool te_nota()  const;

  /** @brief  Consultora del DNI de dos estudiants.
      \pre <em>cert</em>
      \post El resultat indica si el DNI d'e1 es més petit que el d'e2
  */

  static bool comp(const Estudiant& e1, const Estudiant& e2); 

  // Lectura i escriptura

  /** @brief  Lectura d'un estudiant.
      \pre Hi ha preparats al canal estandar d'entrada un enter no negatiu i un double
      \post El paràmetre implícit passa a tenir els atributs llegits 
     del canal estàndard d'entrada; si el double no pertany a l'interval 
     [0..nota_maxima()], el p.i. es queda sense nota
  */

  void llegir();

  /** @brief  Escriptura d'un estudiant.
      \pre cert
      \post S'han escrit els atributs del paràmetre implícit 
     al canal estàndard de sortida; si no té nota escriu "NP"
  */

  void escriure() const;

};
#endif
