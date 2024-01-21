#include <iostream>
#include "dbhelper.hpp"
#include "sqlite3.h"

using namespace std;

Dbhelper::Dbhelper(){}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

bool Dbhelper::createDatabase(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    rc = sqlite3_open("shop-db.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return false;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
 
    sql = "CREATE TABLE SHOP("  \
        "ISDN           CHAR(10) PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL," \
        "NCOPY          INT     NOT NULL," \
        "PRICE          INT     NOT NULL );";
 
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
    
    return true;
}


bool insertBook(Book b){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
 
    /* Open database */
    rc = sqlite3_open("shop-db.db", &db);
   
    if( rc ) {
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
       return(0);
    } else {
       fprintf(stderr, "Opened database successfully\n");
    }
 
    /* Create SQL statement */
    sql = "INSERT INTO COMPANY (ISDN,NAME,NCOPY,PRICE) "  \
          "VALUES (qwerty, 'Paul', 32, 45);";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);
    return 0;
}
