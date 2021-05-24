#include "_stackcolor.h"
#include "ui__stackcolor.h"

StackColor::StackColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StackColor)
{
    ui->setupUi(this);
}

StackColor::~StackColor()
{
    delete ui;
}
