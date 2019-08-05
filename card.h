#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QIcon>
#include <QFont>
#include <QList>
#include <QVector>
#include <QLabel>

class Card : public QPushButton
{

public:
    Card(int location,int index,int strength,int num,int type,
         QString filename,QString name);


    int m_location;
    int m_strength;
    bool m_isChosen;
    int m_type;
    int m_index;//同名牌m_index相同
    int m_num;
    QString m_filename;
    QString m_name;
    QString m_skills;
};

CARD_H

#endif //
