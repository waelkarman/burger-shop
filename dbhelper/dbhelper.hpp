#pragma once
#include <iostream>
#include "book.hpp"

using namespace std;

class Dbhelper {

public:

Dbhelper();
bool createDatabase();
bool insertBook(Book b);


private:



};