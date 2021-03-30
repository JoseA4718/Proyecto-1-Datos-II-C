//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_CHAR_H
#define MODEL_CHAR_H


#include "../Type.h"

class Char : public Type<char> {
public:
    Char(char *ptr, string key);

};


#endif //MODEL_CHAR_H
