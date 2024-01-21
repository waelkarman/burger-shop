
#include <iostream>
#include "book.hpp"
#pragma once

using namespace std;

class Shop {

public:
Shop();
Shop(int space);
bool add(Book b);
bool remove(Book b);

private:
string type = "autoresize";
int space;

};