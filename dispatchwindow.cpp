#include "dispatchwindow.h"
#include "mainwindow.h"
#define CARD_WIDTH 100
#define CARD_HEIGHT 142


dispatchWindow::dispatchWindow(QWidget *parent,int round):
    QMainWindow(parent)
{
    setWindowState(Qt::WindowMaximized);
    m_round=round;
}

void dispatchWindow::finish_clicked()
{
    if(R1draw.isEmpty())
    {
    m_run();
    }
    int n=0;
    if(m_round==1)
    {
    n=10;
    }
     for(int i=0;i<n;i++)
    {
      disconnect(R1draw[i],SIGNAL(clicked()),signalmapper,SLOT(map()));
    }

    disconnect(signalmapper,SIGNAL(mapped(int)),this,SLOT(cardClickedR1(int)));
    delete signalmapper;
    m.m_list=R1draw;
    m.Initcards();
    hide();
    m.show();
}

void dispatchWindow::m_run()
{
    if(m_round==1&& !cardList.isEmpty())
    {
        R1draw=drawCards(cardList,10);
        showCards(R1draw);
    }
}

dispatchWindow::~dispatchWindow()
{
}

void dispatchWindow::showCards(QList<Card*> list)
{
    QWidget *widget = new QWidget(this);
    this->setCentralWidget(widget);
    layout=new QGridLayout(this);
    widget->setLayout(layout);

    signalmapper=new QSignalMapper;
    int n=list.size();

    int row=0;
    for(int i=0;i<n;i++)
    {
        R1draw.append(list[i]);
        layout->addWidget(R1draw.at(i),row,i%5);
        if(i==4)
        {
            row++;
        }
        R1draw[i]->setStyleSheet("QPushButton{border: 3px solid black;border- radius:8px}");
        connect(R1draw[i],SIGNAL(clicked()),signalmapper,SLOT(map()));
        signalmapper->setMapping(R1draw[i],i);
    }
    connect(signalmapper,SIGNAL(mapped(int)),this,SLOT(cardClickedR1(int)) );

    QPushButton* finish=new QPushButton(this);
    QFont font("Microsoft YaHei",18,75);
    finish->setFont(font);
    finish->setText("完成");
    layout->addWidget(finish,2,3);
    connect(finish,SIGNAL(clicked()),this,SLOT(finish_clicked()));
}

void dispatchWindow::cardClickedR1(int n)
{
    static int num=0;
    if(num<3)
    {
    int m=R1left.size();
    QTime time= QTime::currentTime();
    qsrand(time.msec()*qrand()*qrand()*qrand()*qrand()*qrand()*qrand());
    int randn= qrand()% m;


    QIcon icon=QIcon(R1left[randn]->m_filename);
    R1draw[n]->setIcon(icon);
    R1draw[n]->setIconSize(QSize(CARD_WIDTH,CARD_HEIGHT));
    R1draw[n]->setText(R1left.at(randn)->m_name);

    R1draw.replace(n,R1left.at(randn));
    R1left.removeOne(R1left.at(randn));

    num++;
    }
}

void dispatchWindow::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap *background=new QPixmap;
    QString  bgname=":/resource2/bg3.jpg";
    background->load(bgname);
    QPixmap n_background=background->scaled(width(),height());
    painter->drawPixmap(0,0,width(),height(),n_background);
    delete painter;
}

QList<int> dispatchWindow::randNum(int startNum,int finalNum)
{
    int   i=0, j=0;
    QList<int> intList;
    QTime time;
    for(i=0;;)
    {
        int  randn;
        time= QTime::currentTime();
        qsrand(time.msec()*qrand()*qrand()*qrand()*qrand()*qrand()*qrand());
        randn= qrand()%startNum;

        j=0;
        while(j<i && intList.at(j)!=randn)
        {
            j++;
        }

        if(j==i)
        {
            intList.append(randn);
            i++;
        }
        else if(i==finalNum)    break;
        else                continue;
    }
    return intList;
}

QList<Card*> dispatchWindow::drawCards(QList<Card*> list1,int cardNum)
{

    int list1_size=list1.size();
    QList<int> numList=randNum(list1_size,cardNum);
    QList<Card*> list2;
    R1left=list1;
    for(int i=0;i<cardNum;i++)
    {
    list2.append(list1.at (numList.at(i)) );
    R1left.removeOne(list1.at (numList.at(i)));
    }

    return list2;
}
