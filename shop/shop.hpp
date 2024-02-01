#pragma once
#include "book.hpp"
#include "dbhelper.hpp"

#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include <QObject>

using namespace std;

class Shop: public QAbstractListModel {

    Q_OBJECT

public:
    Shop(QObject *parent = nullptr);
    bool dropShop();
    bool insertISDN(const Book& b);
    bool removeISDN(const string& isdn);
    bool fetchAll();
    QString fetchNum(const int& n) const;
    int countAll() const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    ~Shop() override;

private:
    Dbhelper db;

};
