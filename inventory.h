#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include <vector>
#include "Items.h"
using namespace std;

class Inventory
{
private:
    Items* ourItems[2];
    int numberOfItems;
public:
    Inventory();
    void addItem(int index, Items *);
    Items* getItem(int index);
    int getNumberOfItems();
    void removeItem(int index);
    bool* getFileNames();
    void deleteThis();


};

#endif // INVENTORY_H
