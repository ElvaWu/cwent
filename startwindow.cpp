#include "startwindow.h"
#include "ui_startwindow.h"

startWindow::startWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::startWindow)
{
    ui->setupUi(this);

    setWindowTitle("GWENT");
    setWindowState(Qt::WindowMaximized);

    ui->chooseButton->setStyleSheet("QPushButton#chooseButton { background-color:rgb(8,89,83)}");
}

startWindow::~startWindow()
{
    delete ui;
}

void startWindow::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap *background=new QPixmap;
    QString  bg1name=":/resource3/bg1.jpg";
    background->load(bg1name);
    QPixmap n_background=background->scaled(width(),height());
    painter->drawPixmap(0,0,width(),height(),n_background);
    delete painter;
}

void startWindow::on_chooseButton_clicked()
{
    hide();
    c.show();
}
