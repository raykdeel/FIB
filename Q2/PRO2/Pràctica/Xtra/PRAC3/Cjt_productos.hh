/** @file Cjt_productos.hh
    @brief Especificación de la clase Cjt_productos 
*/

#ifndef _CJT_PRODUCTOS_HH_
#define _CJT_PRODUCTOS_HH_


#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no 
#include <map>              // incluya estas clases en los diagramas modulares, 
#include <string>           // mientras que el compilador de c++ 
#include <iostream>         // sí que las procesa correctamente

#endif                        
using namespace std;

/** @class Cjt_productos
    @brief Representa el inventario del almacen con atributos identificador y unidades
*/
class Cjt_productos
{
public:

  //Modificadoras

  /** @brief Modificadora con valores concretos.

	Se introduce un identificador de producto. Si el producto
    ya existia se produce un error, sino el producto se da de alta en el
    sistema con cero unidades. 
      \pre iden_prod>0 
      \post El resultado es una prenda con identificador "iden_prod" y unidades "uni_prod" 0
 */   
 void poner_prod(string iden_prod);


/** @brief Destructora con valores concretos. 

	Se introduce un identificador de producto. Si el producto
no existe, o ya existe y quedan unidades se produce un error, sino el
producto se da de baja en el sistema.
      \pre iden_prod >0 
      \post El resultado es que el producto se da de baja del sistema
  */   
  void quitar_prod(string iden_prod);

  /** @brief Modificadora de los atributos

	Se introduce un identificador de producto y sus unidades. Si el 
    producto no existe o sus unidades son negativas da error. Sino 
    el parametro implicito del producto con "iden_prod" pasa a tener
     "uni_prod" unidades 
      \pre iden_prod>0   uni_prod>=0
      \post El parámetro implícito pasa a tener identificador "iden_prod"y 
      unidades "uni_prod" 
  */
  void modificar(string iden_prod, int uni_prod);
  
  //Consultoras

  /** @brief Consultora de las unidades

	Se introduce un identificador de producto. Si no existe,
se produce un error. Si existe se escribe cuantas unidades hay en
total en el almacen.
      \pre <em>cierto</em>
      \post El resultado son las unidades del parámetro implícito
  */
  int consultar_prod(string iden_prod);

  /** @brief Consultora de producto

	Se introduce un identificador de producto. Si no existe 
    devuelve falso. Si existe devuelve true.
      \pre <em>cierto</em>
      \post El resultado es un booleano
  */
  bool existe_prod(string iden_prod);
 

  //Escritura de productos

  /** @brief Operación de escritura
   
   Escribe por pantalla el inventario del almacen
      \pre <em>cierto</em>
      \post Se han escrito los identificadores de producto que hay 
      las estanterias. 
  */
  void escribir();

private:
	
    /** @brief inventario del almacen  */
    map<string, int> map_productos;
    /** @brief iterador del inventario del almacen  */
    map<string,int>::iterator it;
};

#endif
