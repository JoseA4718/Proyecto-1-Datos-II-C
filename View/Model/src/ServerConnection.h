//
// Created by eduardo218 on 4/25/21.
//

#ifndef MODEL_SERVERCONNECTION_H
#define MODEL_SERVERCONNECTION_H


class ServerConnection {
    /**
     * Recieves a Message.h in Json format, send it to the server and waits for its response.
     * @param message Json format of Message.
     * @return Response from the server.
     */
public:
    static Response *sendMessage(string message) {

        Client::getInstance()->Send(message.c_str());
        string response;
        while (response.empty()) {
            response = Client::getInstance()->getMessage();
        }
        Client::getInstance()->setMessage("");

        Response *result = Json::readJsonResponse(response);
        return result;
    }
};


#endif //MODEL_SERVERCONNECTION_H
