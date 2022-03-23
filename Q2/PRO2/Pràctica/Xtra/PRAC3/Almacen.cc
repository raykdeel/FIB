/** @file Almacen
    @brief Código de la clase Almacen
*/
#include "Almacen.hh"


Almacen::Almacen() 
{ 
}
Almacen::Almacen(BinTree<int> aux) 
{
  estructura_almacen=aux;
 
}

BinTree<int> Almacen::consultar_almacen(){
    return estructura_almacen; // devuelve el p.i. del almacen
}



Almacen Almacen::leer_almacen()
{   
    int x;
    cin>>x ;
    if( x!=0){  //marca
        Almacen e,d;
        e=leer_almacen();
        d=leer_almacen();
        estructura_almacen= BinTree<int> (x, e.consultar_almacen(), d.consultar_almacen());
    }
    else return Almacen(); //devuelve un almacen vacio
    return Almacen(estructura_almacen);
   

}

void Almacen::escribir() 
{   
    cout<<estructura_almacen.value()<<" ";
    Almacen a;
    if(!estructura_almacen.left().empty()){
        a=Almacen(estructura_almacen.left());
        a.escribir();
    }
    if(!estructura_almacen.right().empty()){
        a=Almacen(estructura_almacen.right());
        a.escribir();
    }

}



