 /** @file coleccion.hh
    @brief Especificacio de la clase coleccion.
 */
#ifndef COLECCION_HH
#define COLECCION_HH
 
#include "foto.hh"
#include "fecha.hh"
#include "ConsultaBool_IO.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include "BinTree.hh"
#endif

using namespace std;
typedef pair<string,pair<string,pair<fecha,fecha>>> tkaux; //esto es una guarrada pero 
// estaba teniendo problemas a la hora de implementar token y por eso lo he implentado asi
//esto representa idconsulta<tag,<fecha ini, fecha fin>>

/** @class coleccion
    @brief Es la clase principal de la practica y representa una coleccion de fotos.    
    Esta creado por un diccionario de identificadores un album donde guardamos las fotos.
    Ademas tenemos el album en curso.
 */
class coleccion {
    
public:
    //constructora
        /** @brief Constructora por defecto. Se ejecuta automaticamente al declarar una coleccion.
            \pre <em>cierto</em>
            \post Tenemos una coleccion de imagenes vacia.
        */
    coleccion();
    
    
    
    
    
    //modificadoras
    
        /** @brief Nos dan un identificador y leemos el arbol de ese identificador.
            \pre <em>cierto</em>
            \post Hemos agregado un album.
        */
    void leer_album(const string& s);
    
        /** @brief Agregamos el arbol en curso a la coleccion.
            \pre <em>cierto</em>
            \post Hemos agregado un album a la coleccion.
        */
    void agrega_album();
    
        /** @brief Intorducimos el identificador de un album y si existe lo eliminamos.
            \pre <em>cierto</em>
            \post Hemos eliminado el album.
        */ 
    void eliminar_album(const string& s);
    
        /** @brief Agregamos o eliminamos una foto del album.
            \pre <em>cierto</em>
            \post hemos modificado el album
        */ 
    void modificar_album(const string& op,const string& s);
    
        /** @brief Agregamos o eliminamos una foto del album all.
            \pre <em>cierto</em>
            \post Hemos modificado el album all o hemos devuelto que no se podia.
        */ 
    void modificar_all(const string& s,const string& op);
    
        /** @brief nos dan un identificador y hemos de buscarla en all y si existe la modificamos.
            \pre <em>cierto</em>
            \post hemos modificado la foto o hemos devuelto que no existia.
     */
    void modificar_foto_col(const string&s);
    

    //escriptura
        /** @brief escribe la informacion de una foto si la encuentra y sino nos dice que no existe
            \pre <em>cierto</em>
            \post nos da o un identificador de que la foto no existe o la escribe
        */
    void obten_foto(const string& s) const;    

    /** @brief escribe el numero de fotos del album en curso
        \pre <em>cierto</em>
        \post nos escribe el numero de fotos 
     */
    
    void nr_fotos() const;

        /** @brief Le damos un identificador y escribe ese album ademas pasa a ser nuestro aec.
            \pre <em>cierto</em>
            \post Escribe el album en cuestion si existe y sino nos indica que hay un error.
        */
        
    void obten_album(const string& s);
        /** @brief Nos devuelve el numero de albumes en la coleccion.
            \pre <em>cierto</em>
            \post Escribe el numero de albumes.
        */
        
    void imprimir_nr_albums() const;
        /** @brief Escribe el identificador de los albumes.
            \pre <em>cierto</em>
            \post Nos devuelve el identificador de los arboles en orden lexicografico ascendente.
        */
    void lista_albumes() const;

        /** @brief Escribe todos los albumes en los que se encuentra la foto que buscamos.
            \pre <em>cierto</em>
            \post nos escribe todos los albumes en los que se encuentra la foto.
        */
    void albumes_foto(const string& s) const;

        /** @brief nos dan la fecha y el identificador de 2 albumes y si el primero existe
        escribe el contenido de la busqueda y ademas el segundo pasa a ser el album en curso
            \pre <em>cierto</em>
            \post escribe la busqueda y el album 2 pasa a ser el 1
        */
    void buscar_por_fecha(const string& s, const string& g,const fecha& f1,const fecha& f2);

        /** @brief Nos dan una etiqueta y el identificador de 2 albumes y si el primero existe 
        escribe el contenido de la busqueda y ademas el segundo pasa a ser el primero
            \pre <em>cierto</em>
            \post Escribe o un error o el resultado de la busqueda.
        */
    void buscar_por_etiq(const string& s, const string& p, const string& g);

        /** @brief Nos dan 2 identificadores y si existe un album con el primer identificador
        le hacemos una evaluacion booleana.
            \pre <em>cierto</em>
            \post Retorna o un error o la evaluacion booleana.
        */
    void evalua_const_bool(const string& s, const string& g);

        /** @brief Imprimimos el album en curso.
            \pre <em>cierto</em>
            \post Escribimos el album en curso
        */
        void escribir_aec() const;

        /** @brief Imprime la coleccion.
            \pre <em>cierto</em>
            \post La imprime.
        */
        void escribir_col() const;



private:
        /** @brief Le damos 2 conjuntos de fotos y retorna las fotos que esten en ambos.
            \pre <em>cierto</em>
            \post Las devuelve.
        */
    set<string> booland(set<string>& a1,set<string>& a2);
        /** @brief Junta los 2 conjuntos de fotos.
            \pre <em>cierto</em>
            \post Las devuelve.
        */
    set<string> boolor(set<string>& a1,set<string>& a2);
        /** @brief Le damos 1 conjuntos de foto y el identificador de un album y devulve
         las fotos que solo esten en el album.
            \pre <em>cierto</em>
            \post Las devuelve.
        */
    set<string> boolnot(set<string>&a1,const string& s);
        /** @brief Devuelve las fotos que tengan el tag dentro del identificador.
            \pre <em>cierto</em>
            \post Las devuelve.
        */
    
    set<string> tag(const string& s, const string& g);
        /** @brief Devuelve las fotos que esten entre las 2 fechas dentro del identificador.
            \pre <em>cierto</em>
            \post Las devuelve.
        */
    set<string> date(const string& s,const fecha& f1, const fecha& f2);
        /** @brief Realiza un recorrido_arbol por el arbol y va haciendo las funciones de consulta.
            \pre <em>cierto</em>
            \post devulve un stack con el album resultado de las consultas.
        */
    void recorrido_arbol(const BinTree<tkaux>& a, const string& s, stack<set<string>>& sa);
    
    
    
    
    
    
    
    
    
    /** @class album
    @brief album es una subclase de coleccion a la que solo puede acceder coleccion.
    Y representa el album en curso y el album all.
    */
    class album {
    public:
    //constructora
        /** @brief Constructora por defecto.
        Se ejecuta automaticamente al declarar un album.
            \pre <em>cierto</em>
            \post Tenemos un album vacio.
        */
    album();
    
    
    //modificadoras
        /** @brief Lee un album.
            \pre <em>cierto</em>
            \post Tenemos un album con fotos.
        */
    void lee_album();

        /** @brief Vacia el album.
            \pre <em>cierto</em>
            \post Lo vacia.
        */
    
    void vaciar_album();


        /** @brief Agrega una foto al album si la foto no existe.
            \pre <em>cierto</em>
            \post Si la foto no esta en el album la agrega si esta entonces no hace nada
        */
    void agrega_foto(const pair<string,foto>& pf);

        /** @brief Elimina una foto al album.
            \pre <em>cierto</em>
            \post Hemos eliminado la foto al album.
        */
    void elimina_foto(const string& s);

        /** @brief Nos dan una foto con su identificador y la modificamos en el album;
            \pre <em> cierto </em>
            \post Hemos modificado la imagen.
        */
    void modificar_foto(const pair<string,foto>& pf);

    
    //consultora
        /** @brief Pregunta si existe una imagen con el identificador al album.
            \pre <em>cierto</em>
            \post si existe retorna cierto
        */
    bool existeix_foto(const string& s) const;

        /** @brief retorna el numero de fotos del album
        \pre <em> cierto </em>
        \post retorna el numero de fotos
        */
    int nrfotos() const;
        /** @brief Retorna el identificador de la foto en la posicion i.
        \pre <em> cierto </em>
        \post Si existe una foto en esa posicion nos devulve su identificador.
        */
    string consultar_nom(int i) const;
        
        /** @brief Retorna la posicion de la foto en con el identificador s.
        \pre <em> cierto </em>
        \post Si existe una foto con ese identificador nos devulve su posicion.
        */
    int consultar_posicio(const string& s) const;
        
        /** @brief Devolvemos la foto que esta en la posicion que nos han dado.
        \pre <em> cierto </em> 
        \post Devolvemos la foto con su identificador.
        */
    pair<string,foto> consultar_iesimo(int i) const;
        
        /** @brief Devolvemos un set con el identificador de todas las fotos en el album.
        \pre <em> cierto </em> 
        \post Devolvemos un set de identificadores.
        */
    
    set<string> consultar_nom_fotos() const;
        /** @brief Devolvemos la foto con el identificador dado.
        \pre <em> cierto </em> 
        \post Devolvemos la foto con su identificador.
        */
    pair<string,foto> consultar_foto(const string&s) const;

    //escriptura
        /** @brief nos dan el identificador de una foto y si existe la escribe.
        \pre <em>cierto</em>
        \post  si la foto existe escribe la imagen.
        */
    void obten_foto(const string& s) const;
        /** @brief Escribe el numero de fotos del album.
        \pre <em>cierto</em>
        \post Lo escribe.
        */
    void imprimir_nr_fotos() const;

        /** @brief Escribe el album.
        \pre <em>cierto</em>
        \post Lo escribe.
        */
    void escribir_album() const;
    
    private:
    map<string,foto> al; //contiene el nombre de la foto y la foto
    };



    map<string,set<string>> col; //coleccion de albumes con los identificadores de imagenes;
    album all; //coleccion de imagentes
    string idaec; //id album en curso
    album aec;//album en curso.(Aun estando en la clase coleccion representa que esta fuera)
};

#endif
