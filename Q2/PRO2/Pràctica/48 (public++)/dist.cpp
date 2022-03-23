double Cjt_Especies::consultar_distancia(string id1, string id2, int k){
    if (id1 == id2) return 0;
    it = mesp.find(id1);
    Especie a = it->second;
    it = mesp.find(id2);
    Especie b = it->second;
    map<string,int> k1;
    map<string,int> k2;
    map<string,int>::const_iterator it1;
    map<string,int>::const_iterator it2;
    k1 = a.consultar_kmer();
    k2 = b.consultar_kmer();
    double ig = 0, total = 0;
    it1 = k1.begin(), it2 = k2.begin();
    while (it1 != k1.end() and it2 != k2.end()) {
        if (it1->first < it2->first) {
            total += it1->second;
            ++it1;
        }
        else if (it2->first < it1->first) {
            total += it2->second;
            ++it2;
        }
        else {
            ig += min(it1->second, it2->second);
            total += it2->second;
            total += it1->second;
            ++it1;
            ++it2;
        }
    }
    while (it1 != k1.end()) {
        total += it1->second;
        ++it1;
    }
    while (it2 != k2.end()) {
        total += it2->second;
        ++it2; 
    }
    return (1 - (ig / (total-ig))) * 100;
}
