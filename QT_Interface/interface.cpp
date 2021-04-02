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
}

interface::~interface()
{
    delete ui;
}

void interface::checkLine(string Line){
    if(!Line.find("Integer") or !Line.find("Long") or !Line.find("Char") or !Line.find("Double") or !Line.find("Float") or !Line.find("Reference") or !Line.find("Struct")){
        if(!Line.find("Integer")){
            type = "Integer";
            size_t typeFound = Line.find("Integer");
            pos = typeFound + 8;
            while(next != ";"){
                previous = line[pos];
                newStr.append(previous);
                next = line[pos + 1];
                spaceCheck = next[0];
                if (isspace(spaceCheck)){
                    name = newStr;
                    cout << "Name: " + name << endl;
                    newStr = "";
                    size_t equalsFound = line.find("=");
                    if (equalsFound != string::npos){
                        pos = equalsFound + 2;
                        while (next != ";"){
                            previous = line[pos];
                            newStr.append(previous);
                            next = line[pos + 1];
                            pos += 1;
                        }
                        value = newStr;
                        cout << "Value: " + value << endl;
                        break;
                    }

                }
                pos += 1;
            }

        }
    }
    else{
        cout << "operacion" << endl;
    }
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
    cprint(line);
    MyReadFile.close();
    counter += 1;
}

void interface::cprint(string string1){
    ui->ConsoleTextBrowser->append(QString::fromStdString(string1));
}


