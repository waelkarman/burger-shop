#pragma once
#include <iostream>
#include "book.hpp"
#include "dbhelper.hpp"

using namespace std;

class Shop {

public:
Shop();
bool insertISDN(const Book& b);
bool removeISDN(const string& isdn);
bool fetchAll();
bool fetchISDN(const string& isdn);

private:
Dbhelper db;

};