//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_MESSAGE_H
#define MODEL_MESSAGE_H


#include <ostream>
#include "../Json.h"
#include "Message.h"

class Message {
private:

    /**
     *  POSSIBLE VALUES:\n
     *  "CREATE" - FOR CREATING AN INSTANCE\n
     *  "MODIFY" - FOR MODIFYING AN EXISTING INSTANCE\n
     *  "SEARCH" - FOR SEARCHING AN INSTANCE*/
    string action;
    //|-----------------------------------------------------| //
    //|    * EN CASO DE INSTANCIAR UNA VARIABLE NUEVA  *    | //
    //|-----------------------------------------------------| //
    /**Json with the content of the new element, must have at least, a name and value keys.
     * USE ONLY FOR CREATING A NEW INSTANCE OF AN VARIABLE*/
    string contentJson;

    /** Type of the object to create, GO TO Compiler.h for further information.*/
    string type;

    //|-----------------------------------------------------| //
    //|    * EN CASO DE OPERAR DOS VARIABLES  *             | //
    //|-----------------------------------------------------| //
    /**New value of the variable to modify, ALSO CAN BE THE IDENTIFIER FOR SEARCHING */
    string firstVariable;

    /**Name of the variable to take information from */
    string secondVariable;
public:
    const string getAction() const {
        return action;
    }

    void setAction(const string &action) {
        Message::action = action;
    }

    void show() {
        cout << "---- Message generated ----\n" <<
             "action: " << action <<
             "\ncontentJson: " << contentJson <<
             "\ntype: " << type <<
             "\nfirstVariable: " << firstVariable <<
             "\nsecondVariable: " << secondVariable
             << "\noperation: " << operation <<
             "\n______________________________\n";
    }

    const string getContentJson() const {
        return contentJson;
    }

    void setContentJson(const string &contentJson) {
        Message::contentJson = contentJson;
    }

    const string getType() const {
        return type;
    }

    void setType(const string type) {
        Message::type = type;
    }

    const string getFirstVariable() const {
        return firstVariable;
    }

    void setFirstVariable(const string firstVariable) {
        Message::firstVariable = firstVariable;
    }

    const string getSecondVariable() const {
        return secondVariable;
    }

    void setSecondVariable(const string secondVariable) {
        Message::secondVariable = secondVariable;
    }

    const string getOperation() const {
        return operation;
    }

    void setOperation(const string operation) {
        Message::operation = operation;
    }

private:
    /**Operation to make between the variables */
    string operation;


public:
    /**
     * Method for creating the json formatted object of an Primitive data type.
     * @param name key name of the variable.
     * @param value value in string of the variable.
     */
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
};


#endif //MODEL_MESSAGE_H
