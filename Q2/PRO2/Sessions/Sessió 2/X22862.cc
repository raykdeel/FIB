#include <iostream>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;

double redondear(double r) {
	return int(10.*(r + 0.05)) / 10.0;
}

int main() {
	Cjt_estudiants conjunt;
	conjunt.llegir();

	int op;
	cin >> op;

	int dni, mida;
	double nota;
	Estudiant query;
	while (op != -6) {
		if (op == -1) {
			cin >> dni >> nota;
			query = Estudiant(dni);
			if (nota >= 0 and nota <= 10) query.afegir_nota(nota);

			if (conjunt.existeix_estudiant(dni)) cout << "el estudiante " << dni << " ya estaba" << endl << endl;
			else if (conjunt.mida() == 5) cout << "el conjunto esta lleno" << endl;
			else conjunt.afegir_estudiant(query);
		}

		else if (op == -2) {
			cin >> dni;
			if (conjunt.existeix_estudiant(dni)) {
				query = conjunt.consultar_estudiant(dni);
				if (query.te_nota()) cout << "el estudiante " << dni << " tiene nota " << query.consultar_nota() << endl << endl;
				else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
			} else cout << "el estudiante " << dni << " no esta" << endl << endl;
		}

		else if (op == -3) {
			cin >> dni >> nota;
			if (conjunt.existeix_estudiant(dni)) {
				query = conjunt.consultar_estudiant(dni);
				if (query.te_nota()) query.modificar_nota(nota);
				else query.afegir_nota(nota);
				conjunt.modificar_estudiant(query);
			} else cout << "el estudiante " << dni << " no esta" << endl << endl;
		}

		else if (op == -4) {
			mida = conjunt.mida();
			for (int i = 1; i <= mida; ++i) {
				query = conjunt.consultar_iessim(i);
				if (query.te_nota()) {
					query.modificar_nota(redondear(query.consultar_nota()));
					conjunt.modificar_iessim(i, query);
				}
			}
		}

		else if (op == -5) {
			conjunt.escriure();
			cout << endl;
		}

		cin >> op;
	}
}