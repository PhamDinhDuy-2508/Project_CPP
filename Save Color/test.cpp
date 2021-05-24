#include "test.h"
#include "ui_test.h"
#include"widget.h"
#include"QDebug"
test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    Widget*k  = new Widget() ;
    k->SetLoadData("label",0,ui->label) ;
    k->SetLoadData("label_2",1,ui->label_2) ;
    k->SetLoadData("label_3",2,ui->label_3) ;
    k->SetLoadData("label_4",3,ui->label_4) ;
    k->SetLoadData("label_5",4,ui->label_5) ;
    k->SetLoadData("label_6",5,ui->label_6) ;
    k->SetLoadData("label_7",6,ui->label_7) ;
    k->SetLoadData("label_8",7,ui->label_8) ;
    k->SetLoadData("label_9",8,ui->label_9) ;

}

test::~test()
{
    delete ui;
}
