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

QueryResult Shop::insertBook(const Book& b){
    QueryResult result;
    db.insertBook(b,result);
    return result;
}

QueryResult Shop::countAllBooks(){
    QueryResult result;
    db.countAllBooks(result);
    return result;
}

QueryResult Shop::removeBook(const Book& b){
    QueryResult result;
    db.removeBook(b,result);
    return result;
}

QueryResult Shop::fetchAllBooks(){
    QueryResult result;
    db.fetchAllBooks(result);
    return result;
}

QueryResult Shop::fetchByIsdn(const Book& b) {
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
    QueryResult result = const_cast<Shop*>(this)->countAllBooks();
    return stoi(result.records[0].columns[0]);
}

int Shop::columnCount(const QModelIndex &parent) const {
    return 0;
}

QVariant Shop::data(const QModelIndex &index, int role) const {
    // Restituisci il dato per l'indice specificato e ruolo specificato
    // Ad esempio, se role è Qt::DisplayRole, restituisci il testo da visualizzare
    QueryResult result = const_cast<Shop*>(this)->fetchById(index.row()+1);
    return QString(result.records[0].columns[0].c_str());
}
