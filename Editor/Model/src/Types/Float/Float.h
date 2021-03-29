//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_FLOAT_H
#define MODEL_FLOAT_H


#include "../Type.h"

class Float : public Type<float> {
public:
    Float(float *ptr, string key);

};


#endif //MODEL_FLOAT_H
