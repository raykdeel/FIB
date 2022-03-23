/** @file Cjt_salas.cc
    @brief Código de la clase Cjt_salas
*/

#include "Cjt_salas.hh"


int Cjt_salas::poner_items(int iden_sala, string iden_prod, int uni_prod)
{ //falta mirar si el producto existe y actualizar el inventario 
  
  return vec_salas[iden_sala-1].poner_items_sala(iden_prod,uni_prod);
}

int Cjt_salas::quitar_items(int iden_sala, string iden_prod, int uni_prod)
{ //falta mirar si el producto existe

  return vec_salas[iden_sala-1].quitar_items_sala(iden_prod,uni_prod);
  
}


void Cjt_salas::compactar (int iden_sala) 
{

    int fil=vec_salas[iden_sala-1].consultar_filas(), col=vec_salas[iden_sala-1].consultar_columnas();
    vec_salas[iden_sala-1].cambiar_estanteria(fil,col); //si redimensionamos la sala con las mismas medidas
    //el resultado es la sala compactada
 
}

void Cjt_salas::reorganizar (int iden_sala) 
{
  vec_salas[iden_sala-1].reorganizar();
  
}

void Cjt_salas::redimensionar (int iden_sala, int filas, int columnas) 
{
  
  vec_salas[iden_sala-1].cambiar_estanteria(filas, columnas);

}

string Cjt_salas::consultar_pos(int iden_sala, int filas, int columnas)
{
  
  return vec_salas[iden_sala-1].consultar_producto(filas, columnas);
  
}

void Cjt_salas::leer(int num_sala)
{
  Sala aux;
  vector<Sala> vec_aux(num_sala);
  vec_salas=vec_aux;
  for(int i=0; i<num_sala;i++){
    aux.leer();
    vec_salas[i]=aux; // lee las medidas de las estanterias por odren
  }
  
  
}

void Cjt_salas::escribir(int iden_sala)
{
  vec_salas[iden_sala-1].escribir();
  
}

