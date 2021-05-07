//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_REFERENCE_H
#define MODEL_REFERENCE_H


#include "../../Constants.h"
#include "../GenericType.h"

using namespace std;
/**
 * This is the reference class
 */
class Reference {
private:
    /**Address where the object its allocated.*/
    const char *addr;
    /**Address pointed*/
    const char *pointer;
    /** Identifier for the reference type. */
    string key;

public:

    Reference() {
        ;
    }

    void setAddr(const char *addr) {
        Reference::addr = addr;
    }

    void setPointer(const char *pointer) {
        Reference::pointer = pointer;
    }

    void setKey(const string &key) {
        Reference::key = key;
    }

    const char *getAddr() const {
        return addr;
    }

    const char *const getPointer() const {
        return pointer;
    }

    void show() {
        cout << "Reference name: " << this->key << "\n"
             << "Address where its stored: " << this->addr << "\n"
             << "Address pointed: " << this->pointer << "\n";

    }

    string getKey() {
        return this->key;
    }
};


#endif //MODEL_REFERENCE_H
