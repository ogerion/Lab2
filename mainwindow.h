#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainUI.h"
#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtWidgets/QPlainTextEdit>
#include <QThread>
#include <QCoreApplication>
#include "setup.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    

private:
    std::string jsonPath = "data.json";
    std::string csvPath = "data.csv";
    
    Ui::MainWindow ui;
    
    QVector<int> numbers;
    QTimer* timer;
    int currentIndex;
    void fillIntegerByInput();
    void fillIntegerByJSON();
    void fillIntegerByCSV();
    void fillFloatByInput();
    void fillFloatByJSON();
    void fillFloatByCSV();
    void fillStudentByJSON();
    void fillStudentByCSV();

    QPlainTextEdit* labels[15];
};

#endif // MAINWINDOW_H
