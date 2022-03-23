// Pre: Cert
// Post: La primera component del resultat te valor cert si existeix un node en el p.i. ´
// que representa una Etapa amb ’ciudad’ igual a ’omega’; altrament, la primera component
// del resultat te valor fals. Si la primera component del resultat t ´ e valor cert, la ´
// segona component del resultat conte el m ´ ´ınim valor del camp ’kms recorridos’ dels
// nodes del p.i. que representen una Etapa amb ’ciudad’ igual a ’omega’.

pair<bool,int> distancia(string omega) const {
    return cerca(primer_node, omega);
}

static pair<bool, int> cerca(node* aux, string omega) {
    pair<bool,int> res;
    if (primer == NULL) res.first = false;
    else if (aux->info.ciudad == omega) {
        res.first = true;
        res.second = aux->info.kms_recorridos;
    } else {
        res.first = false;
        int n = aux->seg.size();
        for (int i = 0; i < n; ++i) {
            pair<bool, int> res_i = cerca(aux->seg[i], omega);
            if (res_i.first) {
                if (not res.first or res.second > res_i.second) {
                    res = res_i;
                }
            }
        }
    }
    return res;
}

// Pre: ruta = RUTA es una pila buida. ´
// Post: La primera component del resultat te valor cert si existeix un node en el p.i. ´
// que representa una Etapa amb ’ciudad’ igual a ’omega’; altrament, la primera component
// del resultat te valor fals. Si la primera component del resultat t ´ e valor cert, la ´
// segona component del resultat conte el valor del camp ’kms ´ recorridos’ del node ’n min’
// del p.i. que representa una Etapa amb ’ciudad’ igual a ’omega’ i el seu valor del camp
// ’kms recorridos’ es m ´ ´ınim. En cas d’empat, ’n min’ es el primer node del p.i. en pre-ordre ´
// amb aquestes caracter´ıstiques. A mes, si la primera component del resultat t ´ e valor cert, ´
// el parametre ’ruta’ cont ` e la informaci ´ o dels nodes que formen el cam ´ ´ı que connecta el node
// arrel del p.i. amb el node ’n min’, es a dir, una de las rutes m ´ es curtes des de la ciutat ´
// representada pel node arrel del p.i. fins la ciutat ’omega’.

pair<bool,int> itinerario(string omega, stack<Etapa>& ruta) const {
  return iti_aux(primer_node,omega,ruta);   
}

static pair<bool,int> iti_aux(Node* primer, string omega, stack<Etapa>& ruta) {
  pair<bool,int> res; 
  if (primer == NULL) res.first = false;
    else if (primer->info.ciudad == omega) {
        res.first = true; 
        res.second = primer->info.kms_recorridos;
        ruta.push(primer->info); 
    } 
    else {
        res.first = false;
        int n = primer->seg.size(); 
        for (int i = 0; i < n; ++i) {
           stack<Etapa> ruta_i;
           pair<bool,int> res_i = iti_aux(primer->seg[i],omega,ruta_i); 
           if (res_i.first) {
	           if (not res.first or res.second > res_i.second) {
                   res = res_i;
                   ruta.swap(ruta_i);
                }
            }
        }
    if (res.first) ruta.push(primer->info);
    }
    return res;
}
