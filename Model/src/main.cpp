
#include "Types/Int/Integer.h"
#include "Util/Json.h"

int main() {
    Json *json = new Json();
    int a = 8;
    void *dir = malloc(sizeof(Integer));
    cout << dir << "\n";
    Integer *test = new Integer(dir, "testVar", 8);
    cout << json->generateJson(test) << "\n";
    void *dir2 = malloc(sizeof(Reference));

    Reference *pointerToTestVar = new Reference(dir2, test->getAddr(), "refToTest");
    pointerToTestVar->show();
    return 0;
}