#include <iostream>
#include "BinTree.hh"

class Almacen
  {
public:
  //Constructoras
  Almacen();
  Almacen(BinTree<int> aux); 
  BinTree<int> consultar_almacen();
  // Lectura y escritura del almacen
  Almacen leer_almacen();
  void escribir();
private:
  BinTree<int> estructura_almacen;
};
#endif
