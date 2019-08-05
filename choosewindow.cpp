#include "ui_choosewindow.h"
#include "choosewindow.h"

chooseWindow::chooseWindow(QWidget *parent)
    :QMainWindow(parent), ui(new Ui::chooseWindow)
  {
      ui->setupUi(this);

      setWindowTitle("GWENT");
      setWindowState(Qt::WindowMaximized);

      initCard();

      QCommandLinkButton *finish=new QCommandLinkButton(this);
      finish->setGeometry(width(),height(),width()/2,height()/7);
      QFont font("Microsoft YaHei",30,75);
      finish->setFont(font);
      finish->setText("完   成");
      connect(finish,SIGNAL(clicked(bool)),this,SLOT(finish_clicked()));


 }

chooseWindow::~chooseWindow()
{
    delete ui;
}

void chooseWindow::initCard()
{
    cardSum=0,gold=0,silver=0,copper=0,leader=0;
    for(int i=0;i<CARD_NUM;i++)
    {
        canChoose[i]=1;
    }
    for(int i=0;i<CARD_TYPE;i++)
    {
        index[i]=0;
    }


    QWidget *widget = new QWidget(this);
    widget->resize(width(),height());
    this->setCentralWidget(widget);
    QGridLayout *gridLayout=new QGridLayout(this);
    widget->setLayout(gridLayout);

    QString name[CARD_NUM];
    QString filename[CARD_NUM];


   filename[0]=":/resource/po4xiao3.png";           name[0]="破\n晓";

   filename[1]=":/resource/ci4gu3bing1shuang1.png";name[1]="刺\n骨\n冰\n霜";
   filename[2]=":/resource/bi4ri4nong2wu4.png";    name[2]="蔽日\n浓雾";
   filename[3]=":/resource/qing1pen2da4yu3.png";   name[3]="倾盆\n大雨";
   filename[4]=":/resource/si1lie4.png";name[4]="撕裂";
   filename[5]=":/resource/xiao3wu4yao1.png";name[5]="小\n雾妖";
   filename[6]=":/resource/sai4er3yi1nuo4ying1shen1nv3yao1.png";name[6]="赛尔\n伊诺\n鹰\n身\n女\n妖";
   filename[7]=":/resource4/bao4nu4de1lang2.png";name[7]="暴\n怒\n的\n狼";
   filename[8]=":/resource/tu3yuan2su4.png";name[8]="土\n元素";
   filename[9]=":/resource2/da4shi1jiu4.png";name[9]="大\n狮鹫";
   filename[10]=":/resource2/da4shi1jiu4.png";name[10]="大\n狮鹫";
   filename[11]=":/resource2/kuang2lie4qi1shi4.png";name[11]="狂猎\n骑士";
   filename[12]=":/resource2/kuang2lie4qi1shi4.png";name[12]="狂猎\n骑士";
   filename[13]=":/resource3/xie4zhi1zhu1.png";name[13]="蟹\n蜘蛛";
   filename[14]=":/resource2/xi1yi1ren2zhan4shi4.png";name[14]="蜥蜴\n人战\n士";
   filename[15]=":/resource2/lei2ting2yao4shui3.png";name[15]="雷霆\n药水";

   filename[16]=":/resource3/zhi3hui3hao4jiao3.png";name[16]="指挥\n号角";
   filename[17]=":/resource4/bei4ke4er3de1niu3qu1zhi1jing4.png";name[17]="贝克\n尔的\n扭\n曲\n之\n境";
   filename[18]=":/resource2/lao3wu1yu4zhi1po2.png";name[18]="老\n巫\n妪：\n织\n婆";
   filename[19]=":/resource2/lao3wu1yu4zhu3po2.png";name[19]="老\n巫\n妪：\n煮\n婆";
   filename[20]=":/resource2/lao3wu1yu4ni2nan2po2.png";name[20]="老\n巫\n妪\n呢\n喃\n婆";
   filename[21]=":/resource2/wei4ju4zhe3.png";name[21]="畏惧\n者";
   filename[22]=":/resource2/luo2bo1.png";name[22]="萝卜";

   filename[23]=":/resource/jie2luo4te4yi1ge2ni2fa3yin4.png";name[23]="杰洛\n特：\n伊格\n尼\n法\n印";
   filename[24]=":/resource3/gai4er3.png";name[24]="盖尔";
   filename[25]=":/resource3/lin2yao1.png";name[25]="林妖";
   filename[26]=":/resource2/ka3lan2xi1er3.png";name[26]="卡兰\n希尔";

   filename[27]=":/resource3/da2gang1.png";name[27]="达冈";
   filename[28]=":/resource4/an4ying3zhang3zhe3.png";name[28]="暗影\n长者";


//加载卡牌
    card[0]=new Card(0,0,0,0,0,filename[0],name[0]);
    card[1]=new Card(1,1,0,1,0,filename[1],name[1]);
    card[2]=new Card(1,2,0,2,0,filename[2],name[2]);
    card[3]=new Card(1,3,0,3,0,filename[3],name[3]);
    card[4]=new Card(1,4,0,4,0,filename[4],name[4]);
    card[5]=new Card(0,5,4,5,0,filename[5],name[5]);
    card[6]=new Card(0,6,5,6,0,filename[6],name[6]);
    card[7]=new Card(0,7,1,7,0,filename[7],name[7]);
    card[8]=new Card(2,8,6,8,0,filename[8],name[8]);
    card[9]=new Card(0,9,8,9,0,filename[9],name[9]);
    card[10]=new Card(0,9,8,10,0,filename[10],name[10]);
    card[11]=new Card(0,10,8,11,0,filename[11],name[11]);
    card[12]=new Card(0,10,8,12,0,filename[12],name[12]);
    card[13]=new Card(3,11,3,13,0,filename[13],name[13]);
    card[14]=new Card(0,12,6,14,0,filename[14],name[14]);
    card[15]=new Card(0,13,0,15,0,filename[15],name[15]);
    card[16]=new Card(0,14,0,16,1,filename[16],name[16]);
    card[17]=new Card(0,15,0,17,1,filename[17],name[17]);
    card[18]=new Card(4,16,6,18,1,filename[18],name[18]);
    card[19]=new Card(4,17,8,19,1,filename[19],name[19]);
   card[20]=new Card(4,18,6,20,1,filename[20],name[20]);
   card[21]=new Card(1,19,12,21,1,filename[21],name[21]);
   card[22]=new Card(0,20,4,22,1,filename[22],name[22]);

   card[23]=new Card(0,21,5,23,2,filename[23],name[23]);
   card[24]=new Card(0,22,1,24,2,filename[24],name[24]);
   card[25]=new Card(0,23,5,25,2,filename[25],name[25]);
   card[26]=new Card(0,24,8,26,2,filename[26],name[26]);

   card[27]=new Card(0,25,6,27,3,filename[27],name[27]);
   card[28]=new Card(0,26,5,28,3,filename[28],name[28]);

   //card放到qgridwidget中
   int row=0;
   signalmapper=new QSignalMapper(this);

   for(int i=0;i<CARD_NUM;i++)
   {
   gridLayout->addWidget(card[i],row,i%10);
   connect(card[i],SIGNAL(clicked()),signalmapper,SLOT(map()));
   signalmapper->setMapping(card[i],i);
   if(i%10==9)
   {
       row++;
   }
   }

    connect(signalmapper,SIGNAL(mapped(int)),this,SLOT(cardClicked(int)) );
}

void chooseWindow::cardClicked(int a)
{
  if(card[a]->isChecked())
  {
  justify(a);

  if(! canChoose[a])
  {
  card[a]->setChecked(false);
  QMessageBox::warning(NULL, "warning", "不可选",QMessageBox::Yes);
  card[a]->setStyleSheet("QPushButton{border: 3px solid black;border- radius:8px}");
  }

  else
  {

  chosenCard.append(card[a]);
  cardSum++;
  card[a]->setStyleSheet("QPushButton{border: 3px solid red;border- radius:8px}");
  }

  }

  else
  {
      chosenCard.removeOne(card[a]);
      cardSum--;
      card[a]->setStyleSheet("QPushButton{border: 3px solid black;border- radius:8px}");
  }
}


void chooseWindow::justify(int a)//判断牌是否可选
{
    if(cardSum>40)
    {
      canChoose[a]=0;
      return;
    }

    if(card[a]->m_type==0)
    {
        if(index[card[a]->m_index]==3)
        {
        canChoose[a]=0;
        return;
        }
        copper++;
    }

    if(card[a]->m_type==1)
    {
        if(index[card[a]->m_index]==1)
        {
            canChoose[a]=0;
            return;
        }
        if(silver==6)
        {
            canChoose[a]=0;
            return;
        }
        silver++;
    }

    if(card[a]->m_type==2)
    {
        if(index[card[a]->m_index]==1)
        {
            canChoose[a]=0;
            return;
        }
        if(silver==4)
        {
            canChoose[a]=0;
            return;
        }
        gold++;
    }

    if(card[a]->m_type==3)
    {
        if(leader==1)
        {
            canChoose[a]=0;
            return;
        }
        leader++;
    }
    index[card[a]->m_index]++;

}

void chooseWindow::finish_clicked()
{
  if(cardSum<25||cardSum>40||leader==0)
        QMessageBox::warning(NULL, "warning", "选择有误，不能组成套牌",QMessageBox::Yes);
    else
    {
    for(int i=0;i<CARD_NUM;i++)
    {
        disconnect(card[i],SIGNAL(clicked()),signalmapper,SLOT(map()));
    }
        disconnect(signalmapper,SIGNAL(mapped(int)),this,SLOT(cardClicked(int)) );
        close();

        d.cardList=chosenCard;
        d.m_run();
        d.show();
    }

}
