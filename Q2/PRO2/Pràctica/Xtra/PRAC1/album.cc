#include "coleccion.hh"

using namespace std;



coleccion::album::album() {}


void coleccion::album::lee_album(){
    int n;
    cin>>n;
    string s;
    foto f;
    for(int i=0;i<n;i++){
        cin>>s;
        f.llegir();
        al.insert(make_pair(s,f));
    }
}


void coleccion::album::vaciar_album() {
    al.clear();
}

void coleccion::album::agrega_foto(const pair<string,foto>& pf){
    al.insert(pf);
}


void coleccion::album::elimina_foto(const string& s){
    al.erase(s);
}

void coleccion::album::modificar_foto(const pair<string,foto>& pf){
        map<string,foto>::iterator it=al.find(pf.first);
        if(it!=al.end()){
            it->second=pf.second;
        }
}

bool coleccion::album::existeix_foto(const string& s) const{
            map<string,foto>::const_iterator it=al.find(s);
            if(it!=al.end())return true;
            else return false;
}



int coleccion::album::nrfotos() const{
    return al.size();
}



int coleccion::album::consultar_posicio(const string& s) const{
    int i=0;
     map<string,foto>::const_iterator it=al.begin();  
      while ((it->first)!=s and it!=al.end()){
          it++;
          i++;
      }
    return i;
}
string coleccion::album::consultar_nom(int i) const{
     map<string,foto>::const_iterator it=al.begin();  
      while (i>0){
          it++;
          i--;
      }
    return it->first;
}

pair<string,foto> coleccion::album::consultar_iesimo(int i) const {
      map<string,foto>::const_iterator it=al.begin();  
      while (i>0){
          it++;
          i--;
      }
      pair<string,foto> pf(it->first,it->second);
      return pf;
}


set<string> coleccion::album::consultar_nom_fotos() const{
    set<string> s;  
    for(map<string,foto>::const_iterator it=al.begin();it!=al.end();it++) s.insert(it->first);
    return s;
}

pair<string,foto> coleccion::album::consultar_foto(const string&s) const{
    map<string,foto>::const_iterator it=al.find(s);
        pair<string,foto> pf(it->first,it->second);
        return pf;
}
 
 
void coleccion::album::obten_foto(const string& s) const{
    map<string,foto>::const_iterator it=al.find(s);
    if(it!=al.end()) {
        cout << it->first <<" ";
        it->second.escribir_foto();
    }
    else cout<<"El album en curso no contiene una foto con el identificador "<<s<<endl;
}

void coleccion::album::imprimir_nr_fotos() const{
        cout << al.size()<<endl;
}

void coleccion::album::escribir_album() const{
        for(map<string,foto>::const_iterator it=al.begin();it!=al.end();it++){
            cout <<"  "<< it->first <<" ";
            it->second.escribir_foto(); 
        }
}
