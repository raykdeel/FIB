/** @file Cjt_salas.hh
    @brief Especificación de la clase Cjt_salas
*/

#ifndef _CJT_SALAS_HH_
#define _CJT_SALAS_HH_

#include "Sala.hh"

#ifndef NO_DIAGRAM 
#include <vector>
#endif


/** @class Cjt_salas
    @brief Representa un conjunto de salas. 

    Puede contener las diferentes salas de un almacen con las caracteristicas de cada sala
*/
class Cjt_salas
{
public:
  
  //Modificadoras  

    /** @brief Añade varias unidades de un producto a la sala

        Se introduce un identificador de sala, un identificador
    de producto y una cantidad. Si el producto no existe se produce un
    error. Se colocan tantas unidades como quepan en la sala y se devuelve
    un entero que indique cuantas unidades no han cabido. Se colocaran
    las unidades lo antes posible, es decir, primero se rellenan los huecos
    a partir del hueco que vaya antes. Las unidades que no quepan no se
    guardan en el almacen.
      \pre 1<=iden_sala<=n   iden_prod>0   uni_prod>0 
      \post El parámetro implícito pasa a contener sus productos originales más las unidades añadidas 
  */
  int poner_items(int iden_sala, string iden_prod, int uni_prod);
  
  /** @brief Quita varios productos de la sala

	Se introduce un identificador de sala, un identificador
de producto y una cantidad. Si el producto no existe se produce un
error. Se quitan tantas unidades como se pueda y se devuelve un entero
que indique cuantas unidades no se han podido quitar porque no habia
suficientes en la sala. Se comenzara quitando las unidades que vayan
antes.
      \pre 1<=iden_sala<=n   iden_prod>0   uni_prod>0 
      \post El parámetro implícito pasa a contener sus productos originales más p 
  */
  int quitar_items(int iden_sala, string iden_prod, int uni_prod);

   /** @brief Compacta una estanteria
  
  Se introduce un identificador de sala y se compacta su
estanteria.
      \pre 1<=iden_sala<=n
      \post La estanteria queda compactada.
  */
  void compactar (int iden_sala);
  
  /** @brief Reorganiza una estanteria
  
  Se introduce un identificador de sala y se reorganiza su
estanteria.
      \pre 1<=iden_sala<=n
      \post La estanteria queda reorganizada.
  */
  void reorganizar (int iden_sala);
  
  /** @brief Compacta una estanteria
  
  Se introduce un identificador de sala y el nuevo numero
de filas y el nuevo numero de columnas. Si los productos que hay
en la sala no caben en las nuevas dimensiones se produce un error.
En caso contrario se compacta la estanteria y pasa a tener las nuevas
dimensiones.
      \pre 1<=iden_sala<=n   num_fil>0   num_col>0
      \post Se compacta la estanteria y pasa a tener las nuevas
dimensiones 
  */
  void redimensionar (int iden_sala, int filas, int columnas);

  //Consultoras;

/** @brief Consultora de un producto
  
  Se introduce un identificador de sala y una posicion de la estanteria
      \pre cierto
      \post Se indica que producto hay en la posicion correspondiente de la 
      estanteria de dicha sala, si no hay producto se escribe NULL
  */
  string consultar_pos(int iden_sala, int filas, int columnas);



  // Lectura i escritura de un conjunto de salas

   /** @brief Operación de escritura

   Por orden de identificador de sala se leeran las dimensiones (filas, columnas)
   de la estanteria de cada sala
      \pre En el canal estandard de entrada estan preparados dos enteros (filas,columnas) 
      y sabemos que pertenecen a las dimensioned de la sala "iden_sala"
      \post El parametro implicito pasa a tener los atributos leidos en el canal 
      estandard de entrada, si los enteros son negativos da error 
  */
  void leer(int num_sala);

  /** @brief Operación de escritura

 Se introduce un identificador de sala. Se escribe el contenido
de la estanteria de arriba a abajo y de izquierda a derecha. En
los huecos escribiremos NULL y por tanto no podra ser un identificador
valido de producto. Tambien escribiremos cuantas unidades hay en total
y por orden de identificador de producto existente en la estanteria,
escribiremos el identificador de producto y su cantidad.
      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida
  */
  void escribir(int iden_sala);


private:
/** @brief Vector que representa el conjunto de salas del almacen  */
    vector< Sala> vec_salas;

};
#endif