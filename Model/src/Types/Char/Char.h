//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_CHAR_H
#define MODEL_CHAR_H


#include "../GenericType.h"

class Char : public GenericType<char> {
public:
    Char(void *ptr, string key, char value) {
        this->size = CHAR_SIZE;
        this->addr = ptr;
        this->key = key;
        this->referenceCount = 0;
        this->value = value;
    }

};


#endif //MODEL_CHAR_H
