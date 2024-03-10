
#include <iostream>
#include "burger.hpp"

using namespace std;

Burger::Burger(){}

Burger::Burger(string type, string name, float price, string background, string description):type(type),name(name),price(price),background(background),description(description){
}

string Burger::getType() const
{
    return type;
}

string Burger::getName() const
{
    return name;
}

string Burger::getBackground() const
{
    return background;
}

string Burger::getDescription() const
{
    return description;
}

float Burger::getPrice() const
{
    return price;
}

void Burger::setType(const string& type)
{
    this->type = type;
}

void Burger::setName(const string& name)
{
    this->name = name;
}

void Burger::setBackground(const string& background)
{
    this->background = background;
}

void Burger::setPrice(const float& price)
{
    this->price = price;
}

