//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_GENERICTYPE_H

#define MODEL_GENERICTYPE_H

#include <iostream>
#include "string"
#include "Reference/Reference.h"

using namespace std;

template<class T>
class GenericType {
protected:
/**Size in bytes of the variable*/
    int size;

/**Address of where the variable its stored in the server, we get it from the server itself as a response
 * of the method "create"*/
    void *addr;
public:
    int getSize() const {
        return size;
    }

    void *getAddr() const {
        return addr;
    }

    const string &getKey() const {
        return key;
    }

    T getValue() const {
        return value;
    }


    int getCounter() const {
        return counter;
    }

protected:

    /** Name of the variable, used for identifying the variable among the others, its an unique value
     * and it cannot be any of the reserved words of C!.
     */
    string key;
    T value;
    int counter;

public:

    void show() {
        cout << "Name: " << this->key << "\nValue: " << this->value << "\nAddress: " << this->addr << "\n";
    }
};

#endif //MODEL_GENERICTYPE_H
