#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

int main() {
	int n_est, n_assig, sel_assig;
	cin >> n_est >> n_assig >> sel_assig;

	vector<int> assig_num(sel_assig);
	for (int i = 0; i < sel_assig; ++i) cin >> assig_num[i];

	vector<double> assig_marks(n_assig);
	vector<Estudiant> est(n_est);
	int DNI;
	for (int i = 0; i < n_est; ++i) {
		cin >> DNI;

		for (int j = 0; j < n_assig; ++j) cin >> assig_marks[j];

		double res = 0;
		for (int k = 0; k < sel_assig; ++k) res += assig_marks[assig_num[k]-1];
		res /= sel_assig;

		est[i] = Estudiant (DNI);
		est[i].afegir_nota(res);
		est[i].escriure();
	}
}