//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_COMPILER_H
#define MODEL_COMPILER_H

//RESERVED WORD FOR THE LANGUAGE
static const auto INTEGER_KEY_WORD = "Integer";
static const auto FLOAT_KEY_WORD = "Float";
static const auto DOUBLE_KEY_WORD = "Double";
static const auto CHAR_KEY_WORD = "Char";
static const auto LONG_KEY_WORD = "Long";
static const auto REFERENCE_KEY_WORD = "Reference";
static const auto STRUCT_KEY_WORD = "Struct";


#include "../Util/Json.h"
#include "../Data Structures/SimplyLinkedList.h"+

class Compiler {
private:
    Json json;
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

    static string isNativeTypeDef(const string &word) {

    }
};


#endif //MODEL_COMPILER_H
