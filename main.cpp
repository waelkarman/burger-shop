
#include <iostream>
#include "book.hpp"

int main(int argv, char** args){

    // Test Book class
    Book m_book_a;
    m_book_a.setIsdn("qwertg1234");
    m_book_a.setTitle("Il piccolo principe");
    m_book_a.setPrice(55);
    cout << "Funziona" << endl;


    return 0;
}