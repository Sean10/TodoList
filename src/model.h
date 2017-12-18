/*
 *  @file   model.h
 *  @brief  摘要
 *  Copyright (c) 2017
 */
#ifndef MODEL_H
#define MODEL_H

#include <QStringListModel>
#include <QString>
#include <QVector>
#include <QTime>
#include <QBitArray>

class model : public QStringListModel
{
    Q_OBJECT
public:
    model(QObject* parent= 0);
    ~model();

    int rowCount(const QModelIndex & index = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool insertRow(int row, const QModelIndex &index= QModelIndex());
    bool removeRow(int row, const QModelIndex &index = QModelIndex());

private:
    QVector<QString> string_;
    QBitArray flag_check;
};

#endif // MODEL_H
