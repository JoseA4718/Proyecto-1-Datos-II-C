//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_INTEGER_H
#define MODEL_INTEGER_H


#include "../GenericType.h"

class Integer : public GenericType<int> {
public:
    Integer(void *addr, string key, int value) {
        this->size = INT_SIZE;
        this->referenceCount = 0;

        this->addr = addr;
        this->key = key;
        this->value = value;

    }

};


#endif //MODEL_INTEGER_H
