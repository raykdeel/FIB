#include "fecha.hh"

using namespace std;

fecha::fecha(){};

void fecha::transforma() {
    fdias = dia + (mes * 30) + (any * 365);
}

void fecha::llegir() {
    cin >> dia >> mes >> any;
    transforma();
}
    
    
int fecha::consultar_dias() const{
    return fdias;
}
    
bool fecha::comparar_fechas(const int& f1, const int& f2) const{
    return (fdias>=f1 and fdias<=f2);
}

void fecha::escribir() const{
    cout<< dia<<"/"<<mes<<"/"<<any;
}
