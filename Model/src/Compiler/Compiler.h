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


class Compiler {
private:
    Json json;
public:
    void processLine(string line);
};


#endif //MODEL_COMPILER_H
