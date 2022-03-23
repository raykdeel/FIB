#include <iostream>
#include <vector>
using namespace std;

struct partit {
	int x;
	int y;
};

typedef vector < vector <partit> > partits;

struct result {
	int num_eq = 0;
	int total_p = 0;
	int gols_m = 0;
	int gols_r = 0;
};

partits leer_mat_int() {
	int numEst;
	cin >> numEst;
	partits v(numEst, (vector<partit>(numEst)));

	for (int i = 0; i < numEst; ++i) {
		for (int j = 0; j < numEst; ++j) {
			cin >> v[i][j].x >> v[i][j].y;
		}
	}
	return v;
}

void evaluate(partits& mat, vector<result>& results) {
	int s = mat.size();
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < s; ++j) {
			if (i != j) {
				results[i].gols_m += mat[i][j].x;
				results[j].gols_m += mat[i][j].y;

				results[i].gols_r += mat[i][j].y;
				results[j].gols_r += mat[i][j].x;

				if (mat[i][j].x > mat[i][j].y) results[i].total_p += 3;
				else if (mat[i][j].x < mat[i][j].y) results[j].total_p += 3;
				else {
					results[i].total_p += 1;
					results[j].total_p += 1;
				}
			}
		}
	}
}

int main() {
	partits mat = leer_mat_int();
	vector<result> results(mat.size());
	evaluate(mat, results);
}