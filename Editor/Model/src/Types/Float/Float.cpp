//
// Created by eduardo218 on 3/28/21.
//

#include "Float.h"

Float::Float(float *ptr, string key) {
    this->addr = ptr;
    this->size = FLOAT_SIZE;
    this->key = key;

}
