#include <iostream>
#include <string>
#include <chrono>
#include <cmath>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QInputDialog>

#include "md5.h"
#include "sha256.h"
#include "project.cpp"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->md5text->setText("");
    ui->shatext->setText("");

    ui->timeM->setText("");
    ui->timeS->setText("");

    this->setFixedSize(QSize(857, 609));
}

MainWindow::~MainWindow()
{
    delete ui;
}

string doMd5(QString text){
    return md5(text.toStdString());
}

string doSha(QString text){
    return sha256(text.toStdString());
}


void MainWindow::on_pushButton_clicked()
{
    QString N = ui->inputText->toPlainText();


    if(ui->md5box->isChecked()){

        auto start = chrono::steady_clock::now();

        string answer_1 = doMd5(N);

        auto end = chrono::steady_clock::now();

        chrono::duration<float, std::milli> duration = end - start;

        string durationF = to_string(duration.count());

        ui->md5text->setText(QString::fromStdString(answer_1));
        ui->timeM->setText(QString::fromStdString(durationF));
    }
    else{
        ui->md5text->setText("");
    }

    if(ui->shabox->isChecked()){
        auto start = chrono::steady_clock::now();

        string answer_2 = doSha(N);

        auto end = chrono::steady_clock::now();

        chrono::duration<float, std::milli> duration = end - start;

        string durationF = to_string(duration.count());
        ui->shatext->setText(QString::fromStdString(answer_2));
        ui->timeS->setText(QString::fromStdString(durationF));
    }
    else{
        ui->shatext->setText("");
    }

}
