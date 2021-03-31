
#include "Types/Int/Integer.h"
#include "Util/Json.h"

int main() {
    Json *json = new Json();
    int a = 8;
    void *dirVariable = malloc(sizeof(Integer));
    void *dirReference = malloc(sizeof(Reference));

    cout << "Variable stored in: " << dirVariable << "\n";
    cout << "Reference stored in: " << dirReference << "\n";


    Integer *test = new Integer(dirVariable, "testVar", 8);

    Reference *pointerToTestVar = new Reference(dirReference, test->getAddr(), "refToTest");
    cout << "---------------------------------------\n";

    pointerToTestVar->show();
    cout << "---------------------------------------\n";
    cout << json->generateJson(test) << "\n";
    cout << "---------------------------------------\n";
    cout << json->generateJson(pointerToTestVar) << "\n";

    return 0;
}