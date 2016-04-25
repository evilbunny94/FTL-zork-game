#include "Objective.h"

Objective::Objective(string desc)
{
    complete = false;
    description = desc;
}
Objective::Objective()
{
    complete = false;
    description = "Apparently you didn't do enough to get an objective text. Sucks to be you.";
}

void Objective::addItems(Items *itemOne, Items *itemTwo)
{
    ourItems[0] = itemOne;
    ourItems[1] = itemTwo;
}
void Objective::setComplete(bool newComplete)
{
    complete = newComplete;
}
bool Objective::getComplete()
{
    return complete;
}
int Objective::isItem(string nameString)
{
    if (nameString == ourItems[0]->getName()) {
        return 0;
    } else if (nameString == ourItems[1]->getName()) {
        return 1;
    } else {
        return -1;
    }
}
Items Objective::getItem(int index)
{
    return *ourItems[index];
}


//must pass a pointer to this
//don't presume that it's broken because I'm dumb again.
bool &operator==(Objective &obj, Items &item)
{
    bool toReturn = false;
    int flag = obj.isItem(item.getName());
    if (flag ==0 ||flag ==1) {
        toReturn = true;
    }
    return toReturn;
}


string Objective::getDescription()
{
    return description;
}

void Objective::deleteThis()
{
    delete this;
}
