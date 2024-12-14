#pragma once
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    currentIndex(0) {
    ui.setupUi(this);
    timer = new QTimer(this);
    //labels = {ui.plainTextEdit, ui.plainTextEdit_2, ui.plainTextEdit_3, ui.plainTextEdit_4, ui.plainTextEdit_5, ui.plainTextEdit_6,
    //    ui.plainTextEdit_7, ui.plainTextEdit_8, ui.plainTextEdit_9, ui.plainTextEdit_10, ui.plainTextEdit_11, ui.plainTextEdit_12, ui.plainTextEdit_13,
    //    ui.plainTextEdit_14, ui.plainTextEdit_16
    //};
    labels[0] = ui.plainTextEdit;
    labels[1] = ui.plainTextEdit_2;
    labels[2] = ui.plainTextEdit_3;
    labels[3] = ui.plainTextEdit_4;
    labels[4] = ui.plainTextEdit_5;
    labels[5] = ui.plainTextEdit_6;
    labels[6] = ui.plainTextEdit_7;
    labels[7] = ui.plainTextEdit_8;
    labels[8] = ui.plainTextEdit_9;
    labels[9] = ui.plainTextEdit_10;
    labels[10] = ui.plainTextEdit_11;
    labels[11] = ui.plainTextEdit_12;
    labels[12] = ui.plainTextEdit_13;
    labels[13] = ui.plainTextEdit_14;
    labels[14] = ui.plainTextEdit_16;
    connect(ui.action, &QAction::triggered, this, &MainWindow::fillIntegerByInput);
    connect(ui.action
        
        , &QAction::triggered, this, &MainWindow::fillIntegerByJSON);
    connect(ui.actioncsv, &QAction::triggered, this, &MainWindow::fillIntegerByCSV);
    connect(ui.action_2, &QAction::triggered, this, &MainWindow::fillFloatByInput);
    connect(ui.actionjson_2, &QAction::triggered, this, &MainWindow::fillFloatByJSON);
    connect(ui.actioncsv_2, &QAction::triggered, this, &MainWindow::fillFloatByCSV);
    connect(ui.actionjson_3, &QAction::triggered, this, &MainWindow::fillStudentByJSON);
    connect(ui.actioncsv_3, &QAction::triggered, this, &MainWindow::fillStudentByCSV);
    
}

MainWindow::~MainWindow() {
}

void renderIntegerInput(ShrdPtr<Sequence<int>> seq, QPlainTextEdit* labels[], int n=-1, int k=-1)
{
    for (int i = 0; i < seq->GetLenght(); i++)
    {
        QPalette p = labels[i]->palette();
        if (i==n || i==k)
        {
            p.setColor(QPalette::Active, QPalette::Base, Qt::green);
        }
        else
        {
            p.setColor(QPalette::Active, QPalette::Base, Qt::darkGray);
        }
        labels[i]->setPalette(p);
        labels[i]->setPlainText(QString::number(seq->Get(i)));
        
    }
    QCoreApplication::processEvents();
    QThread::sleep(1);
}

void renderFloatInput(ShrdPtr<Sequence<float>> seq, QPlainTextEdit* labels[], int n=-1, int k=-1)
{
    for (int i = 0; i < seq->GetLenght(); i++)
    {
        QPalette p = labels[i]->palette();
        if (i == n || i == k)
        {
            p.setColor(QPalette::Active, QPalette::Base, Qt::green);
        }
        else
        {
            p.setColor(QPalette::Active, QPalette::Base, Qt::darkGray);
        }
        labels[i]->setPalette(p);
        labels[i]->setPlainText(QString::number(seq->Get(i)));

    }
    QCoreApplication::processEvents();
    QThread::sleep(1);

}

void renderStudentInput(ShrdPtr<Sequence<Student>> seq, QPlainTextEdit* labels[], int n=-1, int k= -1)
{
    for (int i = 0; i < seq->GetLenght(); i++)
    {
        QPalette p = labels[i]->palette();
        if (i == n || i == k)
        {
            p.setColor(QPalette::Active, QPalette::Base, Qt::green);
        }
        else
        {
            p.setColor(QPalette::Active, QPalette::Base, Qt::darkGray);
        }
        labels[i]->setPalette(p);
        labels[i]->setPlainText(QString::fromStdString(seq->Get(i).Name + seq->Get(i).Surname));

    }
    QCoreApplication::processEvents();
    QThread::sleep(1);
}

void MainWindow::fillIntegerByInput()
{
    int n = ui.spinBox->value();
    ShrdPtr<Sequence<int>> seq(new LinkedListSequence<int>());
    for (int i = 0; i < n; i++)
    {
        seq->Append((this->labels[i])->toPlainText().toInt());    
    }
    ShrdPtr<Sequence<int>> res = QuickSort<int>().sortAnimated(seq, compareIntegersAscending, labels, renderIntegerInput);
    renderIntegerInput(std::move(res),this->labels, -1,-1);
}

void MainWindow::fillIntegerByJSON()
{
    ShrdPtr<Sequence<int>> seq = jsonDataLoader().getIntegerDataFromJSON(jsonPath);
    ui.spinBox->setValue(seq->GetLenght());
    renderIntegerInput(std::move(seq), this->labels,-1,-1);
    ShrdPtr<Sequence<int>> res = QuickSort<int>().sortAnimated(seq, compareIntegersAscending, this->labels, renderIntegerInput);
}

void MainWindow::fillIntegerByCSV()
{
    ShrdPtr<Sequence<int>> seq = csvDataLoader().getIntegerDataFromCSV(csvPath);
    ui.spinBox->setValue(seq->GetLenght());
    renderIntegerInput(std::move(seq), this->labels, -1,-1);
    ShrdPtr<Sequence<int>> res = QuickSort<int>().sortAnimated(seq, compareIntegersAscending, labels, renderIntegerInput);
}

void MainWindow::fillFloatByInput()
{
    int n = ui.spinBox->value();
    ShrdPtr<Sequence<float>> seq(new LinkedListSequence<float>());
    for (int i = 0; i < n; i++)
    {
        seq->Append((this->labels[i])->toPlainText().toFloat());
    }
    ShrdPtr<Sequence<float>> res = QuickSort<float>().sortAnimated(seq, compareFloatAscending,this->labels,renderFloatInput);
    renderFloatInput(std::move(res), this->labels, -1, -1);
    
}

void MainWindow::fillFloatByJSON()
{
    ShrdPtr<Sequence<float>> seq = jsonDataLoader().getFloatDataFromJSON(jsonPath);
    ui.spinBox->setValue(seq->GetLenght());
    renderFloatInput(std::move(seq), this->labels);
    ShrdPtr<Sequence<float>> res = QuickSort<float>().sortAnimated(seq, compareFloatAscending, this->labels, renderFloatInput);
    renderFloatInput(std::move(res), this->labels, -1, -1);
}

void MainWindow::fillFloatByCSV()
{
    ShrdPtr<Sequence<float>> seq = csvDataLoader().getFloatDataFromCSV(csvPath);
    ui.spinBox->setValue(seq->GetLenght());
    renderFloatInput(std::move(seq), this->labels, -1, -1);
    ShrdPtr<Sequence<float>> res = QuickSort<float>().sortAnimated(seq, compareFloatAscending, this->labels, renderFloatInput);
    renderFloatInput(std::move(res), this->labels, -1, -1);

}

void MainWindow::fillStudentByJSON()
{
    ShrdPtr<Sequence<Student>> seq = jsonDataLoader().getStudentDataFromJSON(jsonPath);
    ui.spinBox->setValue(seq->GetLenght());
    renderStudentInput(std::move(seq), this->labels);
    ShrdPtr<Sequence<Student>> res = QuickSort<Student>().sortAnimated(seq, compareStudentByAgeAscending, labels, renderStudentInput);
    renderStudentInput(std::move(res), this->labels);

}

void MainWindow::fillStudentByCSV()
{
    ShrdPtr<Sequence<Student>> seq = csvDataLoader().getStudentDataFromCSV(csvPath);
    ui.spinBox->setValue(seq->GetLenght());
    renderStudentInput(std::move(seq), this->labels);
    ShrdPtr<Sequence<Student>> res = QuickSort<Student>().sortAnimated(seq, compareStudentByAgeAscending,labels,renderStudentInput);
    renderStudentInput(std::move(res), this->labels);
}
