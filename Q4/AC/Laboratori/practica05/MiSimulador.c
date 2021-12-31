#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct {
  int vBit;
  int tag;
} cacheDir;

cacheDir cache[128];

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void
init_cache ()
{
  totaltime = 0.0;
  /* Escriu aqui el teu codi */
  for (int i = 0; i < 128; i++) cache[i].vBit = 0;	

}

/* La rutina reference es cridada per cada referencia a simular */
void
reference (unsigned int address)
{
  unsigned int byte;
  unsigned int bloque_m;
  unsigned int linea_mc;
  unsigned int tag;
  unsigned int miss;		// boolea que ens indica si es miss
  unsigned int replacement;	// boolea que indica si es reempla�a una linia valida
  unsigned int tag_out;		// TAG de la linia reempla�ada
  float t1, t2;			// Variables per mesurar el temps (NO modificar)

  t1 = GetTime ();
  /* Escriu aqui el teu codi */

  bloque_m = address >> 5;     //right shift >> 2⁵ = 32 (5 lsb)
  tag = bloque_m >> 7;	      //right shift >> 2⁷ = 128 (7 lsb)
  linea_mc = bloque_m & 0x7f;// (0x7f = 127 = 0111 1111, agafem 7 lsb)
  byte = address & 0x1f;    // (0x1f = 31 = 0001 1111, agafem 5 lsb de @)

  if (!cache[linea_mc].vBit || cache[linea_mc].tag != tag) miss = 1;			
  else miss = 0; //si bit validesa 0 o diferent tag, fallada

  if (miss && cache[linea_mc].vBit) replacement = 1;
  else replacement = 0; //si fallada i bit validesa set, substituir

  if (miss) {
  //si fallada, determinar si replacement o simplement escriure (cache buida (bit validesa 0))
    if (!replacement) {
	  cache[linea_mc].tag = tag;
	  cache[linea_mc].vBit = 1;
	} else {
	  tag_out = cache[linea_mc].tag;
	  cache[linea_mc].tag = tag;
	}
  }


  /* La funcio test_and_print escriu el resultat de la teva simulacio
   * per pantalla (si s'escau) i comproba si hi ha algun error
   * per la referencia actual. Tamb� mesurem el temps d'execuci�
   * */
  t2 = GetTime ();
  totaltime += t2 - t1;
  test_and_print (address, byte, bloque_m, linea_mc, tag,
		  miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void
final ()
{
  /* Escriu aqui el teu codi */

}
