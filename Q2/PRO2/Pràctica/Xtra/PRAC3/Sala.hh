/** @file Sala.hh
    @brief Especificación de la clase Sala
*/

#ifndef _SALA_HH_
#define _SALA_HH_

#ifndef NO_DIAGRAM 

#include <vector>
#include <map>
#include <string>
#include <iostream>


#endif
using namespace std;

/** @class Sala
    @brief Representa una sala del almacen. 

    Cada sala tendra una estanteria con f filas y c columnas. Las
    dimensiones de las estanterias no son necesariamente iguales
    en todas las salas.
    Las dimensiones de una estanteria se pueden cambiar en cualquier momento
    bajo ciertas condiciones.
*/
class Sala
{
public:
 
  //Modificadoras

 /** @brief Modificadora de la estanteria de la sala
  
    Modifica el tamaño de las estanterias teniendo en cuenta que los 
    productos que habia en la estanteria antigua caben en la nueva. 
    \pre fil>0   col>0
    \post La sala cambia las medidas de su estanteria
  */
  void cambiar_estanteria(int fn, int cn);

  /** @brief Modificadora de los productos de la estanteria
  
    Añade productos a la estanteria, si no los puede añadir todos 
    devuelve el numero de productos sobrantes 
    \pre iden_prod>0  uni_prod>0
    \post Se han añadido los productos a la estanteria
  */
  int poner_items_sala(string iden_prod, int uni_prod) ;

  /** @brief Modificadora de los productos de la estanteria
  
    Se introduce un identificador de producto y una cantidad. 
    Si el producto no existe se produce un error. Se quitan tantas 
    unidades como se pueda y se devuelve un entero que indique cuantas
    unidades no se han podido quitar porque no habia suficientes en la
    sala. Se comenzara quitando las unidades que vayan antes.
    \pre iden_prod>0  uni_prod>0
    \post Se han quitado los productos de la estanteria
  */
  int quitar_items_sala(string iden_prod, int uni_prod);

  /** @brief Reorganiza una estanteria
  
  Se reorganiza su estanteria en orden alfabetico.
      \pre cierto
      \post La estanteria queda reorganizada. 
  */
  void reorganizar ();

//Consultoras

  /** @brief Consultora filas de la estanteria
     
    \pre cierto
    \post Devuelve el numero de filas
  */
  int consultar_filas();

/** @brief Consultora columnas de la estanteria
     
    \pre cierto
    \post Devuelve el numero de columnas
  */
  int consultar_columnas();

/** @brief Consultora de productos de la estanteria
     
    \pre cierto
    \post Devuelve el numero de columnas
  */
  string consultar_producto(int filas, int columnas);

  // Lectura i escritura de una sala

  /** @brief Operación de lectura

    \pre En el canal estandard de entrada estan preparados dos enteros (filas,columnas)
    \post El parametro implicito pasa a tener los atributos leidos en el canal 
     estandard de entrada, si los enteros son negativos da error 
  */
  void leer();

  /** @brief Operación de escritura

    Se escribe el contenido de la estanteria de arriba a abajo y de 
    izquierda a derecha. En los huecos escribiremos NULL y por tanto
    no podra ser un identificador valido de producto. Tambien
    escribiremos cuantas unidades hay en total y por orden de 
    identificador de producto existente en la estanteria,
    escribiremos el identificador de producto y su cantidad.
      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida
  */
  void escribir();

private:
/** @brief Filas de la estanteria  */
    int filas;
    /** @brief Columnas de la estanteria */
    int columnas;
    /** @brief Matriz que representa la estanteria  */
    vector< vector <string> > estanterias;
    /** @brief Inventario de la sala  */
    map<string, int> map_prod_sala;
    /** @brief Iterador del inventario de la sala  */
    map<string, int>::iterator it;
    /** @brief Variable con el total de productos  */
    int total_prod;
};
#endif
