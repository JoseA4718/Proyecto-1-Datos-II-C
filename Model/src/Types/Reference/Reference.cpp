//
// Created by eduardo218 on 3/28/21.
//

#include "Reference.h"
#include "../GenericType.h"

template<class T>
Reference<T>::Reference(void *addr, T *pointer) : addr(addr), pointer(pointer) {
    this->addr = addr;
    this->pointer = pointer;

}




