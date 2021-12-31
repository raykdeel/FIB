#include "CacheSim.h"
#include <string.h>
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */


typedef struct {
	unsigned int v1Bit;
    unsigned int v2Bit;
	unsigned int tag2;
	unsigned int tag1;
    unsigned int lru;
} cacheConj;

cacheConj cache[64];


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comenar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
    int i;
	for (i = 0; i < 128; i++) {
        cache[i].v1Bit = 0; cache[i].v2Bit = 0;
        cache[i].lru = 0;
    }
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaa una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

    bloque_m = address >> 5;	 //right shift >> 2 = 32 (5 lsb)
	tag = address >> 11;       //right shift >> 2¹¹ = 2048 (11 lsb)
	conj_mc = bloque_m & 0x3f;// (0x3f = 63 = 0011 1111, agafem 6 lsb)
    byte = address & 0x1f;   // (0x1f = 31 = 0001 1111, agafem 5 lsb de @)
    

    if (cache[conj_mc].v1Bit && tag == cache[conj_mc].tag1) {
		miss = 0; replacement = 0; via_mc = 0;
        cache[conj_mc].lru = 1;
	}
	else if(cache[conj_mc].v2Bit && tag == cache[conj_mc].tag2) {
		miss = 0; replacement = 0; via_mc = 1;
        cache[conj_mc].lru = 0;
	}
	else {
		miss = 1;
        if(!cache[conj_mc].v1Bit || !cache[conj_mc].v2Bit) {
        //bits validesa not initialized (cache buida)
            replacement = 0; //cache buida -> no replace
            if(!cache[conj_mc].lru) {
                cache[conj_mc].tag1 = tag;
                cache[conj_mc].v1Bit = 1;
                via_mc = 0;
                cache[conj_mc].lru = 1;        
            } else {
                cache[conj_mc].tag2 = tag;
                cache[conj_mc].v2Bit = 1;
                via_mc = 1;
                cache[conj_mc].lru = 0;
            }
        } else if (cache[conj_mc].v1Bit && cache[conj_mc].v2Bit) {
        //bits validesa initialized (cache inicialitzada)
			replacement = 1; //cache plena -> replace needed
            if (!cache[conj_mc].lru) {
                tag_out = cache[conj_mc].tag1;
                cache[conj_mc].tag1 = tag;
                cache[conj_mc].lru = 1;
                via_mc = 0;
            }
            else {
                tag_out = cache[conj_mc].tag2;
                cache[conj_mc].tag2 = tag;
                cache[conj_mc].lru = 0;
                via_mc = 1;
            }
		}
    }
    
    
    



	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb mesurem el temps d'execuci
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
}