#pragma once
#include "book.hpp"
#include <sstream>
#include <vector>
#include "sqlite3.h"

using namespace std;

struct Record {
    std::vector<std::string> columns;
};

struct QueryResult {
    std::vector<Record> records;
};



class Dbhelper {
    int rc;
    sqlite3 *db;
private:
    void execute_query(const stringstream& ss, int (*f)(void *, int, char **, char **), void* vp );

public:
    Dbhelper();
    void dropTable(QueryResult &vp);
    void createDatabase(QueryResult &vp);
    void insertBook(Book b,QueryResult &vp);
    void removeBook(Book b,QueryResult &vp);
    void fetchByIsdn(Book b,QueryResult &vp);
    void fetchAllBooks(QueryResult &vp);
    void countAllBooks(QueryResult &vp);
    void fetchById(int n, QueryResult& vp);

    ~Dbhelper();
};
