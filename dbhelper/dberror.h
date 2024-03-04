#pragma once
#include <exception>
#include <iostream>

using namespace std;

class dberror: public exception{
    string e;
public:
    dberror(string e):e(e){};

    what()
};

