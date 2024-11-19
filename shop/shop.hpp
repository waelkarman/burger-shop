#pragma once
#include "burger.hpp"
#include "dbhelper.hpp"

#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include <QObject>

using namespace std;

// FIXME: make it as singleton
class Shop: public QAbstractListModel
{

    Q_OBJECT

public:
    Shop(QObject *parent = nullptr);
    QueryResult dropShop();
    QueryResult insertBurger(const Burger& b);
    QueryResult removeBurger(const Burger& b);
    QueryResult fetchAllBurgers();
    QueryResult fetchByType(const Burger& b);
    QueryResult fetchById(const int& n);
    QueryResult countAllBurgers();
    void execute(const stringstream& ss, void* vp);
    Q_INVOKABLE QString getNamerole(int index);
    Q_INVOKABLE QString getPricerole(int index);
    Q_INVOKABLE QString getBackgroundrole(int index);


    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    ~Shop() override;

private:
    Dbhelper db;

};
