/** @file Cjt_estudiants.hh
    @brief Especificació de la classe Cjt_estudiants 
*/

#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#ifndef NO_DIAGRAM 
#include <vector>

#endif

/** @class Cjt_estudiants
    @brief Representa un conjunt d'estudiants ordenat per DNI. 
*/

class Cjt_estudiants {

private:

/** @brief Vector d'estudiants */
  vector<Estudiant> vest;
  /** @brief Nombre d'estudiants */
  int nest; 
  /** @brief Nombre màxim d'estudiants */
  static const int MAX_NEST = 20;
  /** @brief És el nombres d'estudiants amb nota de vest[0..nest-1] */
  int nest_amb_nota;
    /** @brief És la suma de les notes (dels estudiants amb nota) de vest[0..nest-1] */
  double suma_notes;

   /** @brief Ordenar el conjunt d'estudiants. 
      \pre <em>cert</em>
      \post Els elements del paràmetre implícit passen a estar ordenats
     creixentment per DNI.
  */

  void ordenar_cjt_estudiants();
     
   /** @brief Cerca dicotomica d'un DNI. 
      \pre Els elements de vest estan ordenats creixentment per DNI,
     0<=left, right<vest.size(), right>=left-1
      \post Si x hi és vest[left..right], el resultat és la posició que
     hi ocupa, si no, és la posició que hauria d'ocupar
  */

  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  
public:
  //Constructores

   /** @brief Creadora per defecte. 
      \pre <em>cert</em>
      \post Crea un conjunt d'estudiants buit
  */

  Cjt_estudiants();

  //Modificadores
   
   /** @brief Afegir un estudiant a un conjunt. 
      \pre El paràmetre implícit no està ple
      \post b = indica si el p.i. original contè un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al paràmetre implícit
  */

  void afegir_estudiant(const Estudiant &est, bool& b);

  /** @brief Esborrar un estudiant d'un conjunt. 
      \pre <em>cert</em>
      \post b indica si el paràmetre implícit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del paràmetre implícit 
  */

  void esborrar_estudiant(int dni, bool& b);

  //Consultores

  /** @brief Mida d'un conjunt. 
      \pre <em>cert</em>
      \post El resultat és el nombre d'estudiants del paràmetre implícit
  */
  
  int mida() const;

  /** @brief Consultora de la mida màxima d'un conjunt. 
      \pre <em>cert</em>
      \post El resultat es el nombre maxim d'estudiants que pot arribar
     a tenir el parametre implicit
  */

  static int mida_maxima();
  
   /** @brief Consulta de la mitjana dels estudiants amb nota d'un conjunt. 
      \pre <em>cert</em>
      \post El resultat és la mitjana de les notes dels estudiants amb nota
     del paràmetre implícit; si no n'hi ha cap, el resultat és -1
  */

  double mitjana_estudiants_amb_nota() const;

  // Lectura i escriptura
	
   /** @brief Lectura d'un conjunt d'estudiants. 
      \pre <em>cert</em>
      \post El paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndard d'entrada
  */

  void llegir();

   /** @brief Escriptura d'un conjunt d'estudiants. 
      \pre <em>cert</em>
      \post S'han escrit pel canal estàndard de sortida 
     els estudiants del conjunt que conté el paràmetre 
     implícit en ordre ascendent per DNI
  */

  void escriure() const;

};

#endif
