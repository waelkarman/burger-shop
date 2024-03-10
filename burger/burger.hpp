#pragma once
#include <string>

using namespace std;

class Burger { 

public:
    Burger();
    Burger(string isdn,string title,float price,string background);
    string getIsdn() const;
    string getTitle() const;
    float getPrice() const;
    string getBackground() const;
    void setIsdn(const string& isdn);
    void setTitle(const string& title);
    void setBackground(const string& background);
    void setPrice(const float& price);

private: 
    string isdn;
    string title;
    string background;
    float price;

};
