//
// Created by eduardo218 on 4/1/21.
//

#include "Compiler.h"

void Compiler::processLine(string line) {
    char character;
    int counter = 0;
    string result;

    while (counter < line.length()) {
        character = line[counter];
        if (isblank(character) and !result.empty()) {
            //todo: identificar si es tipo primitivo
            //todo: identificar con el servidor si el nombre ya está tomado
            //todo: identificar si es un struct
        }
        result.push_back(character);

        counter++;
    }


}
