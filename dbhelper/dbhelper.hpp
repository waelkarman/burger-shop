#pragma once
#include <sstream>
#include <vector>
#include "sqlite3.h"

using namespace std;

struct Record 
{
    std::vector<std::string> columns;
};

struct QueryResult 
{
    std::vector<Record> records;
};

int default_callback(void *NotUsed, int argc, char **argv, char **azColName);


class Dbhelper 
{
    int rc;
    sqlite3 *db;

public:
    Dbhelper();
    void execute_query(const stringstream& ss, void* vp = nullptr, int (*f)(void *, int, char **, char **) = default_callback);

    ~Dbhelper();
};
