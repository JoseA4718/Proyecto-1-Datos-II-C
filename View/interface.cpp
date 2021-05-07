#include "interface.h"
#include "../../ui_interface.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <stdio.h>
#include <sys/socket.h>
#include <fstream>
#include "Model/src/Socket/Client.h"
#include "Model/src/ClientManager.h"
using namespace std;
string line;

/**
 * @brief Starts the GUI, generated by QTCreator
 * @param parent QWidget reference
 */
interface::interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interface)
{
    ui->setupUi(this);
    //Instances the compiler
    compiler = new Compiler();
    //Generates the line numbers for the coding space
    fillLines();
}
/**
 * @brief destructor for the interface
 */
interface::~interface()
{
    delete ui;
}
/**
 * @brief creates a response object by processing it on the client manager, this will be the server response to be printed in the application log and RAM live view.
 * @param line string of the line read.
 */
void interface::checkLine(string line){
    //Calls the client manager to process the line received and creates a response from the message that comes from the server
    Response* response = ClientManager::getInstance()->process(line);
    //prints in the application log , the log section of the message from the response
    alprint(response->getLog());
    //switch-case for the different status codes the response may have.
    switch (response->getStatusCode()) {
        case CREATED:{
            //creates a new instance of generic type.
            GenericType* obj = new GenericType();
            //gives the generic type a json value from the response.
            obj = Json::readJson(response->getMessage());
            string addr = Json::getAddr(response->getMessage());
            obj->setAddr(addr.c_str());
            //prints the values of the object in the Ram Live View
            RamViewPrint(obj);
            break;}
        case OK:{
            cout << "Response OK: " << response->getLog() << endl;
            break;
        }

    }
}
/**
 * @brief clears the application log.
 */
void interface::on_ClearButton_clicked()
{
    cprint("Application Log Cleared...");
    ui->LogTextBrowser->clear();
}
/**
 * @brief Halts the running of the code and clears the coding area.
 */
void interface::on_Halt_Button_clicked()
{
    cout << "Operation Halted" << endl;
    Response *response = ClientManager::getInstance()->halt_server();
    response->show();
    if(response->getStatusCode() == OK){
        alprint(response->getLog());
        this->clear_RamViewPrint();
    }
    counter = 1;
    ui->CodingSpace->clear();
}
/**
 * @brief Gets all the text from the coding space and saves it on a .txt file. After that reads the first line from the file and starts to process it.
 */
void interface::on_RunButton_clicked()
{
    cout << "Code Running..." << endl;
    CodeFile = ui->CodingSpace->toPlainText();
    ofstream MyFile("code.txt");
    MyFile << CodeFile.toStdString();
    MyFile.close();
    ifstream MyReadFile("code.txt");
    getline(MyReadFile, line);
    checkLine(line);
    MyReadFile.close();
    counter += 1;
}
/**
 * @brief Gets the next line in the file, reads it and process it.
 */
void interface::on_NextButton_clicked()
{
    cout << "Next Line" << endl;
    ifstream MyReadFile("code.txt");
    for (int i = 1; i <= counter ; ++i) {
        getline(MyReadFile, line);
    }
    checkLine(line);
    counter += 1;
}
/**
 * @brief prints the string parameter in the application log
 * @param string1 string to be printed in the application log
 */
void interface::alprint(string string1){
    ui->LogTextBrowser->append(QString::fromStdString(string1));
}
/**
 * @brief prints the string parameter in the C! IDE console
 * @param string1 string to be printed in the console
 */
void interface::cprint(string string1){

    ui->ConsoleTextBrowser->append(QString::fromStdString(string1));
}
/**
 * @brief receives a generic type, gets the address, name, value and number of references to print in the RAM Live View
 * @param type receives a Generic Type
 */
void interface::RamViewPrint(GenericType *type){

    const char* address = type->getAddr();
    std::string address1 = address;
    string name1 = type->getKey();
    const char* value= type->getValue();
    std::string value1 = value;
    int references = type->getCounter();
    stringstream ss;
    ss << references;
    string references1 = ss.str();
    if(!value1.empty()){
        ui->ValueBrowser->append(QString::fromStdString(value1));}
    else{
         ui->ValueBrowser->append(QString::fromStdString("Undefined"));
    }
    ui->NameBrowser->append(QString::fromStdString(name1));
    ui->AddressBrowser->append(QString::fromStdString(address1));
    ui->ReferenceBrowser->append(QString::fromStdString(references1));
}
void interface::clear_RamViewPrint(){

    ui->NameBrowser->clear();
    ui->AddressBrowser->clear();
    ui->ReferenceBrowser->clear();
    ui->ValueBrowser->clear();
}
/**
 * @brief prints the number lines in the coding area
 */
void interface::fillLines()
{
    for (int i = 0; i < 18; i++) {
        ui->LineBrowser->append(QString::fromStdString(to_string(i)));
    }
}
