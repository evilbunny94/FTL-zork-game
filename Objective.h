#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include "Items.h"

#include <vector>
#include <string>
using namespace std;


class Objective
{

    friend bool &operator==(Objective &, Items &);
public:
    Objective();
    Objective(string desc);
    void addItems(Items *itemOne, Items *itemTwo);
    void setComplete(bool newComplete);
    bool getComplete();
    int isItem(string nameString);
    Items getItem(int index);
    string getDescription();
    void deleteThis();

private:
    string description;
    Items* ourItems[2];
    bool complete;
};

#endif // OBJECTIVE_H
