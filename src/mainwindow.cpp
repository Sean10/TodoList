/*
 *  @file   mainwindow.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    ,ui_(new Ui::MainWindow)
    ,modelStringList_(new model)
{
    ui_->setupUi(this);

    InitState();
}

MainWindow::~MainWindow()
{
    delete modelStringList_;
    delete ui_;
}

void MainWindow::InitState()
{
    connect(ui_->pushButtonAdd,SIGNAL(clicked()), this, SLOT(PushButtonClickedAdd()));
    connect(ui_->pushButtonDel,SIGNAL(clicked()), this, SLOT(PushButtonClickedDel()));

    this->setWindowTitle("Reminder");
    //this->setWindowIcon(QIcon("/img/icn.png"));
    ui_->listView->setModel(modelStringList_);
    ui_->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::SelectedClicked | QAbstractItemView::DoubleClicked);

    ui_->listView->setSelectionMode(QAbstractItemView::NoSelection);
    ui_->listView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::PushButtonClickedAdd()
{
    modelStringList_->insertRow(modelStringList_->rowCount());
}

void MainWindow::PushButtonClickedDel()
{
    modelStringList_->removeRow(ui_->listView->currentIndex().row());
}
