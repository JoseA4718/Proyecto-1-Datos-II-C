//
// Created by eduardo218 on 3/30/21.
//
#ifndef MODEL_JSON_H
#define MODEL_JSON_H

#include "../Types/Type.h"
#include "../Types/Int/Integer.h"

class Json {
    //TODO: hacer singleton
public:
    template<class T>
    string generateJson(Type<T> *obj) {
        //TODO: code for generating json file given an object of GenericType.cpp
    }

    template<class T>
    string generateJson(Reference<Type<T>> obj) {
        //TODO: code for generating json file given an object of Reference.cpp
    }

    template<class T>
    Type<T> readJson(Type<T> obj) {
        //TODO: code for generating an isntance of Type.cpp given json
    }

    template<class T>
    Type<T> readJson(Reference<Type<T>> obj) {
        //TODO: code for generating an isntance of Type.cpp given json
    }
};


#endif //MODEL_JSON_H
