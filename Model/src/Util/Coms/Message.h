//

// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_MESSAGE_H
#define MODEL_MESSAGE_H


#include "../Json.h"
#include "Message.h"

static const auto MODIFY = "MODIFY";
static const auto CREATE = "CREATE";
static const auto SEARCH = "SEARCH";

class Message {
private:

    /**Json with the content of the new element, must have at least, a name and value keys.
     * USE ONLY FOR CREATING A NEW INSTANCE OF AN VARIABLE*/
    string contentJson;

    /** Type of the object to create, GO TO Compiler.h for further information.*/
    string type;
    /**
     *  POSSIBLE VALUES:\n
     *  "CREATE" - FOR CREATING AN INSTANCE\n
     *  "MODIFY" - FOR MODIFYING AN EXISTING INSTANCE\n
     *  "SEARCH" - FOR SEARCHING AN INSTANCE*/
    string action;

    /**New value of the variable to modify
     * USE ONLY FOR MODIFYING A VARIABLE IN THE SERVER*/
    string newValue;

    /** Name of the object to search or modify, expect the contentJson of the obj, or 0 if dont exist
     * USE WHEN TRYING TO MODIFY OF FIND A VARIABLE IN THE SERVER */
    string name;


public:
    void fillJson(string name, string value) {
        //CREATE WRITER
        rapidjson::StringBuffer s;
        rapidjson::Writer<rapidjson::StringBuffer> writer(s);
        writer.StartObject();

        //FILL THE SPACES IN THE JSON FILE
        writer.Key(KEY_VALUE); //string name of the variable
        writer.String(name.c_str());

        writer.Key(VALUE_KEY); //string name of the variable
        writer.String(value.c_str());
        writer.EndObject();

        contentJson = s.GetString();
    }

    string getAction() const {
        return action;
    }

    void setAction(const string &action) {
        Message::action = action;
    }

    const string &getJson() const {
        return contentJson;
    }

    void setJson(const string &json) {
        Message::contentJson = json;
    }

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        Message::type = type;
    }

    const string &getNewValue() const {
        return newValue;
    }

    void setNewValue(const string &newValue) {
        Message::newValue = newValue;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Message::name = name;
    }

};


#endif //MODEL_MESSAGE_H
