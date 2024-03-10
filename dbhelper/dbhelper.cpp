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
