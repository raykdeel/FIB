/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
    int suma;
    node_arbre* aux = NULL;
    arb_sumes_rec(primer_node, aux, suma);
    asum.primer_node = aux;
}

void arb_sumes_rec(node_arbre* node, node_arbre* &node_sum, int &suma) const {
    if (node == NULL) suma = 0;
    else {
        suma = node->info;

        int suma_e, suma_d;
        node_arbre *nE, *nD;
        nE = nD = NULL;
        arb_sumes_rec(node->segE, nE, suma_e);
        arb_sumes_rec(node->segD, nD, suma_d);

        suma += suma_e + suma_d;
        node_sum = new node_arbre;

        node_sum->info = suma;
        node_sum->segE = nE;
        node_sum->segD = nD;
    }
}
