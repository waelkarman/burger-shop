#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "dbhelper.hpp"
#include "sqlite3.h"

using namespace std;

Dbhelper::Dbhelper(){}

static int dbprintoutput(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   cout << "--- DB OUTPUT ---" << endl;
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
   ss << "INSERT INTO SHOP (ISDN,NAME,NCOPY,PRICE) VALUES ('"<< b.getIsdn() <<"', '"<< b.getTitle() <<"', 0,"<< b.getPrice() <<");";
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
   ss << "DELETE FROM SHOP WHERE ISDN = '" << isdn << "';";

   sql = (char *)malloc((strlen(ss.str().c_str())+1)*sizeof(char));
   strcpy(sql, ss.str().c_str());

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, dbprintoutput, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      /* DECREASE THE NCOPY */

   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return true;
}

int Dbhelper::fetchISDN(string isdn){
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
   ss << "SELECT * FROM SHOP WHERE ISDN = '" << isdn << "';";

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