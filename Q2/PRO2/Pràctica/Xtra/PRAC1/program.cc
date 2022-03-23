//sergio jesus sadornil garces grupo 42 pro2


/**
  @mainpage Especifiacio de la parctica de pro de Sergio Sadornil
 */

/** @file main.cc
  @brief Programa principal per la practica <em> coleccion de imagenes</em>.
 */


#include "coleccion.hh"
#include "fecha.hh"
#ifndef NO_DIAGRAM //doxyfile no incluira estas clases a la representacion
#include <iostream>
#include <string>
#endif


int main(){
    string op,nom;
    coleccion c;
    cin>>op;
    while(op!="acabar") {
            if(op=="lee_album"){
                cin >> nom;
                cout << "# lee_album " << nom << " ..."<<endl;
                c.leer_album(nom);
            }
            else if(op=="agrega_foto") {
                cin>> nom;
                cout << "# agrega_foto "<< nom<<" ..."<<endl;
                c.modificar_album("agregar",nom);
            }
            else if(op=="elimina_foto") {
                cin>> nom;
                cout << "# elimina_foto "<< nom<<endl;
                c.modificar_album("eliminar",nom);
                }
            else if(op=="obten_foto") {
                cin>> nom;
                cout << "# obten_foto "<< nom<<endl;
                c.obten_foto(nom);
                }
            else if(op=="nr_fotos") {
                cout << "# nr_fotos"<<endl;
                c.nr_fotos();
                }
            else if(op=="agrega_album") {
                cout << "# agrega_album"<<endl;
                c.agrega_album();
                }
            else if(op=="elimina_album") {
                cin >> nom;
                cout << "# elimina_album " << nom <<endl;
                c.eliminar_album(nom);
                }
            else if(op=="obten_album") {
                cin >> nom;
                cout << "# obten_album " << nom << endl;
                c.obten_album(nom);
                }
            else if(op=="nr_albums") {
                cout << "# nr_albums"<<endl;
                c.imprimir_nr_albums();
                }
            else if(op=="lista_albumes") {
                cout << "# lista_albumes"<<endl;
                c.lista_albumes();
                }
            else if(op=="agrega_foto_coleccion") {
                cin>>nom;
                cout << "# agrega_foto_coleccion "<<nom<<" ..."<<endl;
                c.modificar_all(nom,"agrega");
                }
            else if(op=="elimina_foto_coleccion") {
                cin>>nom;
                cout << "# elimina_foto_coleccion "<<nom<<endl;
                c.modificar_all(nom,"elimina");
                }
            else if(op=="modifica_foto_coleccion") {
                cin>> nom;
                cout << "# modifica_foto_coleccion "<<nom<<" ..."<<endl;
                c.modificar_foto_col(nom);
                }
            else if(op=="albumes_foto") {
                cin >> nom;
                cout << "# albumes_foto "<<nom<<endl;
                c.albumes_foto(nom);
                }
            else if(op=="busca_por_fecha") {
                fecha f1;
                fecha f2;
                string n;
                f1.llegir();
                f2.llegir();
                cin>>nom>>n;
                cout<< "# busca_por_fecha ";
                f1.escribir();
                cout<< "-";
                f2.escribir();
                cout <<" "<<nom<<" "<<n<<endl;
                c.buscar_por_fecha(nom,n,f1,f2);
            } 
            else if(op=="busca_por_etiqueta") {
                string s,n;
                cin>>s>>nom>>n;
                cout<< "# busca_por_etiqueta "<<s<<" "<<nom<<" "<<n<<endl;
                c.buscar_por_etiq(s,nom,n);
                }
             else if(op=="evalua_consulta_booleana") {
                string n;
                cin>>nom>>n;
                cout << "# evalua_consulta_booleana "<<nom<<" "<<n<<endl; 
                cout <<"# BEGIN_QUERY ... END_QUERY"<<endl;
                c.evalua_const_bool(nom,n);
                }
            else if(op=="imprime_album_en_curso") {
                cout << "# imprime_album_en_curso"<<endl;
                c.escribir_aec();
                }
            else if(op=="imprime_coleccion") {
                cout <<"# imprime_coleccion"<<endl;
                c.escribir_col();
                }
            else{};
            cin >> op;
        }
}
