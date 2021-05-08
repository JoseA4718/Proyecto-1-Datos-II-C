#ifndef INTERFACE_H
#define INTERFACE_H
#include "string"
#include <QMainWindow>
#include "Model/src/Compiler/Compiler.h"
#include "Model/src/Types/GenericType.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class interface; }
QT_END_NAMESPACE

class interface : public QMainWindow
{
    Q_OBJECT

public:
    interface(QWidget *parent = nullptr);
    ~interface();
    int counter = 1;

private slots:

    void on_ClearButton_clicked();

    void on_Halt_Button_clicked();

    void on_NextButton_clicked();

    void on_RunButton_clicked();

    void cprint(std::string);

    void alprint(std::string);

    void checkLine(std::string);

    void RamViewPrint(GenericType *type);
    void clear_RamViewPrint();

    void fillLines();

    void on_pushButton_clicked();

    void on_CollectorButton_clicked();

private:
    Ui::interface *ui;
    QString CodeFile;
    string type, name, newStr, next, previous, value;
    int pos, spaceCheck;
    Compiler *compiler;


};
#endif // INTERFACE_H
