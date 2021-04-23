#include "interface.h"
#include "Model/src/Socket/Client.h"
#include <QApplication>
#include <thread>

using namespace std;

int RunInterface(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interface w;
    w.show();
    return a.exec();
}

void RunClient(){
    Client::getInstance()->initClient();
}

int main (int argc, char *argv[]){
    thread Client (RunClient);
    thread Interface (RunInterface, argc, argv);

    Client.join();
    Interface.join();
}
