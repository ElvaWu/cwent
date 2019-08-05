#include "box.h"

box::box(QWidget *parent):
    QGroupBox(parent)
{

}

void box::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        emit boxClicked();
    }
    QGroupBox::mousePressEvent(event);
}
