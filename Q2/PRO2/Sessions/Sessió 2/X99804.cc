#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"
using namespace std;

bool cmp(const Estudiant& a, const Estudiant& b) {
	if (a.consultar_nota() == b.consultar_nota()) return a.consultar_DNI() < b.consultar_DNI();
	return a.consultar_nota() > b.consultar_nota();
}

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
	}

	sort(est.begin(), est.end(), cmp);
	for (int i = 0; i < n_est; ++i) est[i].escriure();
}