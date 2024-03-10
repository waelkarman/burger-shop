#pragma once
#include <iostream>
#include <exception>

using namespace std;

class dberrors: public exception
{
    string e;
public:
    dberrors(string e):e(e){};

    virtual const char* what() const noexcept override 
    {
        return e.c_str();
    }
};
