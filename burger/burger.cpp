
#include <iostream>
#include "burger.hpp"

using namespace std;

Burger::Burger(){}

Burger::Burger(string isdn, string title, float price):isdn(isdn),title(title),price(price){
}

string Burger::getIsdn()
{
    return isdn;
}

string Burger::getTitle()
{
    return title;
}

string Burger::getBackground()
{
    return background;
}

float Burger::getPrice()
{
    return price;
}

void Burger::setIsdn(const string& isdn)
{
    this->isdn = isdn;
}

void Burger::setTitle(const string& title)
{
    this->title = title;
}

void Burger::setBackground(const string& background)
{
    this->background = background;
}

void Burger::setPrice(const float& price)
{
    this->price = price;
}

