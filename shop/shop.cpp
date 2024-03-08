#include "shop.hpp"
#include "dbhelper.hpp"
#include <string>
#include <QString>

Shop::Shop(QObject* parent):QAbstractListModel(parent) {
    QueryResult result;
    dropShop();

    try {
        db.createDatabase(result);
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

QueryResult Shop::dropShop(){
    QueryResult result;
    db.dropTable(result);
    return result;
}

QueryResult Shop::insertBurger(const Burger& b){
    QueryResult result;
    db.insertBurger(b,result);
    return result;
}

QueryResult Shop::countAllBurgers(){
    QueryResult result;
    db.countAllBurgers(result);
    return result;
}

QueryResult Shop::removeBurger(const Burger& b){
    QueryResult result;
    db.removeBurger(b,result);
    return result;
}

QueryResult Shop::fetchAllBurgers(){
    QueryResult result;
    db.fetchAllBurgers(result);
    return result;
}

QueryResult Shop::fetchByIsdn(const Burger& b) {
    QueryResult result;
    db.fetchByIsdn(b,result);
    return result;
}

QueryResult Shop::fetchById(const int& n) {
    QueryResult result;
    db.fetchById(n,result);
    return result;
}


QModelIndex Shop::index(int row, int column, const QModelIndex &parent) const {
    return createIndex(row, column);
}

QModelIndex Shop::parent(const QModelIndex &child) const {
    return QModelIndex();
}

int Shop::rowCount(const QModelIndex &parent) const {
    //FIXME
    QueryResult result = const_cast<Shop*>(this)->countAllBurgers();
    return stoi(result.records[0].columns[0]);
}

int Shop::columnCount(const QModelIndex &parent) const {
    return 2;
}


enum ItemDataRole {
    namerole = 0,
    pricerole = 1,
    backgroundrole = 2
};

QVariant Shop::data(const QModelIndex &index, int role) const {
    // Restituisci il dato per l'indice specificato e ruolo specificato
    // Ad esempio, se role è Qt::DisplayRole, restituisci il testo da visualizzare
    //FIXME
    QueryResult result = const_cast<Shop*>(this)->fetchById(index.row()+1);

    switch (role) {
    case namerole:
        return QString(result.records[0].columns[2].c_str());
    case pricerole:
        return QString(result.records[0].columns[1].c_str());
    case backgroundrole:
        return QString(result.records[0].columns[0].c_str());
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> Shop::roleNames() const
{
    QHash<int, QByteArray> roles;

    // Definisci i nomi dei ruoli associati
    roles[namerole] = "namerole";
    roles[pricerole] = "pricerole";
    roles[backgroundrole] = "backgroundrole";

    // Aggiungi altri nomi dei ruoli se necessario

    return roles;
}
