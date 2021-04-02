//
// Created by eduardo218 on 4/1/21.
//

#ifndef MODEL_GENERICMESSAGE_H
#define MODEL_GENERICMESSAGE_H

class GenericMessage {

public:

    const string &getServerLog() const {
        return serverLog;
    }

    void setServerLog(const string &string) {
        GenericMessage::serverLog = string;
    }

private:
    //MESSAGE THAT THE SERVER SENDS BACK TO PRINT IN THE CLIENT EDITOR.
    string serverLog;
};


#endif //MODEL_GENERICMESSAGE_H
