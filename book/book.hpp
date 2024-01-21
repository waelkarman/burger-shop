
#include <iostream>

using namespace std;

class Book { 

public:
Book();
Book(string isdn,string title,float price);
string getIsdn();
string getTitle();
float getPrice();
void setIsdn(const string& isdn);
void setTitle(const string& title);
void setPrice(const float& price);

private: 
string isdn;
string title;
float price;

};