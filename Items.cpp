

#include "items.h"
#include <iostream>
using namespace std;

Items::Items(string a, string b, string c)
{
     name = a;
     description =b;
     imageFile =c;

}

Items::Items(string a, string b, string c, string d)
{

     name = a;
     description =b;
     imageFile =c;
     itemRequired = d;
}

string Items::getDescription()
{
    return description;

}

string Items::getName()
{
    return name;

}

string Items::getImageFile()
{
    return imageFile;

}

string Items::getItemRequired()
{
    return itemRequired;

}

void Items::deleteThis()
{
    delete this;
}
