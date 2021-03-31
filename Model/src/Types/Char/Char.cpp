//
// Created by eduardo218 on 3/28/21.
//

#include "Char.h"

Char::Char(char *ptr, string key, char value) {
    this->size = CHAR_SIZE;
    this->addr = ptr;
    this->key = key;
    this->counter = 0;
    this->value = value;
}
