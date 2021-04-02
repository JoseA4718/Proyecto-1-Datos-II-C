#include "Types/Int/Integer.h"
#include "Util/Json.h"
#include "Compiler/Compiler.h"
#include "Data Structures/SimplyLinkedList.h"

int main() {
/*
    //crear objeto y asignar valores
    Integer *variable = new Integer();
    variable->setKey("var1");
    variable->setValue("328");
    variable->setAddr("direction");

    //print del objeto
    variable->show();
    //convertir a json
    Json *converter = new Json();
    string json = converter->generateJson(variable);

    cout << json;

    //convertir de json
    Integer *variable2 = new Integer();
    converter->readJson(json, variable2);

    cout << variable->getAddr();
*/

    auto *comp = new Compiler();
    comp->processLine("ABCDEFGHIJK");

}