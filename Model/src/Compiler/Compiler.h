//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_COMPILER_H
#define MODEL_COMPILER_H

#include "../Util/Json.h"
#include "../Data Structures/SimplyLinkedList.h"+

//RESERVED WORD FOR THE LANGUAGE
static const auto INTEGER_KEY_WORD = "Integer";
static const auto FLOAT_KEY_WORD = "Float";
static const auto DOUBLE_KEY_WORD = "Double";
static const auto CHAR_KEY_WORD = "Char";
static const auto LONG_KEY_WORD = "Long";
static const auto REFERENCE_KEY_WORD = "Reference";
static const auto STRUCT_KEY_WORD = "Struct";


class Compiler {
private:
    Json json;
    SimplyLinkedList<string> *TYPE_IDENTIFIER_LIST;

    Compiler() {
        TYPE_IDENTIFIER_LIST = new SimplyLinkedList<string>();

        TYPE_IDENTIFIER_LIST->append(INTEGER_KEY_WORD)
                .append(FLOAT_KEY_WORD)
                .append(DOUBLE_KEY_WORD)
                .append(CHAR_KEY_WORD)
                .append(LONG_KEY_WORD)
                .append(REFERENCE_KEY_WORD)
                .append(STRUCT_KEY_WORD);
    }

public:

    /**
     * Splits a string in substrings, with the slice char as the blank space.
     * @param line string to split.
      * @return Linked list, with substrings, in order, first word on string, first on list.
     */
    static SimplyLinkedList<string> processLine(string line) {
        auto *result = new SimplyLinkedList<string>();
        char character;
        int counter = 0;
        string word;
        while (counter < line.length()) {
            character = line[counter];
            if (isblank(character) and !word.empty()) {
                result->append(word);
                result->show();
                word.clear();
            } else {
                word.push_back(character);
            }
            counter++;
        }
        result->append(word);
        return *result;
    }

    static void interpretLine(SimplyLinkedList<string> processedLine) {

    }
};


#endif //MODEL_COMPILER_H
