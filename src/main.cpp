/*
 *  @file   main.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.setWindowIcon(QIcon(":/img/icn.png"));

    return a.exec();
}
