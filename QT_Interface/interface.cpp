#include "interface.h"
#include "./ui_interface.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <stdio.h>
#include <sys/socket.h>
#include <fstream>


using namespace std;

string line;

interface::interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interface)
{
    ui->setupUi(this);
}

interface::~interface()
{
    delete ui;
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
    cprint(line);
    MyReadFile.close();
    counter += 1;
}
void checkSyntax(string Line){
    cout << "me cago en angosto" << endl;
}
void interface::cprint(string string1){
    ui->ConsoleTextBrowser->append(QString::fromStdString(string1));
}


