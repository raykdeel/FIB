 /** @file ConsultaBool.hh
    @brief Especificacio de la clase ConsultaBool.
 */
#ifndef CONSULTABOOL_IO_HH
#define CONSULTABOOL_IO_HH
 
 
#include "fecha.hh"  
  
#ifndef NO_DIAGRAM
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "BinTree.hh"
#endif

using namespace std;



/** @class ConsultaBool
    @brief representa una foto con su fecha y sus etiquetas.    
 */
class ConsultaBool {

private:
    
   struct token {
        string tipo; // tipo de la consulta: TAG, DATE, AND, OR o NOT
        string etq; // si tipo == "TAG", esta es la etiqueta
        fecha fini, ffin; // si tipo == "DATE", estas son las fechas de inicio y fin
                      // se asume que existe una clase Fecha y que hay una operacion para
                      // leer fechas
    };
        /** @brief Retorna el arbol que hemos creado.
        \pre <em>cierto</em>
        \post Retorna el arbol que hemos creado.
        */
    BinTree<pair<string,pair<string,pair<fecha,fecha>>>> ar;
    
    void read_input(istream& is, vector<token>& l);
        /** @brief Creamos un arbol con valor tag y s.
        \pre <em>cierto</em>
        \post Creamos el arbol.
        */
    ConsultaBool(const string& s);
        /** @brief Creamos un arbol con valor date y las fechas.
            \pre <em>cierto</em>
            \post Creamos el arbol.
        */
    ConsultaBool(const fecha& fini,const fecha& ffin);
       
    ConsultaBool construct_bool_query(const vector<token>& postfix);
    
public:
    //constructora
    /** @brief constructora por defecto.
    s'executa automaticament al declarar una foto.
    \pre <em>cierto</em>
    \post tenemos una foto vacia
    */
    
    
    /** @brief constructora, crea una consulta TAG con la etiqueta s
     \pre
     \post
     */
    ConsultaBool();
    
//modificadora
    /** @brief crea una foto
     \pre <em>cierto</em>
     \post la foto ha sido creada
     */
    void read(istream& is);
        /** @brief Creamos un arbol de valor and con el nodo q1 y q2.
        \pre <em>cierto</em>
        \post devolvemos ConsultaBool.
        */
    ConsultaBool AND(const ConsultaBool& q2);
         /** @brief Creamos un arbol de valor or con el nodo q1 y q2.
        \pre <em>cierto</em>
        \post devolvemos ConsultaBool.
        */
    ConsultaBool OR(const ConsultaBool& q2);
         /** @brief Creamos un arbol de valor not con el nodo q1 y un nodo vacio.
        \pre <em>cierto</em>
        \post devolvemos ConsultaBool.
        */
    ConsultaBool NOT();

    BinTree<pair<string,pair<string,pair<fecha,fecha>>>> consultararbol();
    void convert_infix_to_postfix(const vector<token>& infix, vector<token>& postfix);


    

};

#endif
