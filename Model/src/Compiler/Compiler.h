//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_COMPILER_H
#define MODEL_COMPILER_H

#include <utility>

#include "../Util/Json.h"
#include "../Data Structures/SimplyLinkedList.h"+
#include "../Util/Coms/Message.h"

//RESERVED WORD FOR THE LANGUAGE
static const auto INTEGER_KEY_WORD = "Integer";
static const auto FLOAT_KEY_WORD = "Float";
static const auto DOUBLE_KEY_WORD = "Double";
static const auto CHAR_KEY_WORD = "Char";
static const auto LONG_KEY_WORD = "Long";
static const auto REFERENCE_KEY_WORD = "Reference";
static const auto STRUCT_KEY_WORD = "Struct";
//OPERATORS
static const auto EQUAL_OPERATOR = "=";

class Compiler {
private:
    Json json;
    SimplyLinkedList<string> *TYPE_IDENTIFIER_LIST;
    SimplyLinkedList<string> *SUPPORTED_OPERTATOR_LIST;

private:

    /**
     * Splits a string in substrings, with the slice char as the blank space.
     * @param line string to split.
      * @return Linked list, with substrings, in order, first word on string, first on list.
     */
    static SimplyLinkedList<string> processLine(string line) {
        //FIXME: fijo peta con el struct
        auto *result = new SimplyLinkedList<string>();
        char character;
        int counter = 0;
        string word;
        while (counter < line.length()) {
            character = line[counter];
            if (isblank(character) and !word.empty()) {
                result->append(word);
                word.clear();
            } else {
                word.push_back(character);
            }
            counter++;
        }
        result->append(word);
        return *result;
    }

    /**
     * Method for interpreting an already processed by processLine()
     * @param processedLine list of words found in the line of code.
     */
    void interpretLine(SimplyLinkedList<string> processedLine) {
        //empty message
        auto *msg = new Message();
        //ASIGNAR VALOR A VARIABLE NUEVA
        if (TYPE_IDENTIFIER_LIST->boolSearch(processedLine.get(0))) {
            cout << "Tipo de dato: " << processedLine.get(0) << "|";
            msg->setType(processedLine.get(0));//añadir el tipo de dato al mensaje :)
            //si el valor que sigue no está definido en el servidor Y NO ES UN IDENTIFICADOR
            if (!isVariableName(processedLine.get(1)) and !TYPE_IDENTIFIER_LIST->boolSearch(processedLine.get(1))) {
                cout << "Nombre de la variable: " << processedLine.get(1) << "|";

                if (SUPPORTED_OPERTATOR_LIST->boolSearch(processedLine.get(2))) {
                    cout << "Operador: " << processedLine.get(2) << "|";
                    if (!TYPE_IDENTIFIER_LIST->boolSearch(processedLine.get(3))) {
                        cout << "Valor para asignar: " << processedLine.get(3) << "\n";
                    } else {
                        cout << "\nERROR CON EL TIPO DE DATO PARA ASIGNAR\n";

                    }
                } else {
                    cout << "\nERROR CON EL OPERADOR A UTILIZAR\n";

                }
            } else {
                cout
                        << "\nERROR CON EL NOMBRE DE LA VARIABLE\n";
            }
            //caso para cuando la varia
        }
            //MODIFICAR VALOR DE UNA VARIABLE YA ASIGNADA
        else if (isVariableName(processedLine.get(0))) {
            cout << "Variable: " << processedLine.get(0) << "\n";
            if (SUPPORTED_OPERTATOR_LIST->boolSearch(processedLine.get(1))) {
                cout << "Operación: " << processedLine.get(1) << "\n";
                if (isVariableName(processedLine.get(2))) {
                    cout << "Variable: " << processedLine.get(2) << "\n";
                }
            }

        } else {
            cout << "\nERROR: Valor no definido\n";
        }
    }

    bool isVariableName(string key) {
        Message *msg = new Message();
        msg->setAction(SEARCH);
        msg->setName(key);//nombre a buscar
        // TODO: HACER CLASE QUE SE ENCARGUE DE CONSULTAR AL SERVIDOR Y METER ESTE CÓDIGO AHÍ....
        return false;
    }

    bool isStruct(string key) {
        //TODO: agregar carnita :)
        return false;
    }

public:
    void compile(string line) {
        SimplyLinkedList<string> processedLine = processLine(std::move(line));
        interpretLine(processedLine);
    }

    Compiler() {
        TYPE_IDENTIFIER_LIST = new SimplyLinkedList<string>();
        SUPPORTED_OPERTATOR_LIST = new SimplyLinkedList<string>();


        TYPE_IDENTIFIER_LIST->append(INTEGER_KEY_WORD);
        TYPE_IDENTIFIER_LIST->append(FLOAT_KEY_WORD);
        TYPE_IDENTIFIER_LIST->append(DOUBLE_KEY_WORD);
        TYPE_IDENTIFIER_LIST->append(CHAR_KEY_WORD);
        TYPE_IDENTIFIER_LIST->append(LONG_KEY_WORD);
        TYPE_IDENTIFIER_LIST->append(REFERENCE_KEY_WORD);
        TYPE_IDENTIFIER_LIST->append(STRUCT_KEY_WORD);
        SUPPORTED_OPERTATOR_LIST->append(EQUAL_OPERATOR);
        TYPE_IDENTIFIER_LIST->show();
        SUPPORTED_OPERTATOR_LIST->show();
    }
};


#endif //MODEL_COMPILER_H
