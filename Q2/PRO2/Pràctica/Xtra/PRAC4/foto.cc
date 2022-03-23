#include "foto.hh"

using namespace std;

foto::foto() {}

void foto::llegir() {
        string et;
        fec.llegir();
        cin>> n;
        if(not(etiq.empty()))etiq.clear();
        for(int i=0;i<n;i++) {
            cin >> et;
            etiq.insert(et);
        }
}


bool foto::consultar_fecha(const fecha& f1,const fecha& f2) const {
    return fec.comparar_fechas(f1.consultar_dias(),f2.consultar_dias());
    
}

bool foto::consultar_etiqueta(const string& s) const{
    set<string>::iterator it=etiq.find(s);
    if(it != etiq.end())return true;
    else return false;
}

void foto::escribir_foto() const{
        fec.escribir();
        cout <<" "<<n;
        if(n!=0) {
            for(set<string>::const_iterator it2=etiq.begin();it2!=etiq.end();it2++){
                cout<<" "<< *it2;
            }
        }
        cout <<endl;
}
