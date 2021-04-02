//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_COMPILER_H
#define MODEL_COMPILER_H


#include <utility>

#include "../Util/Json.h"
#include "../Data Structures/SimplyLinkedList.h"
#include "../Util/Coms/Message.h"


class Compiler {
private:
    Json json;
    SimplyLinkedList<string> *TYPE_IDENTIFIER_LIST;
    SimplyLinkedList<string> *SUPPORTED_OPERTATOR_LIST;

public:

    /**
     * Splits a string in substrings, with the slice char as the blank space.
     * @param line string to split.
      * @return Linked list, with substrings, in order, first word on string, first on list.
     */
    static SimplyLinkedList<string> processLine(string line) {

        auto *result = new SimplyLinkedList<string>();
        int counter = 0;
        char character;
        string word;
        while (counter < line.length()) {
            character = line[counter];
            if (isblank(character)) {
                if (!word.empty()) {
                    result->append(word);
                    word.clear();
                }

            } else {
                word.push_back(character);
            }
            counter++;
        }
        result->append(word);
        return *result;
    }

    bool dataType(string basicString, string basicString1) {
        //todo: programar
        return true;
    }

/**
     * Method for interpreting an already processed by processLine()
     * @param processedLine list of words found in the line of code.
     */
    void interpretLine(SimplyLinkedList<string> processedLine) {
        auto *msg = new Message();
        int index = 0;
        int len = processedLine.getLen();
        string element;
        if (index >= len)
            return;
        element = processedLine.get(index);
        //***SI INICIA CON IDENTIFICADOR DE TIPO PRIMITIVO*** [1]
        if (TYPE_IDENTIFIER_LIST->boolSearch(element)) {
            string name;
            string value;
            msg->setAction(CREATE);
            msg->setType(element);
            index++;
            if (index >= len)
                return;
            element = processedLine.get(index);
            //*** SI EL NOMBRE DEESPUÉS DEL IDENTIFICADOR NO ES PALABRA RESERVADA Y NO ES UN IDENTIFICADOR USADO EN EL SERVIDOR***[2]
            if (!isVariableName(element) and !TYPE_IDENTIFIER_LIST->boolSearch(element)) {
                name = (element);
                index++;
                if (index >= len)
                    return;
                element = processedLine.get(index);
                //*** SI SIGUE UN OPERADOR "=" *** [3]
                if (EQUAL_OPERATOR == element) {
                    index++;
                    if (index >= len)
                        return;
                    element = processedLine.get(index);
                    //*** SI EL NOMBRE DEESPUÉS DEL IDENTIFICADOR NO ES PALABRA RESERVADA Y COINCIDE CON EL TIPO QUE SE ASIGNÓ EN [1] *** [4]
                    if (!TYPE_IDENTIFIER_LIST->boolSearch(element) and
                        dataType(element, processedLine.get(0))) {
                        value = (element);
                        msg->fillJson(name, value);
                        msg->show();
                    } else {
                        cout << ERROR_DATA_TYPE;
                    }
                } else {
                    cout << ERROR_OPERATOR_ASSIGN_VALUE;
                }
            } else {
                cout << ERROR_NAME_OF_VARIABLE;
            }
            // *** SI EL VALOR ESTÁ GUARDADO COMO UNA VARIABLE EN EL SERVIDOR +++ [5]
        } else if (isVariableName(element)) {
            index++;
            if (index >= len)
                return;
            element = processedLine.get(index);
            // *** SI EL SIGUIENTE VALOR ES UN OPERADOR DE LA LISTA *** [6]
            if (SUPPORTED_OPERTATOR_LIST->boolSearch(element)) {
                msg->setAction(MODIFY);
                index++;
                if (index >= len)
                    return;
                element = processedLine.get(index);
                // *** SI EL VALOR ESTÁ GUARDADO COMO UNA VARIABLE EN EL SERVIDOR +++ [7]
                if (isVariableName(element)) {
                    // TODO: ENVIAR REQUEST PARA HACER OPERACION ENTRE VARIABLE 1 Y VARIABLE 2.
                }
            }

        } else {
            cout << ERROR_DATA_TYPE;
        }
    }

    bool isVariableName(string key) {
        Message *msg = new Message();
        msg->setAction(SEARCH);
        msg->setFirstVariable(key);//nombre a buscar
        msg->show();
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

    }
};


#endif //MODEL_COMPILER_H
