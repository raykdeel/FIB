/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const {
    int cont = 0;
    recorre(primer_node, x, cont);
    return cont;
}

static void recorre(node_arbreGen* aux, int x, int& cont) {
    if(aux != NULL) {
        if (aux->info == x) ++cont;
        int n = aux->seg.size();
        for (int i = 0; i < n; ++i) {
            recorre(aux->seg[i], x, cont);
        }
    }
}
