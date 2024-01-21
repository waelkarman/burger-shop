
#include <iostream>
#include "book.hpp"

using std namespace;

class Shop {

public:
Shop();
Shop(int space);
bool add(Book b);
bool remove(Book b);

private:
string type = "autoresize";


};