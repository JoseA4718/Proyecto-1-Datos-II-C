//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_GENERICTYPE_H

#define MODEL_GENERICTYPE_H

#include <iostream>
#include "string"
#include "Reference/Reference.h"

using namespace std;


class GenericType {
protected:
    /**Size in bytes of the variable*/
    int size;
    int offset;
    string type;
public:
    /**Address of where the variable its stored in the server, we get it from the server itself as a response
     * of the method "create"*/
    const char *addr;
    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        GenericType::type = type;
    }

public:
    int getOffset() const {
        return offset;
    }

    void setOffset(int offset) {
        GenericType::offset = offset;
    }

    int getReferenceCount() const {
        return referenceCount;
    }

protected:



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

    const char *getAddr() const {
        return this->addr;
    }

    const string &getKey() const {
        return key;
    }

    const char *getValue() const {
        return value;
    }


    int getCounter() const {
        return referenceCount;
    }

public:
    /**
     * @brief prints the generic type object in the console
     */
    void show() {
        cout << "{ Name: " << this->key << " Value: " << this->value << " Address: " << this->addr << "}\n";
    }
};

#endif //MODEL_GENERICTYPE_H
