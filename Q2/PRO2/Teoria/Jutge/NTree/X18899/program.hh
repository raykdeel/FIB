void arbsuma(ArbreNari& asum) const {
    int sum = 0;
    asum.N = this->N;
    recorre(primer_node, asum.primer_node, sum);
}

static void recorre(node_arbreNari *aux, node_arbreNari* &bux, int& sum) {
    if(aux != NULL) {
        sum = aux->info;
        bux = new node_arbreNari;
        bux->seg = vector<node_arbreNari*>(aux->seg.size());
        for(int i = 0; i < aux->seg.size(); ++i) {
            node_arbreNari* cux = NULL;
            int sum2;
            recorre(aux->seg[i], cux, sum2);
            sum += sum2;
            bux->seg[i] = cux;
        }
        bux->info = sum;
    } else {
        sum = 0;
    }
}
