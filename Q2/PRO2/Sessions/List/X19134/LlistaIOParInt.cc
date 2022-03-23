
#include "LlistaIOParInt.hh"

// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
void LlegirLlistaParInt(list<ParInt>& l) {
	ParInt aux;
	while (aux.llegir() and not (aux.primer() == 0 and aux.segon() == 0)) {
		l.push_back(aux);
	}
}

// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
void EscriureLlistaParInt(const list<ParInt>& l) {
	for (list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it) (*it).escriure();
}
