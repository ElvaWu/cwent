#include "showpoints.h"

showPoints::showPoints(QWidget *parent)
    : QMainWindow(parent)
{

}

void showPoints::showpoints()
{
    QString s=QString::number(m_points);
    label=new QLabel(this);
    QFont font("Microsoft YaHei",10,75);
    label->setFont(font);
    label->setText(s);
}

void showPoints::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap *background=new QPixmap;
    QString  bg1name=":/resource3/bg1.jpg";
    background->load(bg1name);
    QPixmap n_background=background->scaled(width(),height());
    painter->drawPixmap(0,0,width(),height(),n_background);
    delete painter;
}
