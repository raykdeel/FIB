 /** @file fecha.hh
    @brief Especificacio de la clase fecha.
 */
#ifndef FECHA_HH
#define FECHA_HH
  
#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;


/** @class fecha
    @brief representa una fecha.    
 */
class fecha {
    
public:
    //constructora
    /** @brief constructora por defecto.
    s'executa automaticament al declarar una fecha.
    \pre <em>cierto</em>
    \post tenemos una fecha vacia.
    */
    fecha();
    
//modificadora
    /** @brief lee una fecha.
     \pre <em>cierto</em>
     \post la foto ha sido creada
     */
    void llegir();


//consultora

    /** @brief retorna la fecha en dias.
    \pre <em>cierto</em>
    \post nos devuelve un int con la fecha en dias.
    */
int consultar_dias() const;

    /** @brief introducimos 2 fechas y nos dice si nuestra fecha esta entre esas 2.
    \pre <em>cierto</em>
    \post si nuestra fecha esta entre las otras 2 devuelve cierto sino falso.
    */
bool comparar_fechas(const int& f1, const int& f2) const;



//escritura

    /** @brief nos escribe la fecha
     \pre <em>cierto</em>
     \post escribe la fecha
     */
void escribir() const;





private:
    /** @brief trasnforma la fecha de dias meses y años a solo dias 
    para que sea mas manejable a la hora de comparar fechas
    \pre <em>cierto</em>
    \post genera un int con la fecha en dias
    */
    void transforma();
    
    
    int dia,mes,any;
    int fdias; //es la fecha en dias
};

#endif
