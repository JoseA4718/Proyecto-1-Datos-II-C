//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_DOUBLE_H
#define MODEL_DOUBLE_H


#include "../GenericType.h"

class Double : public GenericType<double> {
public:
    Double(double *ptr, string key);
};


#endif //MODEL_DOUBLE_H
