#include "Room.h"

Room::Room(string description)
{
    this->description = description;

    roomInventory = new Inventory();

}



void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

string Room::shortDescription() {
    return description;
}

string Room::longDescription() {
    if (roomInventory->getNumberOfItems()==2) {
        return "So many items, what to talk about...";
    } else if (roomInventory->getNumberOfItems()==1) {
        return roomInventory->getItem(0)->getDescription();
    } else {
        return "...";
    }
}


Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}



QRectF Room::getRectSquare(int index) {
    return QRectF(squares[index][0],squares[index][1],12,12);
}

int Room::getNumberOfSquares() {
    return numberOfSquares;
}

void Room::setSquares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    numberOfSquares =4;
    squares[0][0]=x1;
    squares[0][1]=y1;
    squares[1][0]=x2;
    squares[1][1]=y2;
    squares[2][0]=x3;
    squares[2][1]=y3;
    squares[3][0]=x4;
    squares[3][1]=y4;

}
void Room::setSquares(int x1, int y1, int x2, int y2, int x3, int y3)
{
    numberOfSquares = 3;
    squares[0][0]=x1;
    squares[0][1]=y1;
    squares[1][0]=x2;
    squares[1][1]=y2;
    squares[2][0]=x3;
    squares[2][1]=y3;

}

void Room::setSquares(int x1, int y1, int x2, int y2)
{
    numberOfSquares = 2;
    squares[0][0]=x1;
    squares[0][1]=y1;
    squares[1][0]=x2;
    squares[1][1]=y2;
}


void Room::deleteThis()
{
    roomInventory->deleteThis();
    delete this;
}

