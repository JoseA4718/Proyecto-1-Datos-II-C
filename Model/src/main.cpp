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


    SimplyLinkedList<int> *lista = new SimplyLinkedList<int>();
    lista->append(1);
    lista->append(2);
    lista->append(3);
    lista->append(4);
    cout << lista->is(4);
}