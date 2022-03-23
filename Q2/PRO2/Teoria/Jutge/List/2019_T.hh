// Pre: p != nullptr
// Post: retorna nullptr si cap node entre el succesor de p
// i el final conte x, altrament retorna un apuntador al
// predecessor d’un node, entre el successor de p i el final,
// que conte x
static node* cerca(node* aux, const T& x) {
    if(aux->seg == NULL) return NULL;
    else if (aux->seg->info == x) return aux;
    else return cerca(aux->seg, x);
}

static node* cerca(node* aux, const T& x) {
    while(aux->seg != NULL) {
        if(aux->seg->info == x) return aux;
        else aux = aux->seg;
    } else return NULL;
}

// Pre : p != nullptr, p−>seg != nullptr
// Post : mou el node successor de p al començament
// de la Bag implícita
void mou_al_front(node* aux) {
    node* q = aux->seg;
    aux->seg = q->seg;
    q->seg = sent->seg;
    sent->seg = q;
}

// Pre : cert
// Post : retorna cert si i nomes si
// la Bag implıcita conte x; a mes, si x estava
// present x passa a ser el primer element
bool conte(const T& x) {
    node* bux = cerca(sent, x);
    if (bux == NULL) return false;
    else {
        mou_al_front(bux);
        return true;
    }
}

// Pre : cert
// Post : s’ha afegit l’element x a la Bag implıcita, si x no hi era,
// altrament no s’ha afegit res; pero tant si x ja era present com si
// s’ha afegit, x passa a ser el primer element del Bag
void afegeix(const T& x) {
    if (not conte(x)) {
        //x no hi era, i insertem un nou node a l'inici de la llista
        node* nou = new node;
        nou->info = x;
        nou->seg = sent->seg;
        sent->seg = nou;
        ++tam;
    } //else 'conte' ja l'ha mogut al prinicipi
}

void afegeix(const T& x) {
    node* aux = cerca(sent,x);
    if (aux == NULL) {
        node* nou = new node;
        nou->info = x;
        nou->seg = sent->seg;
        sent->seg = nou;
        ++tam;
    } else {
        mou_al_front(aux);
    }
}