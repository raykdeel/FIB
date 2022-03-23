void sub_arrel(Arbre& asub, const T& x) {
    int d =0, dmin = -1;
    sun(primer_node, asub.primer_node, x, d, dmin);
}

void sun(node_arbre* aux, node_arbre* &n, const T& x, int d, int& dmin) {
    if (aux != NULL) {
        if (aux->info == x and (d <= dmin or dmin == -1)) {
            dmin = d;
            n = aux;
        }
    sun(aux->segE, n, x, ++d, dmin);
    sun(aux->segD, n, x, ++d, dmin);  
    }
}