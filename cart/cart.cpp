
#include <iostream>
#include "cart.hpp"

using namespace std;

Cart::Cart():sum(0){}

void Cart::add(Burger n){

}

void Cart::remove(Burger n){

}

int Cart::getSum(){
    return sum;
}






















QModelIndex Cart::index(int row, int column, const QModelIndex &parent) const {
    return createIndex(row, column);
}

QModelIndex Cart::parent(const QModelIndex &child) const {
    return QModelIndex();
}

int Cart::rowCount(const QModelIndex &parent) const {
    //FIXME
    //QueryResult result = const_cast<Cart*>(this)->countAllBurgers();
    //return stoi(result.records[0].columns[0]);
}

int Cart::columnCount(const QModelIndex &parent) const {
    return 2;
}


enum ItemDataRole {
    namerole = 0,
    pricerole = 1,
    backgroundrole = 2
};

QVariant Cart::data(const QModelIndex &index, int role) const {
    // Restituisci il dato per l'indice specificato e ruolo specificato
    // Ad esempio, se role è Qt::DisplayRole, restituisci il testo da visualizzare
    //FIXME
    // QueryResult result = const_cast<Cart*>(this)->fetchById(index.row()+1);

    // switch (role) {
    // case namerole:
    //     return QString(result.records[0].columns[2].c_str());
    // case pricerole:
    //     return QString(result.records[0].columns[1].c_str());
    // case backgroundrole:
    //     return QString(result.records[0].columns[0].c_str());
    // default:
    //     return QVariant();
    // }
}

QHash<int, QByteArray> Cart::roleNames() const
{
    QHash<int, QByteArray> roles;

    // Definisci i nomi dei ruoli associati
    roles[namerole] = "namerole";
    roles[pricerole] = "pricerole";
    roles[backgroundrole] = "backgroundrole";

    // Aggiungi altri nomi dei ruoli se necessario

    return roles;
}
