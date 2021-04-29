//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_LONG_H
#define MODEL_LONG_H


#include "Model/src/Types/GenericType.h"
/**
 * This is the Long class
 */
class Long : public GenericType {
public:
    Long(string key, const char *value) {
        this->addr = nullptr;
        this->value = value;

        this->size = LONG_SIZE;
        this->key = key;
        this->referenceCount = 0;
    }

};


#endif //MODEL_LONG_H
