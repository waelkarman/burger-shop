
#include <iostream>
#include "book.hpp"
#include "shop.hpp"

using namespace std;

int main(int argv, char** args){

    // Test Book class
    Book m_book_a;
    m_book_a.setIsdn("qwertg1234");
    m_book_a.setTitle("Il piccolo principe");
    m_book_a.setPrice(55);
    cout << "Funziona" << endl;

    Shop m_shop;
    m_shop.add(m_book_a);


    return 0;
}