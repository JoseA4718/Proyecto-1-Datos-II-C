//
// Created by eduardo218 on 3/28/21.
//

#ifndef MODEL_TYPE_H

#define MODEL_TYPE_H

#include "string"
#include "Reference/Reference.h"

using namespace std;

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
public:

    /**
     * This method is used for getting a reference to this object.
     * @return Reference<Type> of this element.
     */
    Reference<Type> getAddr() {
        //TODO: ADD THE METHOD HERE TO GET THE REQUESTED VALUE.
        return Reference<Type>(nullptr, nullptr);
    }
};

#endif //MODEL_TYPE_H
