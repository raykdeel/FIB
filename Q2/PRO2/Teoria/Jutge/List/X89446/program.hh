Llista  reorganitzar_out(const T& x) const {
    Llista l;
    if (longitud == 0) return l;
    l.longitud = longitud;
    l.act = l.ultim_node = l.primer_node = NULL;
    node_llista* aux = NULL;
    node_llista* act = primer_node;
    while (act != NULL) {
        if (act -> info <= x) {
            if (l.primer_node == NULL) {
                aux = l.primer_node = new node_llista;
                l.primer_node -> ant = NULL;
            } else {
                aux -> seg = new node_llista;
                aux -> seg -> ant = aux;
                aux = aux -> seg;
            }
            aux -> info = act -> info;
        } else {
            if (l.ultim_node == NULL) {
                l.ultim_node = l.act = new node_llista;
                l.act -> ant = NULL;
            } else {
                l.ultim_node -> seg = new node_llista;
                l.ultim_node -> seg -> ant = l.ultim_node;
                l.ultim_node = l.ultim_node -> seg;
            }
            l.ultim_node -> info = act -> info;
        }
        act = act-> seg;
    }

    if (l.primer_node == NULL) l.primer_node = l.act;
    else if (l.act == NULL) l.ultim_node = aux;
    else {
        aux -> seg = l.act;
        l.act -> ant = aux;
    }

    l.ultim_node -> seg = NULL;
    return l;
}