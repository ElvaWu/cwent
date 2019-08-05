#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include "choosewindow.h"
#include "mainwindow.h"


namespace Ui {
class startWindow;
}

class startWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit startWindow(QWidget *parent = 0);
    ~startWindow();

protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_chooseButton_clicked();

private:
    Ui::startWindow *ui;
    chooseWindow c;

};

#endif // STARTWINDOW_H
