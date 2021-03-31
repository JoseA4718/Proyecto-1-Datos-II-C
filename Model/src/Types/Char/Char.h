//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_CHAR_H
#define MODEL_CHAR_H


#include "../GenericType.h"

class Char : public GenericType<char> {
public:
    Char(char *ptr, string key, char value);

};


#endif //MODEL_CHAR_H
