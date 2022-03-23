/** @file Sala.cc
    @brief Código de la clase Sala
*/

#include "Sala.hh"

int Sala::consultar_filas()
{
    return filas;
}

int Sala::consultar_columnas()
{
    return columnas;
}


void Sala:: cambiar_estanteria(int fn, int cn)
{
    // cambia el tamaño de las estanterias siempre que los productos de la sala quepan en las nuevas medidas
    if(fn*cn>=total_prod and fn>0 and cn>0){
        vector<vector <string> > aux (fn, (vector<string>(cn,"") ) );
        int x=0, y=0; // variables para recorrer la matriz aux
        for (int i=0; i<filas;i++){
            for(int j =0;j<columnas;j++){
                if(estanterias[filas-i-1][j]!=""){
                    aux[fn-1-x][y]=estanterias[filas-i-1][j];
                    y++;
                    if(y==cn){
                        y=0;
                        x++;
                    }
                }
            }
        }
        estanterias=aux;
        filas=fn;           // nuevos parametros
        columnas=cn;
        
    }
    else cout<<"  error"<<endl;
  return ;
}

int Sala::poner_items_sala(string iden_prod, int uni_prod)
{
    if( total_prod==filas*columnas) return uni_prod; // mirar si cabe
    if(iden_prod>"" and uni_prod>0){
        it=map_prod_sala.find(iden_prod);
        if(it==map_prod_sala.end()) {
            map_prod_sala[iden_prod]=0;            // introducirlo en el inventario de la sala si no existia ya
            it=map_prod_sala.find(iden_prod);
            
        }
        for (int i=0; i<filas;i++){
            for(int j =0;j<columnas;j++){
                if(estanterias[filas-1-i][j]==""){
                    estanterias[filas-1-i][j]=iden_prod;
                    it->second++;
                    //falta actualizar inventario almacen
                    total_prod++;
                    uni_prod--;
                    if(total_prod==filas*columnas){  // estanteria llena
                        return uni_prod;
                    }
                    else if(uni_prod==0)return 0; 
                    
                }
            }
        }
        return uni_prod;
    }
    else cout<<"  error"<<endl;
    return 0;
}

int Sala:: quitar_items_sala(string iden_prod, int uni_prod)
{
    if( total_prod==0) return uni_prod;
    if(iden_prod>"" and uni_prod>=0){
        it=map_prod_sala.find(iden_prod);
        if(it!=map_prod_sala.end()){
            for (int i=0; i<filas;i++){
                for(int j=0; j<columnas;j++){
                    if(estanterias[filas-1-i][j]==iden_prod){
                        estanterias[filas-1-i][j]="";
                        it->second--;
                        //falta actualizar inventario almacen
                        total_prod--;
                        uni_prod--;
                        if(it->second==0){
                            map_prod_sala.erase(iden_prod);    // eliminar del inventario de la sala si no quedan mas productos
                            return uni_prod;
                        }
                        else if(uni_prod==0)return 0;
                        
                    }
                }
            }
            return uni_prod;
        }
        else return uni_prod;
   }
   else cout<<"  error"<<endl;
   return uni_prod;
}

void Sala::reorganizar(){
   
    it=map_prod_sala.begin();   // primer producto, orden alfabetico
    if(it!=map_prod_sala.end()){
        int contador= it->second;  //unidades producto
        vector <vector<string> > aux (filas ,vector<string>(columnas,""));
        for (int i=0; i<filas;i++){
            for(int j =0;j<columnas;j++){
                aux[filas-1-i][j]= it->first;
                contador--;
                if(contador==0){ // producto colocado: poner el siguiente producto si es que hay mas
                    it++;
                    if(it!= map_prod_sala.end())contador=it->second;
                    else{
                        estanterias=aux;  // todos los productos colocados
                        return;
                    }
                }
            }
        }
         
    }
}

string Sala::consultar_producto(int filas, int columnas){
    if(filas<= this->filas and columnas<= this->columnas){
        string aux= estanterias[filas-1][columnas-1];
        if(aux!="") return aux;
        else return "NULL";
    } 
    else return "error";
    
}

void Sala::leer() 
{
  cin>>filas>>columnas;
  vector<vector<string > > aux(filas,(vector<string>(columnas,"")));
  estanterias=aux;
  total_prod=0;
}

void Sala::escribir() 
{
    for (int i=0;i<filas;i++){
        cout<<" ";
        for(int j =0;j<columnas;j++){
            if(estanterias[i][j]=="") cout<<" NULL";
            else cout<<" "<<estanterias[i][j];
        }
        cout<<endl;
    }
    cout<<"  "<<total_prod<<endl;
    it=map_prod_sala.begin();
    while(it!=map_prod_sala.end()){  //escribir inventario sala
        cout <<"  "<<it->first<<" "<<it->second<<endl;
        it++;
    }

}

