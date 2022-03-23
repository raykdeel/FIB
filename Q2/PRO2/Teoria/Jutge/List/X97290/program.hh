Llista& operator=(const Llista& original) {
    if (this != &original) {
        longitud = original.longitud;
        esborra_node_llista(primer_node);
        primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);

    }
    return *this;
}

node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a) {
    if (m == NULL) {
        u = a = NULL;
        return NULL;
    }
    node_llista *first, *aux;
    first = aux = new node_llista;
    aux->info = m->info;
    aux->ant = NULL;
    m = m->seg;
    while (m != NULL) {
        node_llista* aux2 = new node_llista;
        aux2 ->info = m->info;
        aux->seg = aux2;
        aux2->ant = aux;
        if (oact == m) a = aux2;
        aux = aux2;
        m = m->seg;
    }
    u = aux;
    return first;
}