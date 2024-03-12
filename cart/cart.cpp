
#include <iostream>
#include "cart.hpp"
#include "dbhelper.hpp"

using namespace std;

Cart::Cart(){
}

void Cart::dropCart()
{
    orders.erase(orders.begin(),orders.end());
}

void Cart::add(QString s)
{
    beginInsertRows( QModelIndex(), orders.size(), orders.size() );
    orders.append(s);
    endInsertRows();
}

void Cart::remove(int index)
{
    beginRemoveRows( QModelIndex(), index, index );
    orders.removeAt(index);
    endRemoveRows();
}

int Cart::getSum() const
{
    return 0;
}

string Cart::getNote() const
{
    return "note";
}

void Cart::fetchCartContent()
{
    for(const auto s : orders){
        cout << s.toStdString() << endl;
    }
}

int Cart::countCartContent() const
{
    return orders.size();
}

QString Cart::fetchById(const int& n) const
{
    return orders.at(n);
}





QModelIndex Cart::index(int row, int column, const QModelIndex &parent) const {
    return createIndex(row, column);
}

QModelIndex Cart::parent(const QModelIndex &child) const {
    return QModelIndex();
}

int Cart::rowCount(const QModelIndex &parent) const {
    return countCartContent();
}

int Cart::columnCount(const QModelIndex &parent) const {
    return 0;
}


enum ItemDataRole {
    namerole = 0
};

QVariant Cart::data(const QModelIndex &index, int role) const {
    return fetchById(index.row());
}

QHash<int, QByteArray> Cart::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[namerole] = "namerole";

    return roles;
}
