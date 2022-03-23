#include <vector>
#include "Cjt_Especies.hh"



int Cjt_Especies::cerca_esp(const vector<Especie>& v, string id) {
    int i = v.size() - 1;
    bool found = false;
    while (i >= 0 and not found) {
        if (v[i].consultar_identificador() == id) found = true;
        if(not found) --i;
    }
    if (found) return i;
    else return -1;
}

vector<string> Cjt_Especies::kmer(string g, int k) const{
    int max = g.length() - k + 1;
    vector<string> v(max);
    for (int j = 0; j < max; ++j) {
        for (int i = j; i < k; ++i) {
            v[j] += g[i];
        } 
        ++k;
    }
    return v;
}


Cjt_Especies::Cjt_Especies() {
    nesp = 0;
    //vesp = vector<Especie>();
}



void Cjt_Especies::afegir_Especie(const Especie& a) {
    if(nesp == 0) {
        vesp[0] = a;
        ++nesp;
    } else {
        bool here = false;
        int i = nesp - 1;
        while (i >= 0 and not here) {
            if (vesp[i].consultar_identificador() == a.consultar_identificador()) here = true;
            --i;
        }
        if (not here) {
            vesp.push_back(a);
            ++nesp;
        }
    }
}

void Cjt_Especies::eliminar_Especie(string id) {
    int i = cerca_esp(vesp, id);
    if(i != -1) {
        vector<Especie> v;
        int p = 0;
        for (int j = 0; j < nesp; ++j) {
            if(j != i) {
                v.push_back(vesp[j]);
                ++p;
            }
        }
        nesp = p;
        vesp.pop_back();
        for (int j = 0; j < p; ++j) {
            vesp[j] = v[j];
        }
    }
}

vector<Especie> Cjt_Especies::consultar_vector() const {
    return vesp;
}

bool Cjt_Especies::existeix_Especie(string id) const{
    int i = cerca_esp(vesp, id);
    if (i != -1) {
        cout << "L'ESPÈCIE AMB L'IDENTIFICADOR " << id << " EXISTEIX" << endl;
        return true;
    }
    else {
        cout << "L'ESPÈCIE AMB L'IDENTIFICADOR " << id << " NO EXISTEIX" << endl;
        return false;
    }
}

double Cjt_Especies::consultar_distancia(string id1, string id2, int k) const{
    int i = cerca_esp(vesp, id1);
    int j = cerca_esp(vesp, id2);
    if (i != -1 and j != -1) {
        vector<string> a = kmer(vesp[i].consultar_gen(), k);
        vector<string> b = kmer(vesp[j].consultar_gen(), k);
        double x = 0;
        int y = a.size() + b.size();
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                if(a[i] == b[j]) ++x;
            }
        }
    cout.setf(ios::fixed);
	cout.precision(4);
    x /= y;
    return ((1 - x) * 100);
    } else {
        if (i == -1) cout << "NO EXISTEIX CAP ESPÈCIE AMB L'IDENTIFICADOR " << id1;
        else if (j == -1) cout << "NO EXISTEIX CAP ESPÈCIE AMB L'IDENTIFICADOR " << id2;
        else cout << "NO EXISTEIX CAP DE LES DUES ESPÈCIES"; 
        return -1;
    }   
}

int Cjt_Especies::mida() const {
    return nesp;
}

void Cjt_Especies::llegir(int n) {//FALTA COMPROVAR
    while (vesp.size() > 1) vesp.pop_back();
    Especie aux;
    for (int i = 0; i < n; ++i) {
        aux.llegir();
        vesp.push_back(aux);
    }
}

void Cjt_Especies::obtenir_gen(string id) {
    int i = cerca_esp(vesp, id);
    if (i != -1) cout << vesp[i].consultar_gen() << endl;
    else cout << "NO EXISTEIX UNA ESPÈCIE AMB AQUEST IDENTIFICADOR" << endl;
}

void Cjt_Especies::escriu_cjt_especies() const {
    for (int i = 0; i < nesp; ++i) vesp[i].escriu();
}

void Cjt_Especies::taula_distancies(int k) {
    for(int i = 0; i < nesp; ++i) {
        for (int j = 0; j < nesp; ++j) {
            if (i == j) cout << "0.000" << " ";
            else cout << consultar_distancia(vesp[i].consultar_identificador(), vesp[j].consultar_identificador(), k) << " ";
        }
        cout << endl;
    }
}
