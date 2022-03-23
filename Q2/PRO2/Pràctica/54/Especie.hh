/** @file Especie.hh
    @brief Especificació de la classe Especie 
*/

#ifndef NO_DIAGRAM 
#include <iostream>
#include <map>
#include <vector>
#endif

using namespace std;

/** @class Especie
    @brief Representa una espècie amb un identificador i un gen.

     Conté l'identificador d'una espècie, i el seu gen, tots dos strings.
*/


class Especie {
    
  private: 

    /** @brief Identificador de l'espècie. */ 
    string identifier;
    /** @brief Gen de l'espècie. */
    string gene;
    /** @brief Map dels kmers (subseqüències) del gen de l'espècie. */
    map<string, int> kmer;
    /** @brief Map de les distancies d'un cluster a la resta. */
    //map<string, double> species_distances;
    
  public:

    //CONSTRUCTORES

  /** @brief Constructora per defecte. 
   
    S'executa automàticament al declarar una espècie.   

      \pre <em>cert</em>
      \post El resultat és una espècie amb identificador i gen no vàl·lids
  */

    Especie();

  /** @brief Constructora d'una espècie amb un identificador, un gen i el map de kmers.
   
    Crea un espècie amb l'identificador i el gen donats, i inicialitza el 
    map kmer amb el gen i la k.
    
      \pre <em>cert</em>
      \post El resultat és una espècie amb identifier = id i gene = g, i 
      kmer inicializat.
  */

    Especie(string id, string g, int k);

    //MODIFICADORES

    /** @brief Modificadora del species_distancies de l'espècie. 
     
      Assigna a l'espècie del paràmetre implícit un map<string, double> 
      substituint species_distances.
     
      \pre <em>cert</em>
      \post Modifica l'espècie del paràmetre implícit i subtitueix 
      species_distances amb l'element del paràmetre.
    */

    void modify_distances(map<string,double> aux);

   /** @brief Conjunt de subseqüències contigües de g de longitud k.
     
     Retorna un map<string, int> on estan ordenades alfabèticament les
      subseqüències de longitud k del gen amb la seva freqüència.
  
      \pre <em>cert</em>
      \post Retorna un map<string,int> d'strings amb totes les subseqüències
       contigües de g (gen) de longitud k ordenades.
  */

    map<string, int> create_kmer(string g, int k) ;

    //CONSULTORES

  /** @brief  Consulta de l'identificador d'una espècie. 

    Retorna l'identificador de l'espècie del paràmetre implícit.

      \pre <em>cert</em>
      \post El resultat és l'identificador del paràmetre implícit.
  */

    string query_identifier() const;

  /** @brief  Consulta del gen d'una espècie.
    
    Retorna el gen de l'espècie del paràmetre implícit.
     
      \pre <em>cert</em>
      \post El resultat és el gen del paràmetre implícit.
  */

    string query_gene() const;

  /** @brief Consulta del kmer de l'espècie.
    
    Retorna el map<string, int> que emmagatzema les distancies entre l'espècie
     del paràmetre implícit i la resta d'espècies del conjunt d'espècies.
     
      \pre <em>cert</em>
      \post El resultat el map kmer del paràmetre implícit.
  */

    map<string, int> query_kmer();

  /** @brief Consulta del species_distances de l'espècie.
    
    Retorna el map<string, double> que emmagatzema alfabèticament les 
    subseqüències de longitud k del gen amb la seva freqüència.
     
      \pre <em>cert</em>
      \post El resultat el map species_distances del paràmetre implícit.
  */

    //map<string, double> query_distances();

    //LECTURA I ESCRIPTURA

  /** @brief  Lectura d'una espècie.
   * 
   Assigna a la espècie del paràmetre implícit l'identificador i el gen 
   llegits. També calcula el kmer de l'espècie.
   * 
      \pre Hi ha preparats al canal estandar d'entrada dos strings.
      \post El paràmetre implícit passa a tenir els atributs llegits 
     del canal estàndard d'entrada.
  */

    void read_single_species(int k);
    
  /** @brief Escriptura de species_distances de l'espècie del paràmetre implícit. 
   
    Escriu pel canal estàndard de sortida la distància entre l'espècie del
    paràmetre implícit i la resta d'espècies del conjunt d'espècies.
   
      \pre <em>cert</em>
      \post Escriu pel canal estàndard de sortida l'atribut species_distances.
  */
    
    //void print_species_distances();
    
};