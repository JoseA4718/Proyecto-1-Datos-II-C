#include "interface.h"
#include "./ui_interface.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <stdio.h>
#include <sys/socket.h>


using namespace std;

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
    cout << "Cleared" << endl;
}

void interface::on_Halt_Button_clicked()
{
    cout << "Operation Halted" << endl;
}

void interface::on_NextButton_clicked()
{
    cout << "Next Line" << endl;
}

void interface::on_RunButton_clicked()
{
    cout << "Code Running..." << endl;
}
