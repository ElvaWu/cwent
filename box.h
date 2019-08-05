#ifndef BOX_H
#define BOX_H
#include <QGroupBox>
#include <QMouseEvent>

//qgroupbox添加单击信号
class box:public QGroupBox
{
    Q_OBJECT
public:
    explicit box(QWidget *parent = 0);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
signals:
    void boxClicked();
public slots:

};
#endif // BOX_H
