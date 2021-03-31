//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_INTEGER_H
#define MODEL_INTEGER_H


#include "../GenericType.h"

class Integer : public GenericType<int> {
public:
    Integer(int *ptr, string key, int value);

};


#endif //MODEL_INTEGER_H
