//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_REFERENCE_H
#define MODEL_REFERENCE_H


#include "../Constants.h"
#include "../GenericType.h"

using namespace std;

class Reference {
private:
    /**Address where the object its allocated.*/
    void *addr;
    /**Address pointed*/
    void *pointer;
    /** Identifier for the reference type. */
    string key;

public:

    Reference(void *addr, void *data, string key) {
        this->key = key;
        this->addr = addr;
        this->pointer = data;
    }

    void *getAddr() const {
        return addr;
    }

    void *getPointer() const {
        return pointer;
    }

    void show() {
        cout << "Reference name: " << this->key << "\n"
             << "Address where its stored: " << this->addr << "\n"
             << "Address pointed: " << this->pointer << "\n";

    }
};


#endif //MODEL_REFERENCE_H
