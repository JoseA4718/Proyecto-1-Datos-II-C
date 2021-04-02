//
// Created by eduardo218 on 3/30/21.
//
#ifndef MODEL_JSON_H
#define MODEL_JSON_H

static const char *const KEY_VALUE = "key";

static const char *const COUNTER_VALUE = "referenceCount";

static const char *const ADDRESS_VALUE = "addr";

static const char *const VALUE_KEY = "value";

static const char *const POINTER_VALUE = "pointer";

#include "/home/eduardo218/Desktop/Proyecto-1-Datos-II-C/Model/librerias/rapidjson/stringbuffer.h"
#include "/home/eduardo218/Desktop/Proyecto-1-Datos-II-C/Model/librerias/rapidjson/writer.h"
#include <sstream>
#include "../Types/GenericType.h"
#include "../Types/Int/Integer.h"
#include "iostream"
#include "../../librerias/rapidjson/document.h"

using namespace rapidjson;
using namespace std;

class Json {
    //TODO: hacer singleton
public:

    template<class T>
    static string generateJson(GenericType<T> *obj) {
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
        writer.Key(KEY_VALUE); //string name of the variable
        writer.String(name);

        writer.Key(COUNTER_VALUE);//reference referenceCount
        writer.Int(referenceCounter);

        writer.Key(ADDRESS_VALUE);//memory address
        writer.String(addr_String);

        writer.Key(VALUE_KEY);//value of the variable
        writer.Key(value);


        writer.EndObject();

        return s.GetString();

    }


    static string generateJson(Reference *obj) {
        const char *pointer = obj->getPointer();
        const char *address = obj->getAddr();
        string key = obj->getKey();



        //CREATE WRITER
        StringBuffer s;
        Writer<StringBuffer> writer(s);
        writer.StartObject();

        //IF THE REFERENCE HAS A POINTER TO A VALUE
        if (obj->getPointer() != nullptr) {
            //CAST THE POINTER TO CONST CHAR*
            std::ostringstream ptrString;
            ptrString << (void const *) pointer;
            string ptr = ptrString.str();
            const char *b = ptr.c_str();
            const char *ptr_String = b;

            writer.Key(POINTER_VALUE);
            writer.String(ptr_String);
        }
        //IF THE ADDRESS ITS ASSIGNED YET
        if (obj->getAddr() != nullptr) {
            //CAST THE ADDR TO CONST CHAR*
            std::ostringstream addrString;
            addrString << (void const *) address;
            string addr = addrString.str();
            const char *c = addr.c_str();
            const char *addr_String = c;
            writer.Key(ADDRESS_VALUE);
            writer.String(addr_String);

        }
        //FILL THE SPACES IN THE JSON FILE
        writer.Key(KEY_VALUE); //string name of the variable
        writer.String(key.c_str());


        writer.EndObject();

        return s.GetString();

    }

    template<class T>
    static void readJson(const string &json, GenericType<T> *obj) {

        rapidjson::Document doc;
        doc.Parse<kParseDefaultFlags>(json.c_str());

        if (doc.HasMember(KEY_VALUE)) {
            const char *keyName = doc[KEY_VALUE].GetString();
            obj->setKey(keyName);
        }
        if (doc.HasMember(VALUE_KEY)) {
            const char *value = doc[VALUE_KEY].GetString();
            obj->setValue(value);
        }
        if (doc.HasMember(ADDRESS_VALUE)) {
            const char *addr = (doc[ADDRESS_VALUE].GetString());
            obj->setAddr(addr);
        }
        if (doc.HasMember(COUNTER_VALUE)) {
            int counter = doc[COUNTER_VALUE].GetInt();
            obj->setReferenceCount(counter);
        }
    }


    static Reference readJson(const string &json, Reference *obj) {
        rapidjson::Document doc;
        doc.Parse<kParseDefaultFlags>(json.c_str());

        if (doc.HasMember(KEY_VALUE)) {
            const char *keyName = doc[KEY_VALUE].GetString();
            obj->setKey(keyName);

        }
        if (doc.HasMember(ADDRESS_VALUE)) {
            const char *addr = (doc[ADDRESS_VALUE].GetString());
            obj->setAddr(addr);
        }
        if (doc.HasMember(POINTER_VALUE)) {
            const char *pointer = doc[POINTER_VALUE].GetString();
            obj->setPointer(pointer);
        }
    }

};

#endif //MODEL_JSON_H
