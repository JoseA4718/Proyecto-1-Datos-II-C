#include "interface.h"
#include "./ui_interface.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <stdio.h>
#include <sys/socket.h>
#include <fstream>
#include "../Model/src/Types/Char/Char.h"
#include "../Model/src/Types/Double/Double.h"
#include "../Model/src/Types/Float/Float.h"
#include "../Model/src/Types/Int/Integer.h"
#include "../Model/src/Types/Long/Long.h"
#include "../Model/src/Types/Reference/Reference.h"


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


