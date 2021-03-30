//
// Created by eduardo218 on 3/28/21.
//

#include "Char.h"

Char::Char(char *ptr, string key) {
    this->size = CHAR_SIZE;
    this->addr = ptr;
    this->key = key;
}
