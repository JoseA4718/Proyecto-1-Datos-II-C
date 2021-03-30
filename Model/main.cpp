#include <iostream>
#include "src/Types/Int/Integer.h"
#include "src/Util/Json.h"

int main() {
    Json *json = new Json();
    int i = 87;
    auto *var = new Integer(&i, "Var1", 87);
    json->generateJson<int>(var);
    return 0;
}
