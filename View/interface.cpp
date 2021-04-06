#include "interface.h"
#include "../../ui_interface.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <stdio.h>
#include <sys/socket.h>
#include <fstream>
#include "Model/src/Types/Char/Char.h"
#include "Model/src/Types/Double/Double.h"
#include "Model/src/Types/Float/Float.h"
#include "Model/src/Types/Int/Integer.h"
#include "Model/src/Types/Long/Long.h"
#include "Model/src/Types/Reference/Reference.h"
#include "Model/src/Types/GenericType.h"
#include "Model/src/Compiler/Compiler.h"

using namespace std;

string line;

interface::interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interface)
{
    ui->setupUi(this);
    compiler = new Compiler();
}

interface::~interface()
{
    delete ui;
}

void interface::checkLine(string Line){
    cprint(this->compiler->compile(line));
    cout << this->compiler->compile(line) << endl;
}

void interface::on_ClearButton_clicked()
{
    cprint("Application Log Cleared...");
    ui->LogTextBrowser->clear();
}

void interface::on_Halt_Button_clicked()
{
    cout << "Operation Halted" << endl;
    counter = 1;
    ui->CodingSpace->clear();
}

void interface::on_NextButton_clicked()
{
    cout << "Next Line" << endl;
    ifstream MyReadFile("code.txt");
    for (int i = 1; i <= counter ; ++i) {
        getline(MyReadFile, line);
    }
    checkLine(line);
    cprint(line);
    counter += 1;
}

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

void interface::cprint(string string1){

    ui->ConsoleTextBrowser->append(QString::fromStdString(string1));
}

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

    ui->NameBrowser->append(QString::fromStdString(name1));
    ui->ValueBrowser->append(QString::fromStdString(value1));
    ui->AddressBrowser->append(QString::fromStdString(address1));
    ui->ReferenceBrowser->append(QString::fromStdString(references1));

}



