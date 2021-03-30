//
// Created by eduardo218 on 3/28/21.
//

#include "Double.h"

Double::Double(double *ptr, string key) {
    this->size = DOUBLE_SIZE;
    this->addr = ptr;
    this->key = key;

}
