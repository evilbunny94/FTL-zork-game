#include "inventory.h"

Inventory::Inventory()
{
    numberOfItems =0;
}


void Inventory::addItem(int index, Items *inItem)
{
    ourItems[index] = inItem;
    if (numberOfItems ==0) {
        numberOfItems =1;
    } else if (numberOfItems ==1) {
        numberOfItems=2;
    }
}

Items* Inventory::getItem(int index)
{
    return ourItems[index];
}

int Inventory::getNumberOfItems()
{
    return numberOfItems;
}

void Inventory::removeItem(int index)
{
    if (numberOfItems==2) {
        if (index==0) {
            ourItems[0] = ourItems[1];
            ourItems[1] = NULL;
        } else if (index==1) {
            ourItems[1] = NULL;
        }
    } else if (index==0) {
        ourItems[0] = NULL;
    }
    numberOfItems--;
}


bool* Inventory::getFileNames()
{
    bool toReturn[2];
    if (numberOfItems==2) {
        toReturn[0] = true;
        toReturn[1] = true;
    } else if (numberOfItems == 1) {
        toReturn[0] = true;
        toReturn[1] = false;
    } else {
        toReturn[0] = false;
        toReturn[1] = false;
    }

    return toReturn;
}

void Inventory::deleteThis()
{
    if (numberOfItems ==2) {
        ourItems[0]->deleteThis();
        ourItems[1]->deleteThis();
    } else if (numberOfItems==1) {
        ourItems[0]->deleteThis();
    }

    delete this;
}

