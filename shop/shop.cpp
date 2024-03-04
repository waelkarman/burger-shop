#include "shop.hpp"
#include "dbhelper.hpp"

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

    for (const auto& record : result.records) {
        for (const auto& column : record.columns) {
            printf("%s ", column.c_str());
        }
        printf("\n");
    }

    return result;
}


QueryResult Shop::insertBook(const Book& b){
    QueryResult result;
    db.insertBook(b,result);

    for (const auto& record : result.records) {
        for (const auto& column : record.columns) {
            printf("%s ", column.c_str());
        }
        printf("\n");
    }

    return result;
}

QueryResult Shop::countAllBooks() {
    QueryResult result;
    db.countAllBooks(result);

    for (const auto& record : result.records) {
        for (const auto& column : record.columns) {
            printf("%s ", column.c_str());
        }
        printf("\n");
    }

    return result;
}

QueryResult Shop::removeBook(const Book& b){
    QueryResult result;
    db.removeBook(b,result);

    for (const auto& record : result.records) {
        for (const auto& column : record.columns) {
            printf("%s ", column.c_str());
        }
        printf("\n");
    }

    return result;
}

QueryResult Shop::fetchAllBooks(){
    QueryResult result;
    db.fetchAllBooks(result);

    for (const auto& record : result.records) {
        for (const auto& column : record.columns) {
            printf("%s ", column.c_str());
        }
        printf("\n");
    }
    return result;
}

QueryResult Shop::fetchBook(const Book& b) {
    QueryResult result;
    db.fetchBook(b,result);
    return result;
}







QModelIndex Shop::index(int row, int column, const QModelIndex &parent) const {
    // Restituisci l'indice per la cella specificata
    // Utilizza QAbstractItemModel::createIndex per creare un indice
    //return createIndex(row, column);
}

QModelIndex Shop::parent(const QModelIndex &child) const {
    // Restituisci l'indice del genitore per il dato indice
    //return QModelIndex();
}

int Shop::rowCount(const QModelIndex &parent) const {
    // Restituisci il numero di righe sotto il genitore specificato
    //return countAll();
}

int Shop::columnCount(const QModelIndex &parent) const {
    // Restituisci il numero di colonne sotto il genitore specificato
    //return 0;
}

QVariant Shop::data(const QModelIndex &index, int role) const {
    // Restituisci il dato per l'indice specificato e ruolo specificato
    // Ad esempio, se role è Qt::DisplayRole, restituisci il testo da visualizzare
    // return fetchNum(index.row()+1);
}
