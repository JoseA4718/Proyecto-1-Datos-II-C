#include "interface.h"
#include "Model/src/Socket/Client.h"
#include <QApplication>
#include <thread>
#include "pthread.h"

using namespace std;


void RunClient(){

    cout << "Client Running" << endl;
    Client c = Client::getInstance();
     c.Start();
}

int RunInterface(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interface w;
    w.show();
    return a.exec();
}

int main (int argc, char *argv[]){
    thread Client (RunClient);
    thread Interface (RunInterface, argc, argv);

    Client.join();
    Interface.join();
}
