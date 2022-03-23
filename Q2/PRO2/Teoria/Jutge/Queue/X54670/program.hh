void concat(Cua &c) {
    if (c.primer_node != NULL) {
        if (primer_node == NULL) {
            primer_node = c.primer_node;
            ultim_node = c.ultim_node;
            longitud = c.longitud;                 
        } else {
            ultim_node->seguent = c.primer_node;
            ultim_node = c.ultim_node;
            longitud += c.longitud;
        }
    }
    c.primer_node = NULL;
    c.ultim_node = NULL;
    c.longitud = 0;
}