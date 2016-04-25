#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <string>
#include <vector>
#include <QRectF>
#include "Items.h"
#include "inventory.h"
#include <iostream>
using namespace std;
using std::vector;
class Room
{
private:
    string description;
    map<string, Room*> exits;
    int squares[4][2];
    int numberOfSquares;

public:
    Inventory* roomInventory;
    Room(string description);
    void setExits(Room *north, Room *east,Room *south, Room *west);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    QRectF getRectSquare(int index);
    int getNumberOfSquares();
    void setSquares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    void setSquares(int x1, int y1, int x2, int y2, int x3, int y3);
    void setSquares(int x1, int y1, int x2, int y2);
    void deleteThis();

};

#endif // ROOM_H
