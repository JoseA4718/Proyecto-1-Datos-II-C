//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_CREATEMESSAGE_H
#define MODEL_CREATEMESSAGE_H


class CreateMessage : public GenericMessage {
private:
    /**Json with the content of the new element, must have at least, a name and value keys. */
    string json;
    /** Type of the object to create, GO TO Compiler.h for further information. */
    string type;
public:
    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        CreateMessage::type = type;
    }

public:
    const string &getJson() const {
        return json;
    }

    void setJson(const string &json) {
        CreateMessage::json = json;
    }
};


#endif //MODEL_CREATEMESSAGE_H
