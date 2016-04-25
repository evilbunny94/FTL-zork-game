#include "endscreen.h"
#include "ui_endscreen.h"

EndScreen::EndScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndScreen)
{
    ui->setupUi(this);
    QPixmap myPix (":/winScreen.png");
    ui->label->setPixmap(myPix);
}

EndScreen::~EndScreen()
{
    delete ui;
}
