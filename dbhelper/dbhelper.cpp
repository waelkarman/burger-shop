#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <unistd.h>
#include "dbhelper.hpp"
#include "sqlite3.h"
#include "dberrors.hpp"

using namespace std;

Dbhelper::Dbhelper():rc(sqlite3_open("shop-db.db", &db)){}

Dbhelper::~Dbhelper(){sqlite3_close(db);}

int default_callback(void *NotUsed, int argc, char **argv, char **azColName) {
    QueryResult* result = reinterpret_cast<QueryResult*>(NotUsed);
    Record record;

    for(int i = 0; i<argc; i++) {
        record.columns.push_back(argv[i] ? argv[i] : "NULL");
    }

    result->records.push_back(record);
    return 0;
}

void Dbhelper::execute_query(const stringstream& ss, int(*f)(void *NotUsed, int argc, char **argv, char **azColName), void* vp){
    char *zErrMsg = 0;
    char *sql;

    if( rc ) {
        throw dberrors(sqlite3_errmsg(db));
    }

    sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
    strncpy(sql, ss.str().c_str(),strlen(ss.str().c_str())+1);

    rc = sqlite3_exec(db, sql, f, vp, &zErrMsg);
    free(sql);

    if( rc != SQLITE_OK ){
        throw dberrors(string(zErrMsg));
        sqlite3_free(zErrMsg);
    }
}

void Dbhelper::dropTable(QueryResult& vp){
    stringstream ss;
    ss << "DROP TABLE IF EXISTS SHOP;";
    execute_query(ss,default_callback,&vp);
}

void Dbhelper::createDatabase(QueryResult& vp){
    stringstream ss;
    ss << "CREATE TABLE SHOP("
       << "ID             INTEGER     PRIMARY KEY AUTOINCREMENT,"
       << "ISDN           CHAR(10)    NOT NULL,"
       << "NAME           TEXT        NOT NULL,"
       << "PRICE          INT         NOT NULL,"
       << "NCOPY          INT         CHECK(NCOPY > 0));";
    execute_query(ss,default_callback,&vp);
}

void Dbhelper::insertBook(Book b, QueryResult& vp){
    stringstream ss;

    ss << "SELECT count(*) FROM SHOP WHERE ISDN = '"<< b.getIsdn() <<"';";
    execute_query(ss,default_callback,&vp);

    if ( stoi(vp.records[0].columns[0]) > 0){
        ss << "UPDATE SHOP SET NCOPY = NCOPY+1 WHERE ISDN = '"<< b.getIsdn() <<"';";
    }else{
        ss << "INSERT INTO SHOP (ISDN,NAME,NCOPY,PRICE) VALUES ('"
           << b.getIsdn() <<"', '"<< b.getTitle() <<"', 1,"
           << b.getPrice() <<");";
    }

    execute_query(ss,default_callback,&vp);
}

void Dbhelper::countAllBooks(QueryResult& vp){
    stringstream ss;
    ss << "SELECT COUNT(*) FROM SHOP;";
    execute_query(ss,default_callback,&vp);
}

void Dbhelper::removeBook(Book b, QueryResult& vp){
    stringstream ss;
    ss << "SELECT NCOPY FROM SHOP WHERE ISDN = '"<< b.getIsdn() <<"';";
    execute_query(ss,default_callback,&vp);

    if ( stoi(vp.records[0].columns[0]) > 1){
        ss << "UPDATE SHOP SET NCOPY = NCOPY-1 WHERE ISDN = '"<< b.getIsdn() <<"';";
    }else{
        ss << "DELETE FROM SHOP WHERE ISDN = '"<< b.getIsdn() <<"';";
    }
    execute_query(ss,default_callback,&vp);
}

void Dbhelper::fetchBook(Book b, QueryResult& vp) {
    stringstream ss;
    ss << "SELECT NAME FROM SHOP WHERE ISDN = " << b.getIsdn() << ";";
    execute_query(ss,default_callback,&vp);
}

void Dbhelper::fetchAllBooks(QueryResult& vp){
    stringstream ss;

    ss << "SELECT * FROM SHOP;";
    execute_query(ss,default_callback,&vp);
}

