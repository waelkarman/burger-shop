#include "shop.hpp"
#include "dberrors.hpp"
#include "dbhelper.hpp"
#include <string>
#include <QString>

Shop::Shop(QObject* parent):QAbstractListModel(parent)
{
    QueryResult result;
    stringstream ss;

    dropShop();

    ss << "CREATE TABLE SHOP("
       << "ID             INTEGER     PRIMARY KEY AUTOINCREMENT,"
       << "TYPE           CHAR(10)    NOT NULL,"
       << "NAME           TEXT        NOT NULL,"
       << "DESCRIPTION    CHAR(50)    NOT NULL,"
       << "PRICE          INT         NOT NULL,"
       << "BACKGROUND     CHAR(10)    NOT NULL,"
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

QueryResult Shop::dropShop()
{
    stringstream ss;
    QueryResult result;
    ss << "DROP TABLE IF EXISTS SHOP;";
    db.execute_query(ss,&result);
    return result;
}

QueryResult Shop::insertBurger(const Burger& b)
{
    QueryResult result;
    stringstream ss;

    ss << "SELECT count(*) FROM SHOP WHERE NAME = '"<< b.getName() <<"';";
    db.execute_query(ss,&result);

    if ( stoi(result.records[0].columns[0]) > 0)
    {
        ss << "UPDATE SHOP SET NCOPY = NCOPY+1 WHERE NAME = '"<< b.getName() <<"';";
    }else
    {
        ss << "INSERT INTO SHOP (TYPE,NAME,BACKGROUND,DESCRIPTION,NCOPY,PRICE) VALUES ('"
           << b.getType() <<"', '"<< b.getName()<<"', '"<< b.getBackground() <<"', '"<< b.getDescription() <<"', 1,"
           << b.getPrice() <<");";
    }

    db.execute_query(ss,&result);
    return result;
}

QueryResult Shop::countAllBurgers()
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT COUNT(*) FROM SHOP;";
    db.execute_query(ss,&result);
    return result;
}

QueryResult Shop::removeBurger(const Burger& b)
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT NCOPY FROM SHOP WHERE NAME = '"<< b.getName() <<"';";
    db.execute_query(ss,&result);

    if ( stoi(result.records[0].columns[0]) > 1)
    {
        ss << "UPDATE SHOP SET NCOPY = NCOPY-1 WHERE NAME = '"<< b.getName() <<"';";
    }else
    {
        ss << "DELETE FROM SHOP WHERE NAME = '"<< b.getName() <<"';";
    }
    db.execute_query(ss,&result);
    return result;
}

QueryResult Shop::fetchAllBurgers()
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT * FROM SHOP;";
    db.execute_query(ss,&result);
    return result;
}

QueryResult Shop::fetchByType(const Burger& b)
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT NAME FROM SHOP WHERE TYPE = " << b.getType() << ";";
    db.execute_query(ss,&result);
    return result;
}

QueryResult Shop::fetchById(const int& n)
{
    stringstream ss;
    QueryResult result;
    ss << "SELECT NAME, PRICE, BACKGROUND FROM SHOP WHERE ID = " << n << ";";
    db.execute_query(ss,&result);
    return result;
}


QModelIndex Shop::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex Shop::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int Shop::rowCount(const QModelIndex &parent) const
{
    //FIXME
    QueryResult result = const_cast<Shop*>(this)->countAllBurgers();
    return stoi(result.records[0].columns[0]);
}

int Shop::columnCount(const QModelIndex &parent) const
{
    return 2;
}


enum ItemDataRole
{
    namerole = 0,
    pricerole = 1,
    backgroundrole = 2
};

QVariant Shop::data(const QModelIndex &index, int role) const
{
    // Restituisci il dato per l'indice specificato e ruolo specificato
    // Ad esempio, se role è Qt::DisplayRole, restituisci il testo da visualizzare
    //FIXME
    QueryResult result = const_cast<Shop*>(this)->fetchById(index.row()+1);

    switch (role) 
    {
    case namerole:
        return QString(result.records[0].columns[0].c_str());
    case pricerole:
        return QString(result.records[0].columns[1].c_str());
    case backgroundrole:
        return QString(result.records[0].columns[2].c_str());
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


Shop::~Shop()
{}
