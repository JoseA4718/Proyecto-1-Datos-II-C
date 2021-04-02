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
    const char *addr;

    /** Name of the variable, used for identifying the variable among the others, its an unique value
     * and it cannot be any of the reserved words of C!.
     */
    string key;

    /** Value stored in the variable*/
    const char *value;

    /**Reference counter on the variable*/
    int referenceCount;

public:
    int getSize() const {
        return size;
    }

    void setSize(int size) {
        GenericType::size = size;
    }

    void setAddr(const char *addr) {
        GenericType::addr = addr;
    }

    void setKey(const string &key) {
        GenericType::key = key;
    }

    void setValue(const char *value) {
        this->value = value;
    }

    void setReferenceCount(int referenceCount) {
        GenericType::referenceCount = referenceCount;
    }

    const void *getAddr() const {
        return addr;
    }

    const string &getKey() const {
        return key;
    }

    T getValue() const {
        return value;
    }


    int getCounter() const {
        return referenceCount;
    }

public:

    void show() {
        cout << "{ Name: " << this->key << " Value: " << this->value << " Address: " << this->addr << "}\n";
    }
};

#endif //MODEL_GENERICTYPE_H
