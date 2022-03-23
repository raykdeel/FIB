T maxim() const {
    T aux = primer_node->info;
    recorre(primer_node, aux);
    return aux;
}

static void recorre(node_arbreNari *a, T& aux) {
    if (a != NULL) {
        for (int i = 0; i < a->seg.size(); ++i) {
            recorre(a->seg[i], aux);
            if (aux < a->info) aux = a->info;
        }
    }
}
