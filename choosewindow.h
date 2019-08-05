#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H
//选择牌组窗口

#define CARD_NUM 29
#define CARD_TYPE 27
#define CARD_WIDTH 100
#define CARD_HEIGHT 142
#define COPPER 16
#define SILVER 7
#define GOLD 4
#define LEADER 2

#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QPushButton>
#include <QPaintEvent>
#include <QIcon>
#include <QColor>
#include <QGridLayout>
#include <QSize>
#include <QStringBuilder>
#include <QSignalMapper>
#include <QMessageBox>
#include <QCommandLinkButton>
#include <QList>
#include "dispatchwindow.h"
#include "card.h"


namespace Ui {
class chooseWindow;
}

class chooseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit chooseWindow(QWidget *parent = 0);
    ~chooseWindow();

    int cardSum;
    int copper;
    int silver;
    int gold;
    int leader;
    int index[CARD_TYPE+5];
    Card *card[CARD_NUM];//可选择的牌
protected:
    QSignalMapper *signalmapper;
    QList<Card*> chosenCard;//选的套牌
    bool canChoose[CARD_NUM];//某张牌是否可选

    void justify(int a);//判断某张牌是否可选

private:
    Ui::chooseWindow *ui;
    dispatchWindow d;
    void initCard();

private slots:
    void cardClicked(int a);
    void finish_clicked();
};

#endif // CHOOSEWINDOW_H
