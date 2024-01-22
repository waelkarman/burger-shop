#include <iostream>
#include "shop.hpp"
#include "dbhelper.hpp"


Shop::Shop(){
    db.createDatabase();
}

bool Shop::insertISDN(const Book& b){
    db.insertISDN(b);
    return true;
}

bool Shop::removeISDN(const string& isdn){
    db.removeISDN(isdn);
    return true;
}

bool Shop::fetchAll(){
    db.fetchAll();
    return true;
}

bool Shop::fetchISDN(const string& isdn){
    db.fetchISDN(isdn);
    return true;
}