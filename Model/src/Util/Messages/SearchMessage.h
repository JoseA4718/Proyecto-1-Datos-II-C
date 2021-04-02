//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_SEARCHMESSAGE_H
#define MODEL_SEARCHMESSAGE_H

class SearchMessage : public GenericMessage {
    /** Name of the object to search, expect the json of the obj, or 0 if dont exist*/
    string name;
public:
    const string &getName() const {

    }

    void setName(const string &name) {
        SearchMessage::name = name;
    }
};

#endif //MODEL_SEARCHMESSAGE_H
