//
// Created by eduardo218 on 3/28/21.
//

#include "Integer.h"

Integer::Integer(int *ptr, string key, int value) {
    this->size = INT_SIZE;
    this->addr = ptr;
    this->key = key;
    this->value = value;

}
