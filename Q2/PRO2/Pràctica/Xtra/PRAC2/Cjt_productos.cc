/** @file Cjt_productos.cc
    @brief Código de la clase Cjt_productos
*/

#include "Cjt_productos.hh"

void Cjt_productos::poner_prod(string iden_prod) 
{
  if(iden_prod>""){
    it=map_productos.find(iden_prod);
    if(it==map_productos.end()){
      map_productos[iden_prod]=0; //pone producto con 0 unidades
    }
    else cout<<"  error"<<endl;
  }
  else  cout<<"  error"<<endl;
  
}

void Cjt_productos::quitar_prod(string iden_prod)
{
  if(iden_prod>""){
    it=map_productos.find(iden_prod);

    if(it!=map_productos.end()){

      if(it->second==0){

        map_productos.erase(iden_prod); //elimina si tiene 0 unidades
      }
      else cout<<"  error"<<endl;
    }
    else cout<<"  error"<<endl;
  }
  else  cout<<"  error"<<endl;

}

void Cjt_productos::modificar(string iden_prod, int uni_prod)
{
  if(iden_prod>"" and uni_prod>=0){
    it=map_productos.find(iden_prod);
    if(it!=map_productos.end()){
      it->second= uni_prod; 
    }
    else cout<<"  error"<<endl;
  }
  else cout<<"  error"<<endl;
}

int Cjt_productos::consultar_prod(string iden_prod) 
{
  if(iden_prod>"" ){
    it=map_productos.find(iden_prod);
    if(it!=map_productos.end()){
      return  it->second;
    }
    else cout<<"  error"<<endl;
  }
  else cout<<"  error"<<endl;
  return -1;
}

bool Cjt_productos::existe_prod(string iden_prod) 
{
  it=map_productos.find(iden_prod);
  if(it!=map_productos.end()){
    return  true;
  }
  else return false; 
}

void Cjt_productos::escribir()  
{
  it = map_productos.begin();
  while(it!=map_productos.end()){
    cout<<"  "<<it->first<<" "<<it->second<<endl;
    it++;
 }
}

