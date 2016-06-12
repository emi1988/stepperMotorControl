#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wiringPi.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    wiringPiSetup();

    //enable
    pinMode(7, OUTPUT);
    //disable
    digitalWrite(7, 1);
    //direction
    pinMode(8, OUTPUT);
    //step
    pinMode(9, OUTPUT);
//    int msec = 100;
//    int uSec = msec * 1000;

//    for (int i = 0; i < 50; ++i)
//    {
//        digitalWrite(9, 0);

//        usleep(uSec);
//        digitalWrite(9, 1);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStart_clicked()
{
    //enable
    digitalWrite(7, 0);


    if(ui->spinBoxDir->value()== 1)
    {
        digitalWrite(8, 0);
    }
    else
    {
        digitalWrite(8, 1);
    }

    int steps = ui->lineEditSteps->text().toInt();
    int msec = ui->lineEditMs->text().toInt();
    int uSec = msec * 100;

    for (int i = 0; i < steps; ++i)
    {
        usleep(uSec);

        digitalWrite(9, 0);

        usleep(uSec);

        digitalWrite(9, 1);
    }

    //disable
    digitalWrite(7, 1);
}
