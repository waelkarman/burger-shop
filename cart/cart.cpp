
#include <iostream>
#include "cart.hpp"
#include <QDebug>
#include <string>
#include "dbhelper.hpp"
#include "dberrors.hpp"

using namespace std;

void execute(const stringstream& ss, void* vp){
    Dbhelper db;
    try{
        db.execute_query(ss,vp);
    }catch(dberrors e){
        e.what();
    }catch(exception e){
        e.what();
    }catch(...){
        cout << "DataBase unknown error.";
    }
}

Cart::Cart(){
}

void Cart::dropCart()
{
    orders.erase(orders.begin(),orders.end());
}

void Cart::add(QString s)
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT PRICE FROM SHOP WHERE NAME = '" << s.toStdString() << "';";
    execute(ss,&result);

    sum+=stoi(result.records[0].columns[0]); //FIXME
    beginInsertRows( QModelIndex(), orders.size(), orders.size() );
    orders.append(s);
    endInsertRows();
    emit sumChanged();
}

void Cart::remove(QString s, int index)
{
    sum-=queryPrice(s); //FIXME;
    beginRemoveRows( QModelIndex(), index, index );
    orders.removeAt(index);
    endRemoveRows();
    emit sumChanged();
}

int Cart::getSum() const
{
    return sum;
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

int Cart::queryPrice(QString s) const
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT PRICE FROM SHOP WHERE NAME = '" << s.toStdString() << "';";
    execute(ss,&result);
    return stoi(result.records[0].columns[0]);
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
    return 1;
}


enum ItemDataRole {
    namerole = 0,
    pricerole = 1
};

QVariant Cart::data(const QModelIndex &index, int role) const {

    switch (role)
    {
    case namerole:
        return fetchById(index.row());
    case pricerole:
        return queryPrice(fetchById(index.row()));
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> Cart::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[namerole] = "namerole";
    roles[pricerole] = "pricerole";

    return roles;
}
