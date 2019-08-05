#ifndef DISPATCHWINDOW_H
#define DISPATCHWINDOW_H
//调度窗口

#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <QList>
#include <QTime>
#include <QGridLayout>
#include <QCommandLinkButton>
#include <QSignalMapper>
#include <QIcon>
#include "card.h"
#include "mainwindow.h"


class Mainawindow;

class dispatchWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit dispatchWindow(QWidget *parent=0,int round=1);
    ~dispatchWindow();


    int m_round;
    int cardNum[3];//每局之前能调度的牌数
    QList<Card*> cardList;//选的套牌
    QList<Card*> R1left;//第一局调度完剩下的
    QList<Card*> R2left;//第二句调度完剩下的

    QList<Card*> R1draw;//第一局抽到的十张
    void m_run();
protected:
    MainWindow m;
    QGridLayout *layout;
    QSignalMapper *signalmapper;
    void paintEvent(QPaintEvent *);
    QList<int> randNum(int startNum,int finalNum);//从startNum中产生finalNum个随机数
    QList<Card*> drawCards(QList<Card*> list1,int cardNum);//抽牌，保存剩下的牌
    void showCards(QList<Card*> list);

private slots:
    void cardClickedR1(int n);
    void finish_clicked();
};

#endif // DISPATCHWINDOW_H
