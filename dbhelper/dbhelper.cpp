#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "dbhelper.hpp"
#include "sqlite3.h"

using namespace std;

Dbhelper::Dbhelper(){}


int dbcallbackfetchNum(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        char *a = (char*)NotUsed;
        strcpy(a,argv[i]);
    }
    printf("\n");
    return 0;
}


int dbcallbackcountAll(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
       int *a = (int*)NotUsed;
      *a = atoi(argv[i]);
   }

   printf("\n");
   return 0;
}


int dbprintoutput(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

bool Dbhelper::dropTable(){
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

    sql = "DROP TABLE IF EXISTS SHOP;";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, dbprintoutput, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);

    return true;
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
        "ID             INTEGER     PRIMARY KEY AUTOINCREMENT," \
        "ISDN           CHAR(10)    NOT NULL," \
        "NAME           TEXT        NOT NULL," \
        "PRICE          INT         NOT NULL," \
        "NCOPY          INT         CHECK(NCOPY > 0));";
 
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, dbprintoutput, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
    
    return true;
}


bool Dbhelper::insertISDN(Book b){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("shop-db.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return false;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   stringstream ss;
   ss << "INSERT INTO SHOP (ISDN,NAME,NCOPY,PRICE) VALUES ('"<< b.getIsdn() <<"', '"<< b.getTitle() <<"', 1,"<< b.getPrice() <<");";
   sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
   strcpy(sql, ss.str().c_str());

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, dbprintoutput, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      /* INCREASE COUNTER */
      stringstream ss;
      ss << "UPDATE SHOP SET NCOPY = NCOPY+1 WHERE ISDN = '"<< b.getIsdn() <<"';";
      sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
      strcpy(sql, ss.str().c_str());

      /* Execute SQL statement */
      rc = sqlite3_exec(db, sql, dbprintoutput, 0, &zErrMsg);

   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return true;
}


bool Dbhelper::removeISDN(string isdn){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("shop-db.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return false;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   stringstream ss;
   ss << "UPDATE SHOP SET NCOPY = NCOPY-1 WHERE ISDN = '"<< isdn <<"';";

   sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
   strcpy(sql, ss.str().c_str());

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, dbprintoutput, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      /* REMOVE RECORD */
       stringstream ss;
      ss << "DELETE FROM SHOP WHERE ISDN = '"<< isdn <<"';";
      sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
      strcpy(sql, ss.str().c_str());

      /* Execute SQL statement */
      rc = sqlite3_exec(db, sql, dbprintoutput, 0, &zErrMsg);

   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return true;
}

char* Dbhelper::fetchNum(int n) const{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("shop-db.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return "";
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   stringstream ss;
   ss << "SELECT NAME FROM SHOP WHERE ID = " << n << ";";

   sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
   strcpy(sql, ss.str().c_str());

   char *name;
   name = (char*)malloc(sizeof(char)*20);
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, dbcallbackfetchNum, name, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return name;
}

int Dbhelper::fetchAll(){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("shop-db.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return false;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   stringstream ss;
   ss << "SELECT * FROM SHOP;";

   sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
   strcpy(sql, ss.str().c_str());

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, dbprintoutput, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return true;
}


int Dbhelper::countAll() const{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    /* Open database */
    rc = sqlite3_open("shop-db.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return false;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    stringstream ss;
    ss << "SELECT count(*) FROM SHOP;";

    sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
    strcpy(sql, ss.str().c_str());
    int *count;
    count = (int*)malloc(sizeof(int));
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, dbcallbackcountAll, count, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);
    return *count;
}
