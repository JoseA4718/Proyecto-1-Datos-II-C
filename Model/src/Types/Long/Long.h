//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_LONG_H
#define MODEL_LONG_H


#include "../GenericType.h"

class Long : public GenericType<long> {
public:
    Long(void *ptr, string key) {
        this->addr = ptr;
        this->size = LONG_SIZE;
        this->key = key;
        this->referenceCount = 0;
    }

};


#endif //MODEL_LONG_H
