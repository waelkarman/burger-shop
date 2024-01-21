
#include <iostream>
#include "book.hpp"

using namespace std;

Book::Book(){}

Book::Book(string isdn, string title, float price){
    this->isdn=isdn;
    this->title=title;
    this->price=price;
}

string Book::getIsdn()
{
    return isdn;
}

string Book::getTitle()
{
    return title;
}

float Book::getPrice()
{
    return price;
}

void Book::setIsdn(const string& isdn)
{
    this->isdn = isdn;
}

void Book::setTitle(const string& title)
{
    this->title = title;
}

void Book::setPrice(const float& price)
{
    this->price = price;
}

