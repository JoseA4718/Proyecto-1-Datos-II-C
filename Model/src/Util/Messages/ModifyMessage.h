//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_MODIFYMESSAGE_H
#define MODEL_MODIFYMESSAGE_H


class ModifyMessage : public GenericMessage {
private:

    string newValue;
    string address;
public:
    const string &getNewValue() const {
        return newValue;
    }

    void setNewValue(const string &newValue) {
        ModifyMessage::newValue = newValue;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        ModifyMessage::address = address;
    }

};


#endif //MODEL_MODIFYMESSAGE_H
