/* Pre: p.i. = L */
/* Post: el p.i. conté els mateixos elements que L però
reorganitzats de manera que primer apareixen els més petits
o iguals que x, en el mateix ordre que en L, seguits pels
més grans que x, en el mateix ordre que en L.
L'element actual del p.i. és el primer del més grans que x, si
existeix, sinó es situa a la dreta de tot */
void reorganitzar_in(const T& x) {
    Llista l;
    if (longitud == 0) return;
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

    *this = l;
}