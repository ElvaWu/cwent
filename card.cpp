#include "card.h"

#define CARD_WIDTH 100
#define CARD_HEIGHT 142

Card::Card(int location,int index,int strength,int num,int type,
           QString filename,QString name)
{
    m_location=location;
    m_num=num;
    m_strength=strength;
    m_isChosen=0;
    m_index=index;
    m_type=type;
    m_filename=filename;
    m_name=name;


    QIcon icon=QIcon(m_filename);
    setIcon(icon);
    setIconSize(QSize(CARD_WIDTH,CARD_HEIGHT));
    QFont font("Microsoft YaHei",10,75);
    setFont(font);
    setText(m_name);
    setCheckable(true);
    setStyleSheet("QPushButton{border: 3px solid black;border- radius:8px}");

}





