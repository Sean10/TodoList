/*
 *  @file   mainwindow.h
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <src/model.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui_;
    model* modelStringList_;


    void InitState();

private slots:
    void PushButtonClickedAdd();
    void PushButtonClickedDel();
};

#endif // MAINWINDOW_H
