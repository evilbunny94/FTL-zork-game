#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QDialog>

namespace Ui {
class EndScreen;
}

class EndScreen : public QDialog
{
    Q_OBJECT

public:
    explicit EndScreen(QWidget *parent = 0);
    ~EndScreen();

private:
    Ui::EndScreen *ui;
};

#endif // ENDSCREEN_H
