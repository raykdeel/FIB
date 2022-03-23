#include "ConsultaBool_IO.hh"


struct token {
    string tipo; // tipo de la consulta: TAG, DATE, AND, OR o NOT
    string etq; // si tipo == "TAG", esta es la etiqueta
    fecha fini, ffin; // si tipo == "DATE", estas son las fechas de inicio y fin
                      // se asume que existe una clase Fecha y que hay una operacion para
                      // leer fechas
}; 

typedef pair<string,pair<string,pair<fecha,fecha>>> tkaux;

/** TIPOS Y CABECERAS DE FUNCIONES AUXILIARES; NO MODIFICAR **/



string toupper(const string& s);
int precedence(string oper);

ConsultaBool::ConsultaBool(){}
    
ConsultaBool::ConsultaBool(const string& s) {
    tkaux t;
    t.first="TAG";
    t.second.first=s;
    ar=BinTree<tkaux>(t);
}
ConsultaBool::ConsultaBool(const fecha& fini, const fecha& ffin ){
    tkaux t;
    t.first= "DATE";
    t.second.second.first=fini;
    t.second.second.second=ffin;
    ar=BinTree<tkaux>(t);
}
    
    
BinTree<tkaux> ConsultaBool::consultararbol() {     
    return ar;
}
    
    
ConsultaBool ConsultaBool::AND(const ConsultaBool& q2) { 
    tkaux pt;
    pt.first="AND";
    BinTree<tkaux>right=q2.ar;
    BinTree<tkaux>left=ar;
    ar=BinTree<tkaux>(pt,left,right);
    return *this;
}
ConsultaBool ConsultaBool::OR(const ConsultaBool& q2)  {
    tkaux pt;
    pt.first="OR";
    BinTree<tkaux>right=q2.ar;
    BinTree<tkaux>left=ar;
    ar=BinTree<tkaux>(pt,left,right);
    return *this;
}
    
ConsultaBool ConsultaBool::NOT(){
    tkaux t;
    t.first= "NOT";
    BinTree<tkaux>left=ar;
    BinTree<tkaux>right;
    ar=BinTree<tkaux>(t,left,right);
    return *this;
}
// cambiad nombres o la sintaxis de las llamadas para adaptar este codigo vuestra clase ConsultaBool,
ConsultaBool ConsultaBool::construct_bool_query(const vector<token>& postfix) {
    stack<ConsultaBool> S;
    for (int i = 0; i < postfix.size(); ++i) {
        token tk = postfix[i];
        if (tk.tipo == "TAG") S.push(ConsultaBool(tk.etq)); // apila una consulta TAG
        if (tk.tipo == "DATE") S.push(ConsultaBool(tk.fini, tk.ffin)); // apila una consulta DATE
        if (tk.tipo == "AND" or tk.tipo == "OR") {
            ConsultaBool q2 = S.top(); S.pop();
            ConsultaBool q1 = S.top(); S.pop();
            if (tk.tipo == "AND") S.push(q1.AND(q2)); // apila una consulta 'q1 and q2'
            if (tk.tipo == "OR") S.push(q1.OR(q2)); // apila una consulta 'q1 or q2'
        }
        if (tk.tipo == "NOT") {
            ConsultaBool q = S.top(); S.pop(); 
            S.push(q.NOT()); // apila una consulta 'not q'
        }
    }
    return S.top();
}

// Operacion de lectura de vuestra clase de consultas booleanas
// - lee la expresion desde el canal de entrada 'is'  (mas general que leer desde 'cin')
// - normalmente no deberiais cambiar nada, excepto quizás
// el nombre la clase on la que representais las consultas, es decir, cambiar ConsultaBool por lo
// que corresponda y el nombre del metodo si os gusta mas otro, por ejemplo read ==> llegir
void ConsultaBool::read(istream& is) {
    vector<token> infix, postfix;
    read_input(is, infix);
    if (infix.empty()) { 
        *this = ConsultaBool();
        return; 
    }
    
    convert_infix_to_postfix(infix, postfix);
    *this = construct_bool_query(postfix);
}

// esta funcion asume que lee una secuencia de strings que empieza con BEGIN_QUERY y acaba
// con END_QUERY y sigue el formato descrito en este mismo fichero asi como en el enunciado de
// la practica; en vez de leer desde el 'cin', es mas general y lee desde un canal de entrada 'is' 
// proporcionado como parametro de entrada/salida del procedimiento;
// es posible/probable que tengais que cambiar el codigo (marcado con /** .... **/) que lee fechas de inicio
// y final para una subexpresion booleana correspondiente a una consulta DATE
// pero no os hará falta cambiar nada más
void ConsultaBool::read_input(istream& is, vector<token>& l) {
    string s; 
    is >> s; 
    while (s != "END_QUERY") {
        token tk;
        s = toupper(s);
        tk.tipo = s;
        if (s == "(" or s == ")" or s == "AND" or s == "OR" or s == "NOT") { 
            l.push_back(tk);
        }
        if (s == "DATE") { /** usad el metodo Fecha::llegir() o similar si no teneis
                            sobrecargado el operador >> para leer fechas **/
            tk.fini.llegir();
            tk.ffin.llegir(); 
            l.push_back(tk);
        }
        if (s == "TAG") {
            is >> tk.etq;
            l.push_back(tk);
        }      
        is >> s;
    }
}

/** NO CAMBIAR NADA A PARTIR DE ESTE PUNTO **/
string toupper(const string& s) {
    string res = "";
    for (int i = 0; i < s.length(); ++i)
        res += toupper(s[i]);
    return res;
}

int precedence(string oper) {
    if (oper == "OR") return 1;
    if (oper == "AND") return 2;
    if (oper == "NOT") return 3;
    return 0;
}

void ConsultaBool::convert_infix_to_postfix(const vector<token>& infix, vector<token>& postfix) {
    stack<token> S;
    token spc; spc.tipo = "#"; S.push(spc);
    for (int i = 0; i < infix.size(); ++i) {
        token tk = infix[i];
        if (tk.tipo == "DATE" or tk.tipo == "TAG")
            postfix.push_back(tk);
        else if (tk.tipo == "(" or tk.tipo == "NOT") 
            S.push(tk);
        else if (tk.tipo == ")") {
            while (S.top().tipo != "#" and S.top().tipo != "(") {
                postfix.push_back(S.top()); S.pop();
            }
            S.pop();
        } else {
            while (S.top().tipo != "#" and 
                precedence(tk.tipo) <= precedence(S.top().tipo)) {
                    postfix.push_back(S.top()); S.pop();
            }
            S.push(tk);
        }
    }
    while (S.top().tipo != "#") {
        postfix.push_back(S.top()); S.pop();
    } 
}
