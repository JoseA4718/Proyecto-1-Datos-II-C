//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_FLOAT_H
#define MODEL_FLOAT_H


#include "../GenericType.h"

class Float : public GenericType<float> {
public:
    Float(float *ptr, string key);

};


#endif //MODEL_FLOAT_H
