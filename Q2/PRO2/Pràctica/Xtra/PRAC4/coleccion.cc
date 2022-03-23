#include "coleccion.hh"

using namespace std;

typedef pair<string,pair<string,pair<fecha,fecha>>> tkaux;


coleccion::coleccion() {}
        

void coleccion::leer_album(const string& s) {
    idaec=s;
    aec.vaciar_album();
    aec.lee_album();
    cout << "Album "<<s << " leido."<<endl;
}

void coleccion::agrega_album(){
    if(idaec=="ALL") cout << "Identificador de album incorrecto. No se puede agregar."<<endl;
    else {    
        map<string,set<string>>::iterator it = col.find(idaec);
        //pair<map<string,album>::iterator,bool> existe= col.insert(make_pair(idaec,aec));
        if(it==col.end()) {
            for(int i=0;i<aec.nrfotos();i++){
            string s= aec.consultar_nom(i);
                if(not all.existeix_foto(s)){
                    all.agrega_foto(aec.consultar_iesimo(i));   
                }
                else {
                    int aux=all.consultar_posicio(s);
                    aec.modificar_foto(all.consultar_iesimo(aux));
                }
            }
            col.insert(make_pair(idaec,aec.consultar_nom_fotos()));
            cout << "Album en curso agregado a la coleccion."<<endl;
            cout << "Album en curso, despues de agregar:"<<endl;
            escribir_aec();
        }
        else cout << "Identificador de album incorrecto. No se puede agregar."<<endl;
    }
}

void coleccion::eliminar_album(const string& s){
    map<string,set<string>>::iterator it=col.find(s);
    if(it!=col.end()){
        col.erase(it);
        cout << "Album eliminado de la coleccion."<<endl;
    }
    else {
        cout<< "Identificador de album incorrecto. No se puede eliminar."<<endl;
    }
}

void coleccion::modificar_album(const string& op,const string& s){
    
    if(op=="agregar") {
        foto f;
        f.llegir();
        if(aec.existeix_foto(s)) cout << "El album en curso ya contiene una foto con el identificador "<<s<<endl;
        else {
            aec.agrega_foto(make_pair(s,f));
            cout << "Foto "<<s<<" agregada al album en curso."<<endl;
        }
    }
    else {
        if(not aec.existeix_foto(s)) cout << "El album en curso no contiene una foto con el identificador "<<s<<endl;
        else {
            aec.elimina_foto(s);
            cout << "Foto "<<s<<" eliminada del album en curso."<<endl;
        }
    }
}


void coleccion::modificar_all(const string& s,const string& op){
    if(op=="agrega") {
        foto f;
        f.llegir();
        pair<string,foto> pf(s,f);
        if(all.existeix_foto(s)) cout<< "Ya existe una foto con el mismo id. No se puede agregar."<<endl;
        else {
            all.agrega_foto(pf);
            /*for(map<string,album>::iterator it=col.begin();it!=col.end();it++){
                it->second.agrega_foto(pf);
            }*/
            cout<<"Foto "<<s<<" agregada a la coleccion."<<endl;
        }
    }
    else {  //op=elimina
        if(all.existeix_foto(s)){
            all.elimina_foto(s);
            for(map<string,set<string>>::iterator it=col.begin();it!=col.end();it++){
                set<string>::iterator it2=it->second.find(s);
                if(it2!=it->second.end())it->second.erase(it2);    
            }
            cout<< "Foto "<<s<<" eliminada de la coleccion."<<endl;
        }
        else cout<<"No existe una foto con el id dado. No se puede eliminar."<<endl;
    }
}

void coleccion::modificar_foto_col(const string&s){
    foto f;
    f.llegir();
    pair<string,foto> pf(s,f);
    if(all.existeix_foto(s)) {
        all.modificar_foto(pf);
        cout << "Foto "<< s<<" modificada en la coleccion."<<endl;
    }
    else cout<<"No existe una foto con el id dado. No se puede modificar."<<endl;
}

void coleccion::obten_foto(const string& s) const{
        aec.obten_foto(s);
}

void coleccion::nr_fotos() const{
        aec.imprimir_nr_fotos();
}

void coleccion::obten_album(const string& s){
    map<string,set<string>>::iterator it=col.find(s);
    if(it!=col.end()){
       cout << s<<endl;
       idaec=s;
       aec.vaciar_album();
       for(set<string>::iterator it2=it->second.begin();it2!=(it->second.end());it2++){
           pair<string,foto> p=all.consultar_foto(*it2);
           cout <<"  "<< p.first << " ";
           p.second.escribir_foto();
           aec.agrega_foto(p);
       }
    }
    else cout << "No existe un album con el id dado."<<endl;
}

void coleccion::imprimir_nr_albums() const{
    cout<<col.size()+1<<endl;
}

void coleccion::lista_albumes() const{
 
    cout << "ALL";
    for(map<string,set<string>>::const_iterator it=col.begin();it!=col.end();it++){
        cout <<" "<< it->first;
    }
    cout <<endl;
}

void coleccion::albumes_foto(const string& s) const{
    if(all.existeix_foto(s)){
        cout << "ALL";
        for(map<string,set<string>>::const_iterator it=col.begin();it!=col.end();it++){
            set<string>::const_iterator it2=it->second.find(s);
            if(it2!=it->second.end()) cout<<" "<<it->first;
        }
        cout << endl;
    }
    else cout<< "No existe una foto con el id dado."<<endl;
}

void coleccion::buscar_por_fecha(const string& s, const string& g,const fecha& f1,const fecha& f2) {
    if (s=="ALL"){
        idaec=g;
        aec.vaciar_album();
        pair<string,foto> pf;
        for(int i=0;i<all.nrfotos();i++) {
            pf = all.consultar_iesimo(i);
            if(pf.second.consultar_fecha(f1,f2)) aec.agrega_foto(pf);
            }
        cout << idaec<<endl;
        aec.escribir_album();
    }
    else {
        map<string,set<string>>::iterator it=col.find(s);
        if(it!=col.end()){
            idaec=g;
            aec.vaciar_album();
            pair<string,foto> pf;
            for(set<string>::iterator it2=it->second.begin();it2!=it->second.end();it2++) {
                pf = all.consultar_foto(*it2);
                if(pf.second.consultar_fecha(f1,f2)) aec.agrega_foto(pf);
            }
            cout << idaec<<endl;
            aec.escribir_album();
        }
        else cout<< "No existe un album con el id dado."<<endl;
    }
}


void coleccion::buscar_por_etiq(const string& s,const string& p,const string& g) {
    map<string,set<string>>::iterator it=col.find(p);
    if(p=="ALL") {
        idaec=g;
        aec.vaciar_album();
        pair<string,foto> pf;
        for(int i=0;i<all.nrfotos();i++) {
            pf = all.consultar_iesimo(i);
            if(pf.second.consultar_etiqueta(s)) aec.agrega_foto(pf);
            }
        cout << idaec<<endl;
        aec.escribir_album();
    }
    else{
        if(it!=col.end()){
            idaec=g;
            aec.vaciar_album();
            pair<string,foto> pf;
            for(set<string>::iterator it2=it->second.begin();it2!=it->second.end();it2++) {
                pf = all.consultar_foto(*it2);
                if(pf.second.consultar_etiqueta(s)) aec.agrega_foto(pf);
            }
            cout<<idaec<<endl;
            aec.escribir_album();
        }
        else cout<< "No existe un album con el id dado."<<endl; 
    }
}


set<string> coleccion::booland(set<string>& a1,set<string>& a2){
    set<string>a;
    for(set<string>::iterator it=a2.begin();it!=a2.end();it++){
        set<string>::iterator it2=a1.find(*it);
        if(it2!=a1.end())a.insert(*it);
    }
    return a;
}


set<string> coleccion::boolor(set<string>& a1,set<string>& a2){
    for(set<string>::iterator it=a2.begin();it!=a2.end();it++) a1.insert(*it);
    return a1;
}


set<string> coleccion::boolnot(set<string>& a1,const string& s){
     set<string> a;
     pair<string,foto> pf;
     if(s=="ALL"){
         for(int i=0;i<all.nrfotos();i++){
              pf = all.consultar_iesimo(i);
              set<string>::iterator it=a1.find(pf.first);
              if(it==a1.end()) a.insert(pf.first);
         }
     }
     else{
        map<string,set<string>>::iterator it=col.find(s);
            if(it!=col.end()){
                for(set<string>::iterator it2=it->second.begin();it2!=it->second.end();it2++) {
                    pf = all.consultar_foto(*it2);
                    it2=a1.find(pf.first);
                    if(it2==a1.end()) a.insert(pf.first);
                }
            }
     }
    return a;
}

set<string> coleccion::tag(const string& s, const string& g){
    set<string> a;
    pair<string,foto> pf;
    if(s=="ALL"){
        for(int i=0;i<all.nrfotos();i++) {
            pf = all.consultar_iesimo(i);
            if(pf.second.consultar_etiqueta(g)) a.insert(pf.first);
            }
    }
    else {
        map<string,set<string>>::iterator it=col.find(s);
        if(it!=col.end()){
            for(set<string>::iterator it2=it->second.begin();it2!=it->second.end();it2++) {
                pf = all.consultar_foto(*it2);
                if(pf.second.consultar_etiqueta(g)) a.insert(pf.first);
            }
        }
    }
    return a;
}
    

set<string> coleccion::date(const string& s,const fecha& f1,const fecha& f2){
    set<string> a;
    pair<string,foto> pf;
    if(s=="ALL"){
        for(int i=0;i<all.nrfotos();i++) {
            pf = all.consultar_iesimo(i);
            if(pf.second.consultar_fecha(f1,f2)) a.insert(pf.first);
            }
    }
    else {
        map<string,set<string>>::iterator it=col.find(s);
        if(it!=col.end()){
            for(set<string>::iterator it2=it->second.begin();it2!=it->second.end();it2++) {
                pf = all.consultar_foto(*it2);
                if(pf.second.consultar_fecha(f1,f2)) a.insert(pf.first);
            }
        }
    }
    return a;
}
    
void coleccion::recorrido_arbol(const BinTree<tkaux>& a, const string& s, stack<set<string>>& sa){
        if(not a.empty()){
            recorrido_arbol(a.left(),s,sa);
            recorrido_arbol(a.right(),s,sa);
            if(a.value().first=="TAG"){
                sa.push(tag(s,a.value().second.first));
            }
            else if(a.value().first=="DATE"){
                sa.push(date(s,a.value().second.second.first,a.value().second.second.second));
            }
            else if(a.value().first=="AND"){
                set<string> a=sa.top();sa.pop();
                set<string> b=sa.top();sa.pop();
                sa.push(booland(a,b));
            }
            else if(a.value().first=="OR"){
                set<string> a=sa.top();sa.pop();
                set<string> b=sa.top();sa.pop();
                sa.push(boolor(a,b));
            }
            else{//"NOT"
                set<string> a=sa.top();sa.pop();
                sa.push(boolnot(a,s));
            }
        }
}

void coleccion::evalua_const_bool(const string& s, const string& g) {
    ConsultaBool cb;
    pair<string,foto>pf;
    map<string,set<string>>::iterator it=col.find(s);
    if(it!=col.end() or s=="ALL"){
        cb.read(cin);
        idaec=g;
        aec.vaciar_album();
        BinTree<tkaux> a= cb.consultararbol();
        stack<set<string>> sa;
        recorrido_arbol(a,s,sa);
        for(set<string>::iterator it2=sa.top().begin();it2!=sa.top().end();it2++){
            pf=all.consultar_foto(*it2);
            aec.agrega_foto(pf);
        }
        escribir_aec();
    }
    else {
        string h;
        cin >> h;
        while(h!="END_QUERY")cin>>h;
        cout<<"No existe un album con el id dado."<<endl;
    }
}

void coleccion::escribir_aec() const{
    cout << idaec<<endl;
    aec.escribir_album();
}

void coleccion::escribir_col() const{
    cout<< "ALL"<<endl;
    all.escribir_album();
    for(map<string,set<string>>::const_iterator it=col.begin();it!=col.end();it++){
        cout<<it->first<<endl;
        for(set<string>::const_iterator it2=it->second.begin();it2!=it->second.end();it2++) {
            cout <<"  ";
            all.obten_foto(*it2);
        }
    }
}
