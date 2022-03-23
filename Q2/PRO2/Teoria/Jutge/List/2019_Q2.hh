// Pre: p != nullptr, k ≥ 0
// Post: retorna un apuntador al node que està k posicions més
// enllà de p a la cadena o bé nullptr si no hi ha k o més nodes
// a continuació de p
static node* salta(node* aux,int k) {
    if(aux != NULL and k > 0) {
        --k;
        salta(p->seg, k);
    } else return aux;
}

static node* salta(node* aux,int k) {
    while (aux != NULL and k>0) {
        aux = aux->seg;
        --k;
    }
    return aux;    
}

// Pre: cert
// Post: retorna un MySet amb la subllista
// formada pel 1r, 2n, 4t, 8è, 16è,...
// elements del MySet implícit
Myset galopar() const {
    Myset a;
    if(a.primer != NULL) {
        node* aux = primer;
        a.primer = new node;
        a.ult = a.primer;
        a.primer->info = primer->info;

        node* bux = a.primer;
        aux = aux->seg;
        int salt = 2;
        while (aux != NULL) {
            bux->seg = new node;
            bux = bux->seg;
            bux->info = aux->info;
            aux = salta(aux, salt);
            salt *= 2;
        }
        a.ult = bux;
    }
}