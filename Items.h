
#ifndef ITEMS_H
#define ITEMS_H
using namespace std;
#include <iostream>

// Base class
class Items
{
public:
    Items(string a, string b, string c);
    Items(string a, string b, string c, string d);
    string getName();
    string getDescription();
    string getImageFile();
    string getItemRequired();
    void helloWorld();
    void deleteThis();
private:
    string name;
    string description;
    string imageFile;
    string itemRequired;
};

#endif // ITEMS_H
