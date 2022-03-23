/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
T max_suma_cami() const {
    T sum = primer_node->info;
    recorre(primer_node, sum);
    return sum;
}

static void recorre(node_arbreGen* aux, T& sum) {
    if(aux != NULL) {
        T x = 0, max = 0;
        if (aux->seg.size() != 0) max = -99999;
        else max = 0;
        int n = aux->seg.size();
        for (int i = 0; i < n; ++i) {
            recorre(aux->seg[i], x);
            if (x > max) max = x;
        }
        sum = aux->info + max;
    }
}
