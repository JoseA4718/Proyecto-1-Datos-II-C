//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_TYPE_H

#define MODEL_TYPE_H

#include <iostream>
#include "string"
#include "Reference/Reference.h"

using namespace std;

template<class T>
class Type {
protected:
/**Size in bytes of the variable*/
    int size;

/**Address of where the variable its stored in the server, we get it from the server itself as a response
 * of the method "create"*/
    void *addr;
    /** Name of the variable, used for identifying the variable among the others, its an unique value
     * and it cannot be any of the reserved words of C!.
     */
    string key;
    T value;
public:
    void show() {
        cout << "Name: " << this->key << " Value: " << this->value << "\n";
    }
};

#endif //MODEL_TYPE_H
