
#include <iostream>
#include "book.hpp"
#include "shop.hpp"

using namespace std;

int main(int argv, char** args){

    // Test Book class
    Book m_book_a;
    m_book_a.setIsdn("987255324");
    m_book_a.setTitle("Il piccolo principe.");
    m_book_a.setPrice(55);

    // Test Shop and Dbhelper class
    Shop m_shop;
    m_shop.insertISDN(m_book_a);
    m_shop.fetchISDN("987255324");
    m_shop.fetchAll();
    m_shop.removeISDN("974568324");
    m_shop.removeISDN("987589657");
    

    return 0;
}