//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_DOUBLE_H
#define MODEL_DOUBLE_H


#include "../GenericType.h"

class Double : public GenericType<double> {
public:
    Double(void *ptr, string key) {
        this->size = DOUBLE_SIZE;
        this->addr = ptr;
        this->key = key;
        this->referenceCount = 0;

    }
};


#endif //MODEL_DOUBLE_H
