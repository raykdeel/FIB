int ipl(node_arbre* aux) {
    int ipl, s;
    ls(aux, ipl, s);
    return double(ipl)/double(s);   
}

static void ls(node_arbre* aux, int& ipl, int& s) {
    if (aux != NULL) {
        int iple, ipld, se, sd;
        ls(aux->esq, iple, se);
        ls(aux->dre, ipld, sd);
        ipl = iple + ipld + se + sd;
        s = 1 + se + sd;  
    }
}