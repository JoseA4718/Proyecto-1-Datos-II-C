
#include "Types/Int/Integer.h"
#include "Util/Json.h"
#include "Compiler/Compiler.h"

int main() {
    auto *msg = new Message();
    msg->fillJson("var1", "234");
    msg->setAction(CREATE);
    msg->setType(INTEGER_KEY_WORD);
    cout << Json::generateJson(msg);


}