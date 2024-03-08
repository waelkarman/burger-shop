#pragma once
#include <iostream>
#include <vector>
#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include <QObject>

using namespace std;

class Cart: public QAbstractListModel {

    Q_OBJECT

public:
    Cart();
    int add(int n);
    int remove(int n);

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = 100) const override;
    QHash<int, QByteArray> roleNames() const override;
    
private: 
    int sum=0;
    vector<int> cartlist;  
};
