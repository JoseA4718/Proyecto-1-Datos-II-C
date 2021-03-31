//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_LONG_H
#define MODEL_LONG_H


#include "../GenericType.h"

class Long : public GenericType<long> {
public:
    Long(long *ptr, string key);

};


#endif //MODEL_LONG_H
