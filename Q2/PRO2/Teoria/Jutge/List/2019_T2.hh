// Pre : s i no e s t `a buid a , l a c a d e n a de n o d e s d e l
// p . i . e s t `a c om p a r ti d a amb una a l t r a l l i s t a
// P o s t : e l p . i . r e p r e s e n t a a una l l i s t a b ui d a
void nullify() {
    primer_node = ultim_node = act = NULL;
    longitud = 0;
}

// Pre : c e r t
// P o s t : r e t o r n a un a p u n t a d o r a l p rim e r node que c o n t ´e x
// en l a c a d e n a de n o d e s que comen¸ca a p , o n u l l p t r
// s i no h i ha cap node a p a r t i r de p que c o n t i n g u i x
static node_llista* search(node_llista* aux, const T& x) {
    while(aux != NULL and aux->info != x) {
        aux = aux->seg;
    }
    return aux;
}

// Pre : c e r t
// P o s t : i n s e r e i x l a l l i s t a l2 j u s t d a v an t de l a p rim e r a
// a p a r i c i ´o de l ’ el em e n t x en e l p . i . s i x e s t `a p r e s e n t ,
// o a l f i n a l d e l p . i . s i x no e s t `a p r e s e n t ; en q u a l s e v o l c a s
// l a l l i s t a l2 queda buid a , i e l punt d ’ i n t e r `e s d e l p . i .
// queda i n a l t e r a t
void splice(const T& x, Llista& l2) {
    if (l2.primer_node == NULL) return;
    if (primer_node == NULL) {
        primer_node = l2.primer_node;
        ultim_node = l2.ultim_node;
        longitud = l2.longitud;
        l2.nullify();
        return;
    }    
    node_llista* aux = search(primer_node, x);
    if (aux == NULL) {
        ultim_node->seg = l2.primer_node;
        l2.primer_node->ant = ultim_node;
        ultim_node = l2.ultim_node;
    } else {
        node_llista* bux = aux->ant;
        l2.primer_node->ant = bux;
        l2.ultim_node->seg = aux;
        if (bux != NULL) {
            bux->seg = l2.primer_node;
        } else {
            primer_node = l2.primer_node;
        }
    }
    longitud += l2.longitud;
    l2.nullify();
}
