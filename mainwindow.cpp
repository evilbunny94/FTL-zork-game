#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startGame();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

       ui->mapLabel->clear();
       QImage tmp;
       tmp.load(":/ship.png");
       QPainter painter(&tmp);
       QPainterPath path;

       for (int i=0; i<16; i++) {
           if (currentRoom!=all_rooms[i]) {
                for (int j=0; j<all_rooms[i]->getNumberOfSquares();j++) {
                    path.addRoundedRect(all_rooms[i]->getRectSquare(j), 1, 1);
                    QPen pen(Qt::red, 10);
                    painter.setPen(pen);
                    painter.fillPath(path, Qt::red);
                    painter.drawPath(path);
                }
           }
       }

       QFont font = painter.font();
       font.setPointSize(20);
       painter.setFont(font);
       painter.setPen(Qt::yellow);
       painter.drawText(20,480, QString::fromStdString(textBoxString));

       if (myInventory->getFileNames()[0]) {
           QPixmap myPix(QString::fromStdString(myInventory->getItem(0)->getImageFile()));
           ui->myInvOneLabel->setPixmap(myPix);
       }
       ui->myInvOneButton->setVisible(myInventory->getFileNames()[0]);
       ui->myInvOneLabel->setVisible(myInventory->getFileNames()[0]);
       ui->myInvOneHint->setVisible(myInventory->getFileNames()[0]);

       if (myInventory->getFileNames()[1]) {
           QPixmap myPix(QString::fromStdString(myInventory->getItem(1)->getImageFile()));
           ui->myInvTwoLabel->setPixmap(myPix);
       }
       ui->myInvTwoButton->setVisible(myInventory->getFileNames()[1]);
       ui->myInvTwoLabel->setVisible(myInventory->getFileNames()[1]);
       ui->myInvTwoHint->setVisible(myInventory->getFileNames()[1]);

       if (currentRoom->roomInventory->getFileNames()[0]) {
           QPixmap myPix(QString::fromStdString(currentRoom->roomInventory->getItem(0)->getImageFile()));
           ui->roomInvOneLabel->setPixmap(myPix);
       }
       ui->roomInvOneButton->setVisible(currentRoom->roomInventory->getFileNames()[0]);
       ui->roomInvOneLabel->setVisible(currentRoom->roomInventory->getFileNames()[0]);
       ui->roomInvOneHint->setVisible(currentRoom->roomInventory->getFileNames()[0]);

       if (currentRoom->roomInventory->getFileNames()[1]) {
           QPixmap myPix(QString::fromStdString(currentRoom->roomInventory->getItem(1)->getImageFile()));
           ui->roomInvTwoLabel->setPixmap(myPix);
       }
       ui->roomInvTwoButton->setVisible(currentRoom->roomInventory->getFileNames()[1]);
       ui->roomInvTwoLabel->setVisible(currentRoom->roomInventory->getFileNames()[1]);
       ui->roomInvTwoHint->setVisible(currentRoom->roomInventory->getFileNames()[1]);

       ui->mapLabel->setPixmap(QPixmap::fromImage(tmp));

}

void MainWindow::on_northButton_clicked()
{
    goRoom("north");
}

void MainWindow::on_eastButton_clicked()
{
    goRoom("east");
}

void MainWindow::on_southButton_clicked()
{
    goRoom("south");
}

void MainWindow::on_westButton_clicked()
{
    goRoom("west");
}

void MainWindow::goRoom(string direction)
{
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "can't go there"<< endl;
    else {
        currentRoom = nextRoom;
        checkObjective();
        textBoxString = currentRoom->longDescription();
    }
}
void MainWindow::startGame()
{

    createRooms();

    createObjectsAndObjectives();

    myInventory = new Inventory();


    textBoxString = "Match the items to save the ship! Place pairs in a room together (top panel) to win!";





}

void MainWindow::checkObjective()
{
    for (int i =0; i< difficulty; i++) {
        if (currentRoom->roomInventory->getNumberOfItems()==2) {
            if (*objectives[i] == *currentRoom->roomInventory->getItem(0)
                    && *objectives[i] == *currentRoom->roomInventory->getItem(1)) {
                objectives[i]->setComplete(true);
                textBoxString = objectives[i]->getDescription();
                checkWin();
            }
        }
    }
}

void MainWindow::checkWin()
{
    bool toReturn = true;
    for (int i=0; i< difficulty; i++) {
        if (!objectives[i]->getComplete()) {
            toReturn = false;
        }
    }

    if (toReturn) {
        this->close();
        EndScreen end;
        end.setModal(true);
        end.exec();
    }
}

//room slot 1 to inv slot 1/2
void MainWindow::on_roomInvOneButton_clicked()
{

    if (myInventory->getNumberOfItems()!=2) {
        myInventory->addItem(myInventory->getNumberOfItems(), currentRoom->roomInventory->getItem(0));
        currentRoom->roomInventory->removeItem(0);
    }

}


void MainWindow::on_roomInvTwoButton_clicked()
{

    if (myInventory->getNumberOfItems()!=2) {
        myInventory->addItem(myInventory->getNumberOfItems(), currentRoom->roomInventory->getItem(1));
        currentRoom->roomInventory->removeItem(1);
    }

}
void MainWindow::on_myInvOneButton_clicked()
{

    if (currentRoom->roomInventory->getNumberOfItems()!=2) {
        currentRoom->roomInventory->addItem(currentRoom->roomInventory->getNumberOfItems(), myInventory->getItem(0));
        myInventory->removeItem(0);
    }
    checkObjective();

}
void MainWindow::on_myInvTwoButton_clicked()
{

    if (currentRoom->roomInventory->getNumberOfItems()!=2) {
        currentRoom->roomInventory->addItem(currentRoom->roomInventory->getNumberOfItems(), myInventory->getItem(1));
        myInventory->removeItem(1);
    }
    checkObjective();

}

void MainWindow::on_roomInvOneHint_clicked()
{
    textBoxString = currentRoom->roomInventory->getItem(0)->getDescription();
}

void MainWindow::on_roomInvTwoHint_clicked()
{
    textBoxString = currentRoom->roomInventory->getItem(1)->getDescription();
}

void MainWindow::on_myInvOneHint_clicked()
{
    textBoxString = myInventory->getItem(0)->getDescription();
}

void MainWindow::on_myInvTwoHint_clicked()
{
    textBoxString = myInventory->getItem(1)->getDescription();
}
void MainWindow::createRooms()
{
    Room *a, *b, *c, *d, *e, *f, *g, *h,
            *i, *j, *k, *l, *m, *n, *o, *p;
    a = new Room("a");
        a->setSquares(144,200,144,225);
    b = new Room("b");
        b->setSquares(169,199, 169, 225,190, 225,190,199);
    c = new Room("c");
        c->setSquares(170,175,193,175);
    d = new Room("d");
        d->setSquares(170,250,193,250);
    e = new Room("e");
        e->setSquares(220,175,242,178);
    f = new Room("f");
        f->setSquares(220,250,242,250);
    g = new Room("g");
        g->setSquares(242,202,242,225,265,202,265,225);
    h = new Room("h");
        h->setSquares(292,152,315,152);
    i = new Room("i");
        i->setSquares(292,178,292,202,315,178,315,202);
    j = new Room("j");
        j->setSquares(292,250,315,225,315,250);
    k = new Room("k");
        k->setSquares(292,275,315,275);
    l = new Room("l");
        l->setSquares(340,178,365,178,340,202,365,202);
    m = new Room("m");
        m->setSquares(340,250,340,225,365,250,365,225);
    n = new Room("n");
        n->setSquares(388,202,415,202);
    o = new Room("o");
        o->setSquares(440,202,463,202,440,225,463,225);
    p = new Room("p");
        p->setSquares(487,202,487,225);


//             (N, E, S, W)
    a->setExits(NULL, b, NULL, NULL);
    b->setExits(c, NULL, d, a);
    c->setExits(NULL, e, b, NULL);
    d->setExits(b, f, NULL, NULL);
    e->setExits(NULL, NULL, g, c);
    f->setExits(g, NULL, NULL, d);
    g->setExits(e, i, f, NULL);
    h->setExits(NULL, NULL, i, NULL);
    i->setExits(h, l, j, g);
    j->setExits(i, m, k, NULL);
    k->setExits(j, NULL, NULL, NULL);
    l->setExits(NULL, n, m, i);
    m->setExits(l, NULL, NULL, j);
    n->setExits(NULL, o, NULL, l);
    o->setExits(NULL, p, NULL, n);
    p->setExits(NULL, NULL, NULL, o);

    all_rooms[0] = a;
    all_rooms[1] = b;
    all_rooms[2] = c;
    all_rooms[3] = d;
    all_rooms[4] = e;
    all_rooms[5] = f;
    all_rooms[6] = g;
    all_rooms[7] = h;
    all_rooms[8] = i;
    all_rooms[9] = j;
    all_rooms[10] = k;
    all_rooms[11] = l;
    all_rooms[12] = m;
    all_rooms[13] = n;
    all_rooms[14] = o;
    all_rooms[15] = p;

    currentRoom = a;
}
void MainWindow::createObjectsAndObjectives()
{
    Items *a, *b, *c, *d, *e, *f;
    Objective *aa, *bb, *cc;

    a = new Items("Kebab", "Luckily you dont hate yourself enough to steal it", ":/kebab.png");
    b = new Items("Captain", "Can you get me a kebab?", ":/captain.png");
    c = new Items("Flower", "It fills you with joy", ":/flower.png");
    d = new Items("Engie", "I'm feeling sad", ":/engie.png");
    e = new Items("Key", "Red Key opens Red Door -- basic logic", ":/key.png");
    f = new Items("Officer",  "Where did I put that key...", ":/officer.png");

    aa = new Objective("Hunger no more!");
    bb = new Objective("Flowers always bring happiness.");
    cc = new Objective("That makes sense, I guess.");
    aa->addItems(a,b);
    bb->addItems(c,d);
    cc->addItems(e,f);

    objectives[0] = aa;
    objectives[1] = bb;
    objectives[2] = cc;


    addItemToRandomInv(a);
    addItemToRandomInv(b);
    if (difficulty>1) {
        addItemToRandomInv(c);
        addItemToRandomInv(d);
    }
    if (difficulty>2) {
        addItemToRandomInv(e);
        addItemToRandomInv(f);
    }


}


void MainWindow::addItemToRandomInv(Items * a)
{
    int number = rand() %16;
    bool finish = false;
    while (!finish) {
        if (all_rooms[number]->roomInventory->getNumberOfItems()==0) {
            all_rooms[number]->roomInventory->addItem(0,a);
            finish = true;
            cout << all_rooms[number]->shortDescription() << endl;
        } else {
            number = rand()%16;
        }

    }
}

void MainWindow::setDifficulty(int diff)
{
    difficulty = diff;
}


void MainWindow::closeEvent(QCloseEvent *)
{
    //delete everything
    for (int i=0; i<16; i++) {
        all_rooms[i]->deleteThis();
    }

    myInventory->deleteThis();

    for (int j=0; j<3; j++) {
        objectives[j]->deleteThis();
    }
}
