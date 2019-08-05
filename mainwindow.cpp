#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "dispatchwindow.h"
#include "showpoints.h"

#define CARD_WIDTH 80
#define CARD_HEIGHT 100

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowState(Qt::WindowMaximized);
    focus=0;
    signalmapper2=new QSignalMapper(this);
    for(int i=0;i<6;i++)
    {
       layout[i]=new QHBoxLayout(this);
       row[i]=new box(this);
       row[i]->setGeometry(CARD_WIDTH*4,CARD_HEIGHT*i,CARD_WIDTH*10,CARD_HEIGHT);
       connect(row[i],SIGNAL(boxClicked()),signalmapper2,SLOT(map()));
       signalmapper2->setMapping(row[i],i);
       row[i]->setLayout(layout[i]);
    }
    connect(signalmapper2,SIGNAL(mapped(int)),this,SLOT(rowClicked(int)) );

    point=0;

    w=new QWidget(this);
    w->setGeometry(QRect(CARD_WIDTH,CARD_HEIGHT,CARD_WIDTH*5,CARD_HEIGHT));

    QFont font("Microsoft YaHei",10,75);
    button=new QPushButton(this);
    button->setFont(font);
    button->setText("放弃跟牌");

    label=new QLabel(this);
    label->setFont(font);
    label->setText("0");

    layout1.addWidget(label);
    layout1.addWidget(button);
    w->setLayout(&layout1);


    connect(button,SIGNAL(clicked()),this,SLOT(drop()));
}

void MainWindow::rowClicked(int a)
{
    if(m_list.at(focus)->m_location==0 && a>2&&a<6)
    {
        hLayout->removeWidget(m_list.at(focus));
        layout[a]->addWidget(m_list.at(focus));
    }

    if(m_list.at(focus)->m_location==1 && a>-1 && a<3)
    {
        hLayout->removeWidget(m_list.at(focus));
        layout[a]->addWidget(m_list.at(focus));
    }
     row[a]->setLayout(layout[a]);
     point+=m_list.at(a)->m_strength;
     m_list.removeAt(a);
     QString s=QString::number(point);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drop()
{
    dispatchWindow *d2=new dispatchWindow(0,2);
    showPoints s;
    s.m_points=point;
    s.showpoints();
    hide();
    s.show();
}

void MainWindow::Initcards()
{
    widget = new QWidget(this);
    widget->setGeometry(CARD_WIDTH*3,CARD_HEIGHT*6,CARD_WIDTH*20,CARD_HEIGHT);

    hLayout=new QHBoxLayout(this);

    signalmapper=new QSignalMapper;
    for(int i=0;i< m_list.size(); i++)
    {
      m_list[i]->setIconSize(QSize(CARD_WIDTH,CARD_HEIGHT));
      m_list[i]->resize(QSize(CARD_WIDTH,CARD_HEIGHT));
      m_list[i]->setStyleSheet("QPushButton{border: 3px solid black;border- radius:8px}");

      hLayout->addWidget(m_list.at(i));

      connect(m_list.at(i),SIGNAL(clicked()),signalmapper,SLOT(map()));
      signalmapper->setMapping(m_list[i],i);
    }

    widget->setLayout(hLayout);
    connect(signalmapper,SIGNAL(mapped(int)),this,SLOT(dClicked(int)) );
}


void MainWindow::dClicked(int a)
{
    focus=a;
    switch(m_list.at(a)->m_location)
    {
    case 2:
    {
        hLayout->removeWidget(m_list.at(a));
        layout[3]->addWidget(m_list.at(a));
        point+=m_list.at(a)->m_strength;
        m_list.removeAt(a);
    }
        break;
    case 3:
    {
        hLayout->removeWidget(m_list.at(a));
        layout[4]->addWidget(m_list.at(a));
        point+=m_list.at(a)->m_strength;
        m_list.removeAt(a);
    }
        break;
    case 4:
    {
        hLayout->removeWidget(m_list.at(a));
        layout[5]->addWidget(m_list.at(a));
        point+=m_list.at(a)->m_strength;
        m_list.removeAt(a);
    }
        break;
    default:
        return;
    }
     row[a]->setLayout(layout[a]);
     QString s=QString::number(point);

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap *background=new QPixmap;
    QString  bgname=":/resource4/battle.png";
    background->load(bgname);
    QPixmap n_background=background->scaled(width(),height());
    painter->drawPixmap(0,0,width(),height(),n_background);
    delete painter;
}




