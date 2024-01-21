#pragma once
#include <iostream>
#include "book.hpp"
#include "dbhelper.hpp"

using namespace std;

class Shop {

public:
Shop();
bool add(const Book& b);
bool remove(string isdn);

private:
Dbhelper db;

};