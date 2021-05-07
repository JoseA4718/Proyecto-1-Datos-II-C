//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_COMPILER_H
#define MODEL_COMPILER_H


#include <utility>
#include "../Util/Json.h"
#include "../Data Structures/SimplyLinkedList.h"
#include "../Util/Coms/Message.h"
#include "../Socket/Client.h"
#include "../ServerConnection.h"


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
            } else if (character == '=') {
                if (!word.empty()) {
                    result->append(word);
                    word.clear();
                }
                word.push_back(character);
                result->append(word);
                word.clear();
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
        string result;
        string element;
        element = processedLine.get(index);
        //***SI INICIA CON IDENTIFICADOR DE TIPO PRIMITIVO*** [1]
        if (TYPE_IDENTIFIER_LIST->boolSearch(element)) {
            string name = "";
            string value = "";
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
                        result = (element + ERROR_DATA_TYPE);
                    }
                } else if (element == ";") {
                } else {
                    result = (element + ERROR_OPERATOR_ASSIGN_VALUE);
                }
            } else {
                result = (element + ERROR_NAME_OF_VARIABLE);
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
                if (!element.empty()) {
                    //todo:
                    msg->setSecondVariable(element);
                }
            } else {
                result = (element + ERROR_OPERATOR_ASSIGN_VALUE);
            }
        } else if (STRUCT_KEY_WORD == (element)) {
            result = ("NOT IMPLEMENTED");
        } else {
            result = (element + ERROR_DATA_TYPE);
        }
        if (result.empty()) {
            result = Json::generateJson(msg);
        }
        return result;
    }
    /**
     * @brief Checks if the string segment that is currently reading is a variable in the server.
     * @param key string key value
     * @return boolean response
     */
    static bool isVariableName(string key) {
        cout << "Searching for..." << key << endl;
        bool temp = true;
        auto *msg = new Message();
        msg->setAction(SEARCH);
        msg->setFirstVariable(key);
        Response *resp = ServerConnection::sendMessage(Json::generateJson(msg));
        if (resp->getStatusCode() == NOT_FOUND) {
            cout << "Not found" << endl;
            temp = false;
        }
        return temp;
    }
    /**
     * @brief Checks what kind of generic type it is and returns the size of it.
     * @param key Key value of the object
     * @return returns size in memory of the specific generic type.
     */
    int getSize(const string &key) {
        for (int i = 0; i < TYPE_IDENTIFIER_LIST->getLen(); ++i) {
            if (TYPE_IDENTIFIER_LIST->get(i) == key) {
                return TYPE_SIZES_LIST->get(i);
            }
        }
    }
    /**
     * @brief Checks if the currently checked object is a struct
     * @param key Key value of the object
     * @return returns boolean response
     */
    bool isStruct(string key) {
        //TODO: agregar carnita :)
        return false;
    }

public:
    /**
     * @brief Compiles the line that it receives as a parameter
     * @param line String line to compile
     * @return either returns the interpreted line, or the exception if there is an error
     */
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
