void esborrar_tots(const T& x) {
    if (primer_node != NULL) {
        node_llista *n = primer_node;
        node_llista *aux = primer_node;
        while (n != NULL) {
            if (n->info == x) {
                if(n == act) act = n->seg;
                node_llista *aux2 = n;
                n = n->seg;
                if(aux2 == primer_node) {
                    primer_node = n; //aux = n;
                }
                else if(aux2 == ultim_node) {
                    ultim_node = aux;
                    aux->seg = NULL;
                } else {
                    aux->seg = n;
                    n->ant = aux;
                }
                delete aux2;
                --longitud;
            } else {
                aux = n;
                n = n->seg;
            }
        }
    }
}
