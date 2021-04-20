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
    SimplyLinkedList<string> *TYPE_IDENTIFIER_LIST;
    SimplyLinkedList<string> *SUPPORTED_OPERTATOR_LIST;
    SimplyLinkedList<int> *TYPE_SIZES_LIST;


public:

    /**
     * Splits a string in substrings, with the slice char as the blank space or the semicolon.
     * @param line string to split.
      * @return Linked list, with substrings, in order, first word on string, first on list.
     */
    static SimplyLinkedList<string> processLine(string line) {
        bool flag = false;
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
            } else if (character == ';') {
                if (!word.empty()) {
                    result->append(word);
                    word.clear();
                }
                word.push_back(character);
                result->append(word);
                word.clear();
                flag = true;
                break;
            } else {
                word.push_back(character);
            }
            counter++;
        }
        if (!flag)
            throw std::logic_error("Line does not end with a semicolon");
        return *result;
    }

    bool dataType(string basicString, string basicString1) {
        //todo: programar para obtener el tipo de dato ¿?
        return true;
    }

    /**
     * Method for interpreting an already processed by processLine()
     * @param processedLine list of words found in the line of code.
     */
    string interpretLine(SimplyLinkedList<string> processedLine) {
        auto *msg = new Message();
        int index = 0;
        int len = processedLine.getLen();
        string element;
        element = processedLine.get(index);
        //***SI INICIA CON IDENTIFICADOR DE TIPO PRIMITIVO*** [1]
        if (TYPE_IDENTIFIER_LIST->boolSearch(element)) {
            string name = "null";
            string value = "null";
            int size = getSize(element);
            msg->setAction(CREATE);
            msg->setSize(size);
            msg->setType(element);
            index++;
            element = processedLine.get(index);
            //*** SI EL NOMBRE DEESPUÉS DEL IDENTIFICADOR NO ES PALABRA RESERVADA Y NO ES UN IDENTIFICADOR USADO EN EL SERVIDOR***[2]
            if (!isVariableName(element) and !TYPE_IDENTIFIER_LIST->boolSearch(element)) {
                name = (element);
                index++;
                element = processedLine.get(index);
                //*** SI SIGUE UN OPERADOR "=" *** [3]
                if (EQUAL_OPERATOR == element) {
                    index++;
                    element = processedLine.get(index);
                    //*** SI EL NOMBRE DEESPUÉS DEL IDENTIFICADOR NO ES PALABRA RESERVADA Y COINCIDE CON EL TIPO QUE SE ASIGNÓ EN [1] *** [4]
                    if (!TYPE_IDENTIFIER_LIST->boolSearch(element) and
                        dataType(element, processedLine.get(0))) {
                        value = (element);
                    } else {
                        throw std::logic_error(ERROR_DATA_TYPE);
                    }
                } else if (element == ";") {
                } else {
                    throw std::logic_error(ERROR_OPERATOR_ASSIGN_VALUE);
                }
            } else {
                throw std::logic_error(ERROR_NAME_OF_VARIABLE);
            }
            //todo: http post con msg.to json
            msg->fillJson(name, value);
            // *** SI EL VALOR ESTÁ GUARDADO COMO UNA VARIABLE EN EL SERVIDOR *** [5]
        } else if (isVariableName(element)) {
            msg->setFirstVariable(element);
            index++;
            element = processedLine.get(index);
            // *** SI EL SIGUIENTE VALOR ES UN OPERADOR DE LA LISTA *** [6]
            if (SUPPORTED_OPERTATOR_LIST->boolSearch(element)) {
                msg->setAction(MODIFY);
                msg->setOperation(element);
                index++;
                element = processedLine.get(index);
                // *** SI EL VALOR ESTÁ GUARDADO COMO UNA VARIABLE EN EL SERVIDOR +++ [7]
                if (isVariableName(element)) {
                    //todo:
                    msg->setSecondVariable(element);
                }
            } else {
                throw std::logic_error("Operador no identificado: " + element);

            }
        } else if (STRUCT_KEY_WORD == (element)) {
            throw std::logic_error("NOT IMPLEMENTED");

        } else {
            throw std::logic_error(element + ERROR_DATA_TYPE);
        }
        return Json::generateJson(msg);
    }

    static bool isVariableName(string key) {
        auto *msg = new Message();
        msg->setAction(SEARCH);
        //todo: http get con el key (recibe un json)
        msg->setFirstVariable(key);//nombre a buscar
        // msg->show();
        // TODO: HACER CLASE QUE SE ENCARGUE DE CONSULTAR AL SERVIDOR Y METER ESTE CÓDIGO AHÍ....
        return false;
    }

    int getSize(const string &key) {
        for (int i = 0; i < TYPE_IDENTIFIER_LIST->getLen(); ++i) {
            if (TYPE_IDENTIFIER_LIST->get(i) == key) {
                return TYPE_SIZES_LIST->get(i);
            }
        }
    }

    bool isStruct(string key) {
        //TODO: agregar carnita :)
        return false;
    }

public:

    string compile(string line) {
        try {

            SimplyLinkedList<string> processedLine = processLine(std::move(line));
            return interpretLine(processedLine);
        }
        catch (std::logic_error e) {
            return e.what();
        } catch (std::out_of_range e) {
            return e.what();
        }


    }

    Compiler() {
        TYPE_IDENTIFIER_LIST = new SimplyLinkedList<string>();
        SUPPORTED_OPERTATOR_LIST = new SimplyLinkedList<string>();
        TYPE_SIZES_LIST = new SimplyLinkedList<int>();

        TYPE_IDENTIFIER_LIST->append(INTEGER_KEY_WORD);
        TYPE_SIZES_LIST->append(INT_SIZE);

        TYPE_IDENTIFIER_LIST->append(FLOAT_KEY_WORD);
        TYPE_SIZES_LIST->append(FLOAT_SIZE);

        TYPE_IDENTIFIER_LIST->append(DOUBLE_KEY_WORD);
        TYPE_SIZES_LIST->append(DOUBLE_SIZE);

        TYPE_IDENTIFIER_LIST->append(CHAR_KEY_WORD);
        TYPE_SIZES_LIST->append(CHAR_SIZE);

        TYPE_IDENTIFIER_LIST->append(LONG_KEY_WORD);
        TYPE_SIZES_LIST->append(LONG_SIZE);

        TYPE_IDENTIFIER_LIST->append(REFERENCE_KEY_WORD);
        TYPE_SIZES_LIST->append(REFERENCE_SIZE);

        SUPPORTED_OPERTATOR_LIST->append(EQUAL_OPERATOR);

    }

};


#endif //MODEL_COMPILER_H
