//
// Created by eduardo218 on 3/28/21.
//

#include "Long.h"

Long::Long(long *ptr) {
    this->addr = ptr;
    this->size = LONG_SIZE;
}
