#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QList>
#include <QHBoxLayout>
#include <QSize>
#include <QSpacerItem>
#include <QRect>
#include <QSignalMapper>
#include <QEvent>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include "card.h"
#include "box.h"

class showPoints;
class dispatchWindow;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public:
    int focus;
    QList<Card*> m_list;
    void Initcards();
protected:
    int point;
    QWidget *w;
    QWidget *widget;
    QLabel *label;
    box *row[6];
    QPushButton *button;
    QHBoxLayout layout1;
    QHBoxLayout *hLayout;
    QHBoxLayout *layout[6];//场上每一行的布局
    QSignalMapper *signalmapper;
    QSignalMapper *signalmapper2;

    void paintEvent(QPaintEvent *);

protected slots:
    void dClicked(int);//单击未出手的牌
    void rowClicked(int);//单击场上的某一行
    void drop();

private:
    Ui::MainWindow *ui;

};



#endif // MAINWINDOW_H
