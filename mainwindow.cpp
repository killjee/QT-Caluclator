#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->one_button,SIGNAL(clicked()),this,SLOT(one()));
    connect(ui->two_button,SIGNAL(clicked()),this,SLOT(two()));
    connect(ui->three_button,SIGNAL(clicked()),this,SLOT(three()));
    connect(ui->four_button,SIGNAL(clicked()),this,SLOT(four()));
    connect(ui->five_button,SIGNAL(clicked()),this,SLOT(five()));
    connect(ui->six_button,SIGNAL(clicked()),this,SLOT(six()));
    connect(ui->seven_button,SIGNAL(clicked()),this,SLOT(seven()));
    connect(ui->eight_button,SIGNAL(clicked()),this,SLOT(eight()));
    connect(ui->nine_button,SIGNAL(clicked()),this,SLOT(nine()));
    connect(ui->zero_button,SIGNAL(clicked()),this,SLOT(zero()));
    connect(ui->add_button,SIGNAL(clicked()),this,SLOT(add()));
    connect(ui->subtract_button,SIGNAL(clicked()),this,SLOT(subtract()));
    connect(ui->multiply_button,SIGNAL(clicked()),this,SLOT(multiply()));
    connect(ui->divide_button,SIGNAL(clicked()),this,SLOT(divide()));
    connect(ui->equal_button,SIGNAL(clicked()),this,SLOT(equal()));
    connect(ui->clear_button,SIGNAL(clicked()),this,SLOT(clear()));

}

int MainWindow::stringToNum(QString s) {
    string p=s.toStdString();
    int num=0,sz=p.size();

    for (int i=0 ; i<sz ; i++) {
        num=num*10+(p[i]-'0');
    }
    return num;
}

//ghgnvb

double MainWindow::equalto(double fNum , int sNum) {
    if(addchk)   return fNum+sNum;
    if(subtractchk) return fNum-sNum;
    if(multiplychk) return fNum*sNum;
    if(dividechk) {
        if(sNum==0)
            return -1.0;
        return fNum/sNum;
    }
    return sNum;
}

bool MainWindow::printValue(double toprint) {
    if(toprint>=0) {
        value=QString::number(toprint);
        ui->label->setText(value);
        return 0;
    }
    else {
        toprint=0;
        ui->label->setText("Math Error");
        value="";
        num=toprint;
        addchk=0,subtractchk=0,multiplychk=0,dividechk=0;
        return 1;
    }
}

void MainWindow::one() {
    value=value+'1';
    ui->label->setText(value);
}

void MainWindow::two() {
    value=value+'2';
    ui->label->setText(value);
}

void MainWindow::three() {
    value=value+'3';
    ui->label->setText(value);
}

void MainWindow::four() {
    value=value+'4';
    ui->label->setText(value);
}

void MainWindow::five() {
    value=value+'5';
    ui->label->setText(value);
}

void MainWindow::six() {
    value=value+'6';
    ui->label->setText(value);
}

void MainWindow::seven() {
    value=value+'7';
    ui->label->setText(value);
}

void MainWindow::eight() {
    value=value+'8';
    ui->label->setText(value);
}

void MainWindow::nine() {
    value=value+'9';
    ui->label->setText(value);
}

void MainWindow::zero() {
    value=value+'0';
    ui->label->setText(value);
}

void MainWindow::add() {
    int newnum=stringToNum(value);
    double toprint=equalto(num,newnum);
    if(value=="")
        toprint=num;
    bool chk=printValue(toprint);
    if(chk)
        return;
    value="";
    num=toprint;
    addchk=1,subtractchk=0,multiplychk=0,dividechk=0;
}

void MainWindow::subtract() {
    int newnum=stringToNum(value);
    double toprint=equalto(num,newnum);
    if(value=="")
        toprint=num;
    bool chk=printValue(toprint);
    if(chk)
        return;
    value="";
    num=toprint;
    addchk=0,subtractchk=1,multiplychk=0,dividechk=0;
}

void MainWindow::multiply() {
    int newnum=stringToNum(value);
    double toprint=equalto(num,newnum);
    if(value=="")
        toprint=num;
    bool chk=printValue(toprint);
    if(chk)
        return;
    value="";
    num=toprint;
    addchk=0,subtractchk=0,multiplychk=1,dividechk=0;
}

void MainWindow::divide() {
    int newnum=stringToNum(value);
    double toprint=equalto(num,newnum);
    if(value=="")
        toprint=num;
    bool chk=printValue(toprint);
    if(chk)
        return;
    value="";
    num=toprint;
    addchk=0,subtractchk=0,multiplychk=0,dividechk=1;
}

void MainWindow::equal() {
    int newnum=stringToNum(value);
    double toprint=equalto(num,newnum);
    if(value=="")
        toprint=num;
    bool chk=printValue(toprint);
    if(chk)
        return;
    value="";
    num=toprint;
    addchk=0,subtractchk=0,multiplychk=0,dividechk=0;
}

void MainWindow::clear() {
    value="";
    num=0;
    addchk=0,subtractchk=0,multiplychk=0,dividechk=0;
    ui->label->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}
