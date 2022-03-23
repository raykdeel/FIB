 /** @file foto.hh
    @brief Especificacio de la clase foto.
 */
#ifndef FOTO_HH
#define FOTO_HH
  
#include "fecha.hh"  
  
#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#include <string>
#endif

using namespace std;


/** @class foto
    @brief representa una foto con su fecha y sus etiquetas.    
 */
class foto {
    
public:
    //constructora
    /** @brief constructora por defecto de la clase foto.
    \pre <em>cierto</em>
    \post tenemos una foto vacia.
    */
    foto();
    
//modificadora
    /** @brief Llama a la funcion leer de fecha 
     y lee el numero de etiquetas y las etiquetas de la foto.
     Ademas si la foto no estaba vacia la limpia antes de leer
     \pre <em>cierto</em>
     \post la foto ha sido creada
     */
    void llegir();

//consultora
    /** @brief nos dice si hay alguna foto con la etiqueta dada
    \pre <em>cierto</em>
    \post si ha encontrado la etiqueta nos devuleve cierto sino falso
    */
bool consultar_etiqueta(const string& s) const;

    /** @brief nos dan 2 fechas y hemos de devolver
    si la foto esta entre las 2 fechas
    \pre <em>cierto</em>
    \post si la foto esta entre las 2 fechas devuelve cierto sino falso
    */
bool consultar_fecha(const fecha& f1,const fecha& f2) const;

//escritura

    /** @brief escribe la informacion de la foto
     \pre <em>cierto</em>
     \post escribe la foto
     */
void escribir_foto() const;


private:
    fecha fec; //fecha de la foto
    int n;     //numero de etiquetas
    set<string>etiq; //set de etiquetas
};

#endif
