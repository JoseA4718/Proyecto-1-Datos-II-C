#include "Types/Int/Integer.h"
#include "Util/Json.h"
#include "Compiler/Compiler.h"
#include "Data Structures/SimplyLinkedList.h"

int main() {
    Compiler *compiler = new Compiler();
    string linea = "angosto = a_momir";
    SimplyLinkedList<string> processedLine = compiler->processLine(linea);
    processedLine.show();
    compiler->interpretLine(processedLine);
}