#pragma once
#include "burger.hpp"
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
    void insertBurger(Burger b,QueryResult &vp);
    void removeBurger(Burger b,QueryResult &vp);
    void fetchByIsdn(Burger b,QueryResult &vp);
    void fetchAllBurgers(QueryResult &vp);
    void countAllBurgers(QueryResult &vp);
    void fetchById(int n, QueryResult& vp);

    ~Dbhelper();
};
