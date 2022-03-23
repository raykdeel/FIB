// Pre: el p.i. no es buit i tot node te exactament zero
// o 2 fills no buits .
// Post : retorna l’arbre de maxims corresponent al p.i.
Arbre arbre_maxims() {
    Arbre a;
    int max;
    a.primer_node = recorre(primer_node, max);
    return a;
}

static node_arbre* recorre(node_arbre* aux, int& max) {
    node_arbre* n;
    if (aux == NULL) n = NULL;
    else {
        int x, y;
        n = new node_arbre;
        n->segE = recorre(aux->segE, x);
        n->segD = recorre(aux->segD, y);
        n->info = max(x, y, aux->info);
    }
    return n;
}