//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_STRUCT_H
#define MODEL_STRUCT_H


#include "../Type.h"

class Struct {
public:

    Struct(void *ptr, string key);

private:
    //TODO: List<Type> members;
    string key;
    void *addr;
    int size;



};


#endif //MODEL_STRUCT_H
