#pragma once
#include <iostream>
#include "book.hpp"

using namespace std;

class Dbhelper {

public:

Dbhelper();
bool createDatabase();
bool insertISDN(Book b);
bool removeISDN(string isdn);
int fetchISDN(string isdn);
int fetchAll();

private:

};