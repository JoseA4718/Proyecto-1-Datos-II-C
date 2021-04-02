#include "Types/Int/Integer.h"
#include "Util/Json.h"
#include "Compiler/Compiler.h"
#include "Data Structures/SimplyLinkedList.h"

int main() {

    auto *compiler = new Compiler();


    // ERROR CON EL TIPO DE DATO


    string linea2 = "Integer var = 2";
    compiler->compile(linea2);


}