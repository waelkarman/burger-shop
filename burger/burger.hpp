#pragma once
#include <string>

using namespace std;

class Burger { 

public:
    Burger();
    Burger(string type, string title, float price, string background, string description);
    string getType() const;
    string getTitle() const;
    float getPrice() const;
    string getDescription() const;
    string getBackground() const;
    void setType(const string& type);
    void setTitle(const string& title);
    void setBackground(const string& background);
    void setPrice(const float& price);

private: 
    string type;
    string title;
    string background;
    string description;
    float price;

};
