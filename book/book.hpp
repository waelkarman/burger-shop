#pragma once
#include <iostream>

using namespace std;

class Book { 

public:
    Book();
    Book(string isdn,string title,float price);
    string getIsdn();
    string getTitle();
    float getPrice();
    string getBackground();
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
