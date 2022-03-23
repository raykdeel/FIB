/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
    return recorre(primer_node, x);
}

static bool recorre(node_arbreGen* aux, const T& x) {
    if (aux != NULL) {
        if(aux->info == x) return true;
        else {
            int n = aux->seg.size();
            for (int i = 0; i < n; ++i) {
                bool res = recorre(aux->seg[i], x);
                if (res) return true;
            }
        }
    }
    return false;
}