#include "Types/Int/Integer.h"
#include "Util/Json.h"
#include "Compiler/Compiler.h"
#include "Data Structures/SimplyLinkedList.h"

int main() {
    Compiler *compiler = new Compiler();
    //UNA LINEA QUE COMPILA
    string linea = "Integer var = 4";
    compiler->compile(linea);

    // ERROR CON EL TIPO DE DATO
    string linea2 = "integer  var = 4";
    compiler->compile(linea2);

    //ERROR CON EL NOMBRE DE LA VARIABLE
    string linea3 = "Integer Char  = 4";
    compiler->compile(linea3);

    //ERROR CON EL OPERADOR
    string linea4 = "Integer  == 4";
    compiler->compile(linea4);

}