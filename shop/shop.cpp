

#include <iostream>
#include "shop.hpp"

Shop::Shop(){}

Shop::Shop(int space){
    this->space = space;
}

bool Shop::add(Book b){
    Book m_book_a;
    m_book_a.setIsdn("qwertg1234");
    m_book_a.setTitle("Il piccolo principe");
    m_book_a.setPrice(55);
    cout << "Libro aggiunto." << endl;
    return true;
}

bool Shop::remove(Book b){

    cout << "Libro rimosso." << endl;
    return true;
}