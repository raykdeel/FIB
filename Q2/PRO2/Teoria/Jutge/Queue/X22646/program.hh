/* Pre: p.i. = C1, c = C2 */
/* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
void trenat(Cua &c) {
    if (primer_node == NULL) {
        primer_node = c.primer_node;
        ultim_node = c.ultim_node;
        longitud = 0;
    } else {
        node_cua* m = primer_node;
        node_cua* n = c.primer_node;
        node_cua *temp_seg_m, *temp_seg_n;

        while (n != NULL and m != NULL) {
            temp_seg_m = m->seguent;
            temp_seg_n = n->seguent;

            n->seguent = m->seguent;
            m->seguent = n;

            if (temp_seg_m == NULL) n->seguent = temp_seg_n;

            m = temp_seg_m;
            n = temp_seg_n;
        }
    }

    longitud += c.longitud;
    c.primer_node = NULL;
    c.ultim_node = NULL;
    c.longitud = 0;
}