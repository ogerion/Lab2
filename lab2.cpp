#pragma once

#include "lab2_final.h"
#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "setup.h"
#include "tests/testCSVDataLoader.h"
#include "tests/testJSONDataLoader.h"
#include "tests/testQuickSort.h"
#include "tests/testHeapSort.h"
#include "tests/testInsertionSort.h"
int main(int argc, char* argv[]) {
    testJSONDataLoader();
    testCSVDataLoader();
    testQuickSort();
    testHeapSort();
    testInsertionSort();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
