#include "shop.hpp"
#include "dbhelper.hpp"


Shop::Shop(QObject* parent):QAbstractListModel(parent) {
    dropShop();
    db.createDatabase();
}

bool Shop::insertISDN(const Book& b){
    db.insertISDN(b);
    return true;
}

bool Shop::removeISDN(const string& isdn){
    db.removeISDN(isdn);
    return true;
}

bool Shop::fetchAll(){
    db.fetchAll();
    return true;
}

QString Shop::fetchNum(const int& n) const {
    QString a(db.fetchNum(n));
    return a;
}

bool Shop::dropShop(){
    return db.dropTable();
}

int Shop::countAll() const {
    return db.countAll();
}


Shop::~Shop() {

};


QModelIndex Shop::index(int row, int column, const QModelIndex &parent) const {
    // Restituisci l'indice per la cella specificata
    // Utilizza QAbstractItemModel::createIndex per creare un indice
    return createIndex(row, column);
}

QModelIndex Shop::parent(const QModelIndex &child) const {
    // Restituisci l'indice del genitore per il dato indice
    return QModelIndex();
}

int Shop::rowCount(const QModelIndex &parent) const {
    // Restituisci il numero di righe sotto il genitore specificato
    return countAll();
}

int Shop::columnCount(const QModelIndex &parent) const {
    // Restituisci il numero di colonne sotto il genitore specificato
    return 0;
}

QVariant Shop::data(const QModelIndex &index, int role) const {
    // Restituisci il dato per l'indice specificato e ruolo specificato
    // Ad esempio, se role è Qt::DisplayRole, restituisci il testo da visualizzare
    return fetchNum(index.row()+1);
}
