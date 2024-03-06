
#include <iostream>
#include "book.hpp"

using namespace std;

Book::Book(){}

Book::Book(string isdn, string title, float price):isdn(isdn),title(title),price(price){
}

string Book::getIsdn()
{
    return isdn;
}

string Book::getTitle()
{
    return title;
}

string Book::getBackground()
{
    return background;
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

void Book::setBackground(const string& background)
{
    this->background = background;
}

void Book::setPrice(const float& price)
{
    this->price = price;
}

