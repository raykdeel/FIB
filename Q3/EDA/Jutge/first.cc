#include <iostream>
#include <vector>

using namespace std;

// Retorna la primera aparicio de x en el vector v[l....r]
int first_occurrence(double x, const vector<double>& v, int l, int r){

  if (l > r) return -1;
  else {
    int m = (l+r)/2;
    if (v[m] == x) {
      if (m-1 < l or v[m-1] != x) return m; // Si esquerra no existeix o no es x
      else return first_occurrence(x,v,l,m-1); // Busco esquerra
    }
    else if (v[m] < x) return first_occurrence(x,v,m+1,r); // Busco dreta
    else                    return first_occurrence(x,v,l,m-1); // Busco esquerra
  }

}

int first_occurrence(double x, const vector<double>& v){
  return first_occurrence(x,v,0,v.size()-1);
}

int main() {
  // Llegeix un double i el vector on cal buscar-lo
  double x;
  cin >> x;
  int n; cin >> n;
  vector<double> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  cout << first_occurrence(x,v) << endl;
}

  
