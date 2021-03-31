//
// Created by eduardo218 on 3/30/21.
//
#ifndef MODEL_JSON_H
#define MODEL_JSON_H

#include "/home/eduardo218/Desktop/Proyecto-1-Datos-II-C/Model/librerias/rapidjson/stringbuffer.h"
#include "/home/eduardo218/Desktop/Proyecto-1-Datos-II-C/Model/librerias/rapidjson/writer.h"
#include <sstream>
#include "../Types/GenericType.h"
#include "../Types/Int/Integer.h"
#include "iostream"

using namespace rapidjson;
using namespace std;

class Json {
    //TODO: hacer singleton
public:
    template<class T>
    string generateJson(GenericType<T> *obj) {
        //GET THE VALUES FROM THE OBJECT
        const char *name = obj->getKey().c_str();
        int referenceCounter = obj->getCounter();

        //CAST THE VALUE TO CONST CHAR*
        std::ostringstream valueRaw;
        valueRaw << (T) obj->getValue();
        string var = valueRaw.str();
        const char *B = var.c_str();
        const char *value = B;

        //CAST THE ADDR TO CONST CHAR*
        std::ostringstream address;
        address << (void const *) obj->getAddr();
        string addr = address.str();
        const char *c = addr.c_str();
        const char *addr_String = c;

        //CREATE WRITER
        StringBuffer s;
        Writer<StringBuffer> writer(s);
        writer.StartObject();

        //FILL THE SPACES IN THE JSON FILE
        writer.Key("name"); //string name of the variable
        writer.String(name);

        writer.Key("count");//reference count
        writer.Int(referenceCounter);

        writer.Key("addr");//memory address
        writer.String(addr_String);

        writer.Key("value");//value of the variable
        writer.Key(value);


        writer.EndObject();

        return s.GetString();

    }

    template<class T>
    string generateJson(Reference<GenericType<T>> obj) {

    }

    template<class T>
    GenericType<T> readJson(string json) {
        //TODO: code for generating an instance of GenericType.cpp given json
    }

    template<class T>
    Reference<GenericType<T>> readJsonReference(string json) {
        //TODO: code for generating an instance of GenericType.cpp given json
    }

};

#endif //MODEL_JSON_H
