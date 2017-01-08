#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
using namespace std;

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    int stringToNum(QString s);
    double equalto(double fNum , int sNum);
    bool printValue(double toprint);
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();
    void zero();
    void add();
    void subtract();
    void multiply();
    void divide();
    void equal();
    void clear();

private:
    QString value="",total="";
    double num=0;
    bool addchk=0,subtractchk=0,multiplychk=0,dividechk=0;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
