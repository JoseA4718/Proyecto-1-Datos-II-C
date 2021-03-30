//
// Created by eduardo218 on 3/28/21.
//

#include "Struct.h"

Struct::Struct(void *ptr, string key) {
    //TODO: SET AN ALGORITHM FOR ADDING THE SIZE, ADDING THE SIZES OF THE MEMBERS.
    this->size = 0;
    this->addr = ptr;
    this->key = key;
}
