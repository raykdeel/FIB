/**
 * @mainpage Ejemplo de diseño modular:  Gestión de un almacen.
 
En esta practica se construye un programa modular que ofrece un menú de opciones 
para gestionar un almacen. Se introducen las clases <em>Cjt_productos</em>, 
<em>Sala</em>, <em>Cjt_salas</em> y <em>Almacen</em>.

*/

/** @file program.cc
    @brief Programa principal para el ejercicio <em>Gestión de un almacen</em>.
*/



#include "Cjt_productos.hh"
#include "Sala.hh"
#include "Cjt_salas.hh"
#include "Almacen.hh"

#ifndef NO_DIAGRAM 
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "BinTree.hh"
#endif
using namespace std;


int distribuir_almacen(BinTree<int> a, Cjt_salas& almacen , Cjt_productos& inventario, string iden_prod, int uni_prod){
    if(!a.left().empty() and !a.right().empty() and uni_prod>0  ){ //entra si nodo con hijos
        int aux;
        aux= almacen.poner_items(a.value(), iden_prod, uni_prod); //devuelve los que no se han puesto en la sala
        aux=uni_prod-aux; //los productos puestos
        inventario.modificar(iden_prod,(inventario.consultar_prod(iden_prod)+aux) ); // añadimos al inventario
        uni_prod-=aux;
        int rest=0, rest1=0;
        rest = distribuir_almacen(a.left(),almacen, inventario,iden_prod,(uni_prod/2)+(uni_prod%2));
        rest1 = distribuir_almacen(a.right(),almacen, inventario,iden_prod,uni_prod/2);
        return rest+rest1; // productos no puestos en el almacen
    }
    else if(uni_prod  ==  0 ) return 0;
    else { //llega a un nodo sin hijos
        int aux;
        aux= almacen.poner_items(a.value(), iden_prod, uni_prod); //devuelve los que no se han puesto en la sala
        aux=uni_prod-aux; //los productos puestos
        inventario.modificar(iden_prod,(inventario.consultar_prod(iden_prod)+aux) ); // añadimos al inventario
        uni_prod-=aux;
        return uni_prod;

    }

}

/** @brief Programa principal para el ejercicio <em>Gestión de un almacen</em>.
*/

int main ()
{
    int n;
    cin>> n;
    Almacen estructura;
    Cjt_productos inventario;
    Cjt_salas almacen;

    estructura.leer_almacen();    
    almacen.leer(n);
    
    string opcio;
    while(cin>>opcio ){
        if(opcio == "poner_prod"){
            string iden_prod;
            cin>>iden_prod;
            
            cout<<opcio<<" "<<iden_prod<<endl;
            inventario.poner_prod(iden_prod);
        }
        else if(opcio == "quitar_prod"){
            string iden_prod;
            cin>>iden_prod;
            cout<<opcio<<" "<<iden_prod<<endl;
            inventario.quitar_prod(iden_prod);
        }
        else if(opcio == "poner_items"){ //
            int iden_sala, uni_prod, aux;
            string iden_prod;
            cin>>iden_sala>>iden_prod>>uni_prod;
            cout<<opcio<<" "<<iden_sala<<" "<<iden_prod<<" "<<uni_prod<<endl;
            if(inventario.existe_prod(iden_prod)){
                aux=almacen.poner_items(iden_sala,iden_prod,uni_prod);
                if(aux!=-1) cout<<"  "<<aux<<endl;
                aux=uni_prod-aux; // productos en el almacen
                inventario.modificar(iden_prod,(inventario.consultar_prod(iden_prod)+aux) ); //actualizar inventario
            }
            else cout<<"  error"<<endl;
        }
        else if(opcio == "quitar_items"){//
            int iden_sala, uni_prod, aux;
            string iden_prod;
            cin>>iden_sala>>iden_prod>>uni_prod;
            cout<<opcio<<" "<<iden_sala<<" "<<iden_prod<<" "<<uni_prod<<endl;
            if(inventario.existe_prod(iden_prod)){
                aux=almacen.quitar_items(iden_sala,iden_prod,uni_prod);
                if(aux!=-1) cout<<"  "<<aux<<endl;
                aux=uni_prod-aux; // productos que se han quitado del almacen
                inventario.modificar(iden_prod,(inventario.consultar_prod(iden_prod)-aux) ); // actualizar inventario
            }
            else cout<<"  error"<<endl;

        }
        else if(opcio == "distribuir"){ //
            string iden_prod;
            int uni_prod;
            cin>> iden_prod>>uni_prod;
            cout<<opcio<<" "<<iden_prod<<" "<<uni_prod<<endl;
            if( inventario.existe_prod(iden_prod) ){
                cout<<"  "<<distribuir_almacen(estructura.consultar_almacen(),almacen,inventario,iden_prod,uni_prod)<<endl;
                //imprime por pantalla los productos que no se han guardado en el almacen
            }
            else cout<<"  error"<<endl;

        }
        else if(opcio == "compactar"){ //
            int iden_sala;
            cin>> iden_sala;
            cout<<opcio<<" "<<iden_sala<<endl;
            almacen.compactar(iden_sala);

        }
        else if(opcio == "reorganizar"){ //
            int iden_sala;
            cin>>iden_sala;
            cout<<opcio<<" "<<iden_sala<<endl;
            almacen.reorganizar(iden_sala);
        }
        else if(opcio == "redimensionar"){ //
            int iden_sala, filas, columnas;
            cin>>iden_sala>>filas>>columnas;
            cout<<opcio<<" "<<iden_sala<<" "<<filas<<" "<<columnas<<endl;
            almacen.redimensionar(iden_sala,filas,columnas);
        }
        else if(opcio == "inventario"){
            cout<<opcio<<endl;
            inventario.escribir();
        }
        else if(opcio == "escribir"){
            int iden_sala;
            cin>> iden_sala;
            cout<<opcio<<" "<<iden_sala<<endl;
            almacen.escribir(iden_sala);
        }
        else if(opcio == "consultar_pos"){
            int iden_sala, filas, columnas;
            cin>>iden_sala>>filas>>columnas;
            cout<<opcio<<" "<<iden_sala<<" "<<filas<<" "<<columnas<<endl;
            string aux=almacen.consultar_pos(iden_sala,filas,columnas);
            if(aux!="")cout<<"  "<<aux<<endl;

        }
        else if(opcio == "consultar_prod"){
            string iden_prod;
            cin>> iden_prod;
            cout<<opcio<<" "<<iden_prod<<endl;
            int aux=inventario.consultar_prod(iden_prod);
            if(aux!=-1)cout<<"  "<<aux<<endl;

        }
        else if(opcio == "fin"){
            cout<<opcio<<endl;
            break;
        }
    }

}
