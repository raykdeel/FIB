#include "Especie.hh"
using namespace std;

Especie::Especie() {
    identificador;
    gen;
}

void Especie::llegir() {
    cin >> identificador >> gen;
}

void Especie::escriu() const {
    cout << identificador << " " << gen << endl;
}
void Especie::modificar_id(string id) {
        identificador = id;
}

string Especie::consultar_identificador() const{
    return identificador;
}

string Especie::consultar_gen() const{
    return gen;
}

