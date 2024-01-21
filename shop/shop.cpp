#include <iostream>
#include "shop.hpp"
#include "dbhelper.hpp"


Shop::Shop(){
    db.createDatabase();
}

bool Shop::add(const Book& b){
    db.insertBook(b);
    cout << "Libro aggiunto." << endl;
    return true;
}

bool Shop::remove(string isdn){
    db.removeISDN(isdn);
    cout << "Libro rimosso." << endl;
    return true;
}