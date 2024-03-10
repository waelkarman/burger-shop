
#include <iostream>
#include "burger.hpp"

using namespace std;

Burger::Burger(){}

Burger::Burger(string isdn, string title, float price,string background):isdn(isdn),title(title),price(price),background(background){
}

string Burger::getIsdn() const
{
    return isdn;
}

string Burger::getTitle() const
{
    return title;
}

string Burger::getBackground() const
{
    return background;
}

float Burger::getPrice() const
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

