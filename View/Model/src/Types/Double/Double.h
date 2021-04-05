//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_DOUBLE_H
#define MODEL_DOUBLE_H


#include "../GenericType.h"

class Double : public GenericType {
public:
    Double(string key, const char *value) {
        this->size = DOUBLE_SIZE;
        this->addr = nullptr;
        this->key = key;
        this->referenceCount = 0;
        this->value = value;

    }
};


#endif //MODEL_DOUBLE_H
