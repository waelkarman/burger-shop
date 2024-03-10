#pragma once
#include <string>

using namespace std;

class Burger { 

public:
    Burger();
    Burger(string type, string name, float price, string background, string description);
    string getType() const;
    string getName() const;
    float getPrice() const;
    string getDescription() const;
    string getBackground() const;
    void setType(const string& type);
    void setName(const string& name);
    void setBackground(const string& background);
    void setPrice(const float& price);

private: 
    string type;
    string name;
    string background;
    string description;
    float price;

};
