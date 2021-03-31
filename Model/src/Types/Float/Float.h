//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_FLOAT_H
#define MODEL_FLOAT_H


#include "../GenericType.h"

class Float : public GenericType<float> {
public:
    Float(void *ptr, string key) {
        this->addr = ptr;
        this->size = FLOAT_SIZE;
        this->key = key;
        this->counter = 0;
    }

};


#endif //MODEL_FLOAT_H
