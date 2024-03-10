#pragma once
#include "burger.hpp"
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
    QueryResult dropShop();
    QueryResult insertBurger(Burger b);
    QueryResult removeBurger(Burger b);
    QueryResult fetchAllBurgers();
    QueryResult fetchByIsdn(Burger b);
    QueryResult fetchById(const int& n);
    QueryResult countAllBurgers();

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = 100) const override;
    QHash<int, QByteArray> roleNames() const override;

    ~Shop() override {};

private:
    Dbhelper db;
    int sum = 0;

};
