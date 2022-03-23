/** @file Almacen.hh
    @brief Especificación de la clase Almacen 
*/

#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_

#ifndef NO_DIAGRAM  
#include <iostream>
#include "BinTree.hh"

#endif

/** @class Almacen
    @brief Representa la estructura del almacen 

    Representa la estructura del almacen con un arbol en que cada
     nodo contiene el identificador de sala
*/
class Almacen
  {

public:
  //Constructoras 

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un almacen.
      \pre <em>cierto</em>
      \post El resultado es un almacen
  */  
  Almacen();
    
    /** @brief Copiadora por defecto. 
     
      Se introduce un arbol y devuelve un almacen
      
      \pre <em>cierto</em>
      \post El resultado es un almacen
  */  
  Almacen(BinTree<int> aux); 

 /** @brief Consultora del almacen. 
    
    Devuelve el arbol del parametro implcito estructura_almacen
      
      \pre <em>cierto</em>
      \post El resultado es el arbol de la estructura del almacen
  */  
  BinTree<int> consultar_almacen();

  // Lectura y escritura del almacen

/** @brief Se lee la distribucion de las salas del almacen 
 
 En el canal estandard hay una serie de enteros, si el entero es 0 significa 
 que el arbol no continua por uno de los subarboles posibles
      \pre En el canal estandard de entrada estan preparados una
      serie de enteros que representan la estructura del almacen
      \post El parámetro implícito contiene un arbol que representa la estructura
      del almacen teniendo en cuenta los parametros entrados
  */
  Almacen leer_almacen();


  /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
  */
  void escribir();

private:
/** @brief Arbol que representa la estructura del almacen  */
  BinTree<int> estructura_almacen;
};
#endif
