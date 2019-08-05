#ifndef SHOWPOINTS_H
#define SHOWPOINTS_H

#include <QString>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>

class showPoints : public QMainWindow
{
    Q_OBJECT
public:
    explicit showPoints(QWidget *parent = 0);
    ~showPoints(){}
    int m_points;
    void showpoints();
protected:
    QLabel *label;
    void paintEvent(QPaintEvent *);
};
#endif // SHOWPOINTS_H
