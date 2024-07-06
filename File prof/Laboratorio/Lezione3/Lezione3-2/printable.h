#ifndef PRINTABLE_H
#define PRINTABLE_H
#include <iostream>

using namespace std;

class Printable
{
  public:
    virtual string getLabel() const = 0;
};

#endif