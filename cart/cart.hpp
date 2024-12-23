#pragma once
#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include <QObject>

using namespace std;

class Cart: public QAbstractListModel {

    Q_OBJECT
    Q_PROPERTY(int sum READ getSum NOTIFY sumChanged)

public:
    Cart();
    void dropCart();
    Q_INVOKABLE void add(QString s);
    Q_INVOKABLE void remove(QString s, int index);
    int getSum() const;
    string getNote() const;
    Q_INVOKABLE void fetchCartContent();
    int countCartContent() const ;
    Q_INVOKABLE QString fetchById(const int& n) const;
    int queryPrice(QString s) const;


    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void sumChanged();
    
private:
    QVector<QString> orders;
    int sum = 0;

};
