/*
 *  @file   model.cpp
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#include "model.h"
#include <QDebug>

enum { RowCount = 5 };

model::model(QObject* parent)
    :QStringListModel (parent)
    ,string_(RowCount,"")
    ,flag_check(RowCount, false)
{
}

model::~model()
{

}

int model::rowCount(const QModelIndex& index) const
{
    return string_.size();
}

QVariant model::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
    case Qt::DisplayRole:
        //return QString("Info %1.Edit time:%2").arg(index.row()).arg(QTime::currentTime().toString());
        return string_[index.row()]+QString("\t%1").arg(QTime::currentTime().toString());
    case Qt::CheckStateRole:
        //qDebug() << flag_check.at(index.row()) ;
        return flag_check.at(index.row()) ? Qt::Checked : Qt::Unchecked;
    }

    return QVariant();
}

bool model::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if(role == Qt::EditRole)
    {
        //index.data(Qt::DisplayRole).toString();
        string_[index.row()] = value.toString();
    }
    if(role == Qt::CheckStateRole)
    {
        auto s = static_cast<Qt::CheckState>(value.toInt());
        s == Qt::Checked ? flag_check.setBit(index.row()) : flag_check.clearBit(index.row());
        //qDebug() << s;
    }
    return true;
}

Qt::ItemFlags model::flags(const QModelIndex &index) const
{
    return Qt::ItemIsUserCheckable | Qt::ItemIsEditable | QStringListModel::flags(index);
}

bool model::insertRow(int row, const QModelIndex &index)
{
    string_.append("");
    flag_check.resize(this->rowCount());
    flag_check.clearBit(this->rowCount()-1);
    this->insertRows(row,1,index);
    return true;
}


/**
 *  @brief 移除当前行，存在crash bug
 *  @param 当前行，index
 *  @retval true or false
 */
bool model::removeRow(int row, const QModelIndex &index)
{
    string_.erase(string_.begin()+row);
    for(int i = row; i < this->rowCount(); i++)
        flag_check[i] = flag_check[i+1];
    //flag_check.resize(this->rowCount());

    this->removeRows(row, 1, index);
    return true;
}
