//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_REFERENCE_H
#define MODEL_REFERENCE_H


#include "../Constants.h"

template<typename T>
class Reference {
private:
    /**Address where the object its allocated.*/
    void *addr;
    /**Address pointed*/
    T *pointer;
    /**Size in bytes*/
    int size = REFERENCE_SIZE;

public:
    Reference(void *addr, T *pointer);


};


#endif //MODEL_REFERENCE_H
