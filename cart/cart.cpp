
#include <iostream>
#include "cart.hpp"
#include "dbhelper.hpp"

using namespace std;

Cart::Cart(){
    QueryResult result;
    stringstream ss;

    dropCart();

    ss << "CREATE TABLE CART("
       << "ID             INTEGER     PRIMARY KEY AUTOINCREMENT,"
       << "NAME           TEXT        NOT NULL,"
       << "NOTE           CHAR(40)    NOT NULL,"
       << "NCOPY          INT         CHECK(NCOPY > 0));";

    try{
        db.execute_query(ss,&result);
    }catch(dberrors e){
        e.what();
    }catch(exception e){
        e.what();
    }catch(...){
        cout << "DataBase unknown error.";
    }
}

QueryResult Cart::dropCart()
{
    stringstream ss;
    QueryResult result;
    ss << "DROP TABLE IF EXISTS CART;";
    db.execute_query(ss,&result);
    return result;
}

void Cart::add(Burger b)
{
    QueryResult result;
    stringstream ss;

    ss << "SELECT count(*) FROM CART WHERE NAME = '"<< b.getName() <<"';";
    db.execute_query(ss,&result);

    if ( stoi(result.records[0].columns[0]) > 0)
    {
        ss << "UPDATE CART SET NCOPY = NCOPY+1 WHERE NAME = '"<< b.getName() <<"';";
    }else
    {
        ss << "INSERT INTO CART (NAME,NOTE,NCOPY) VALUES ('"
           << b.getName() <<"', '"<< "NOTE-NOTE" <<"', '"<< 1 <<"');";
    }

    db.execute_query(ss,&result);
}

void Cart::add(QString s)
{
    QueryResult result;
    stringstream ss;

    ss << "SELECT count(*) FROM CART WHERE NAME = '"<< s.toStdString() <<"';";
    db.execute_query(ss,&result);

    if ( stoi(result.records[0].columns[0]) > 0)
    {
        ss << "UPDATE CART SET NCOPY = NCOPY+1 WHERE NAME = '"<< s.toStdString() <<"';";
        db.execute_query(ss,&result);
    }else
    {
        ss << "INSERT INTO CART (NAME,NOTE,NCOPY) VALUES ('"
           << s.toStdString() <<"', '"<< "NOTE-NOTE" <<"', '"<< 1 <<"');";

        beginInsertRows( QModelIndex(), stoi(countCartContent().records[0].columns[0]), stoi(countCartContent().records[0].columns[0]) );
        db.execute_query(ss,&result);
        endInsertRows();
    }
}

void Cart::remove(QString s, int index)
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT NCOPY FROM CART WHERE NAME = '"<< s.toStdString() <<"';";
    db.execute_query(ss,&result);

    if ( stoi(result.records[0].columns[0]) > 1)
    {
        ss << "UPDATE CART SET NCOPY = NCOPY-1 WHERE NAME = '"<< s.toStdString() <<"';";
        db.execute_query(ss,&result);
    }else
    {
        ss << "DELETE FROM CART WHERE NAME = '"<< s.toStdString() <<"';";

        beginRemoveRows( QModelIndex(), index, index );
        db.execute_query(ss,&result);
        endRemoveRows();
    }
}

int Cart::getSum() const
{
    return 0;
}

string Cart::getNote() const
{
    return "note";
}

QueryResult Cart::fetchCartContent()
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT * FROM CART;";
    db.execute_query(ss,&result);
    return result;
}

QueryResult Cart::countCartContent()
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT COUNT(*) FROM CART;";
    db.execute_query(ss,&result);
    return result;
}

QueryResult Cart::fetchById(const int& n)
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT NAME FROM CART WHERE ID = " << n << ";";
    db.execute_query(ss,&result);
    return result;
}





QModelIndex Cart::index(int row, int column, const QModelIndex &parent) const {
    return createIndex(row, column);
}

QModelIndex Cart::parent(const QModelIndex &child) const {
    return QModelIndex();
}

int Cart::rowCount(const QModelIndex &parent) const {
    //FIXME
    QueryResult result = const_cast<Cart*>(this)->countCartContent();
    return stoi(result.records[0].columns[0]);
}

int Cart::columnCount(const QModelIndex &parent) const {
    return 0;
}


enum ItemDataRole {
    namerole = 0
    //pricerole = 1,
    //backgroundrole = 2
};

QVariant Cart::data(const QModelIndex &index, int role) const {
    // Restituisci il dato per l'indice specificato e ruolo specificato
    // Ad esempio, se role è Qt::DisplayRole, restituisci il testo da visualizzare
    //FIXME
    QueryResult result = const_cast<Cart*>(this)->fetchById(index.row()+1);
    return QString(result.records[0].columns[0].c_str());
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
    //roles[pricerole] = "pricerole";
    //roles[backgroundrole] = "backgroundrole";

    // Aggiungi altri nomi dei ruoli se necessario

    return roles;
}
