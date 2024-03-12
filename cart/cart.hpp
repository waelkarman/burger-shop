#pragma once
#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include <QObject>
#include "burger.hpp"
#include "dbhelper.hpp"
#include "dberrors.hpp"

using namespace std;

class Cart: public QAbstractListModel {

    Q_OBJECT

public:
    Cart();
    QueryResult dropCart();
    void add(Burger b);
    Q_INVOKABLE void add(QString s);
    Q_INVOKABLE void remove(QString s, int index);
    int getSum() const;
    string getNote() const;
    QueryResult fetchCartContent();
    QueryResult countCartContent();
    QueryResult fetchById(const int& n);

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    
private:
    Dbhelper db;

};
