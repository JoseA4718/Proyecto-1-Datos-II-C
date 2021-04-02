//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_INTEGER_H
#define MODEL_INTEGER_H


#include "../GenericType.h"

class Integer : public GenericType<int> {
public:
    Integer() {

    }

    Integer(string key, const char *value) {
        this->size = INT_SIZE;
        this->referenceCount = 0;
        this->addr = nullptr;
        this->key = key;
        this->value = value;

    }

};


#endif //MODEL_INTEGER_H
