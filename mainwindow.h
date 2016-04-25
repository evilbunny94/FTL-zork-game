#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QtGui>
#include <QtCore>
#include <room.h>
#include <vector>
#include "Items.h"
#include "Objective.h"
#include "inventory.h"
#include "endscreen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startGame();
    void setDifficulty(int);

private:
    Ui::MainWindow *ui;
    Room * all_rooms[16];
    Room *currentRoom;
    Inventory* myInventory;
    Objective * objectives[3];
    string textBoxString;
    int difficulty;
    int completeObjectives;
    void goRoom(string direction);
    void createRooms();
    void createObjectsAndObjectives();
    void addItemToRandomInv(Items* a);
    void checkWin();
    void checkObjective();


protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *);
private slots:
    void on_northButton_clicked();
    void on_eastButton_clicked();
    void on_southButton_clicked();
    void on_westButton_clicked();
    void on_roomInvOneButton_clicked();
    void on_roomInvTwoButton_clicked();
    void on_myInvOneButton_clicked();
    void on_myInvTwoButton_clicked();
    void on_roomInvOneHint_clicked();
    void on_roomInvTwoHint_clicked();
    void on_myInvOneHint_clicked();
    void on_myInvTwoHint_clicked();
};

#endif // MAINWINDOW_H
