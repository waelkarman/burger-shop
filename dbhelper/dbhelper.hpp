#pragma once
#include "book.hpp"

using namespace std;

class Dbhelper {

public:

    Dbhelper();
    bool dropTable();
    bool createDatabase();
    bool insertISDN(Book b);
    bool removeISDN(string isdn);
    char* fetchNum(int n) const;
    int fetchAll();
    int countAll() const;

private:


};
