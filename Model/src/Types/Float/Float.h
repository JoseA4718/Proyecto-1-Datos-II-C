//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_FLOAT_H
#define MODEL_FLOAT_H


#include "../GenericType.h"

class Float : public GenericType<float> {
public:
    Float(string key, float value) {
        this->addr = nullptr;
        this->value = value;
        this->size = FLOAT_SIZE;
        this->key = key;
        this->referenceCount = 0;
        this->value = value;

    }

};


#endif //MODEL_FLOAT_H
