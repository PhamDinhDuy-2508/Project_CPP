#include "widget.h"
#include"test.h"
#include "ui_widget.h"
#include "QColorDialog"
#include "QSettings" /// same database
#include"QVariant"
#include"QtDebug"
#include"QDialog"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    for(int  i =0 ; i < 9 ; i ++ ) {
            colorList.append(Qt::black) ;
    }
    for ( int  i =0; i <  9 ; i++ ) {
    blackList.append(Qt::black) ;
    }
}
Widget::~Widget()
{
    delete ui;
}
void Widget::on_ButtonC1_clicked()
{
    QColor chossenColor = QColorDialog::getColor(colorList[0] , this , "choose Color") ;
    try {
        int ret = chossenColor.isValid() ;
        colorList[0] = chossenColor ;
        if(ret == 1 ) {

            QString _BColor = QString("background-color : %1").arg(chossenColor.name()) ;
            ui->ButtonC1->setStyleSheet(_BColor) ;
        }

    }
   catch (...){ }
}
void Widget::on_ButtonC9_clicked()
{
    QColor chossenColor = QColorDialog::getColor(colorList[8] , this , "choose Color") ;
    try {
         int ret = chossenColor.isValid() ;
         colorList[8] = chossenColor ;
         if(ret == 1 ) {
             QString _BColor = QString("background-color : %1").arg(chossenColor.name()) ;
             ui->ButtonC9->setStyleSheet(_BColor) ;
         }

    } catch (...) {
    }
}
void Widget::on_ButtonC2_clicked()
{
    QColor chosenColor  = QColorDialog::getColor(colorList[1] , this , "choose Color") ;
    try {
        int ret = chosenColor.isValid() ;
        colorList[1] = chosenColor ;
        if(ret == 1 ) {
            QString _BColor = QString("background-color : %1").arg(chosenColor.name()) ;

            ui->ButtonC2->setStyleSheet(_BColor) ;
        }
    } catch (...) {
    }
}
void Widget::on_ButtonC3_clicked()
{
    QColor chosenColor  = QColorDialog::getColor(colorList[2] , this , "choose Color") ;
    try {
        int ret = chosenColor.isValid() ;
        colorList[2] = chosenColor ;
        if(ret == 1 ) {
            QString _BColor = QString("background-color : %1").arg(chosenColor.name()) ;

            ui->ButtonC3->setStyleSheet(_BColor) ;
        }
    } catch (...) {
}
}

void Widget::on_ButtonC4_clicked()
{
    QColor chosenColor  = QColorDialog::getColor(colorList[3] , this , "choose Color") ;
    try {
        int ret = chosenColor.isValid() ;
        colorList[3] = chosenColor ;
        if(ret == 1 ) {
            QString _BColor = QString("background-color : %1").arg(chosenColor.name()) ;
            ui->ButtonC4->setStyleSheet(_BColor) ;
        }
    } catch (...) {
    }
}
void Widget::on_ButtonC6_clicked()
{
    QColor chosenColor  = QColorDialog::getColor(colorList[5] , this , "choose Color") ;
    try {
        int ret = chosenColor.isValid() ;
        colorList[5] = chosenColor ;
        if(ret == 1 ) {
            QString _BColor = QString("background-color : %1").arg(chosenColor.name()) ;

            ui->ButtonC6->setStyleSheet(_BColor) ;
        }
    } catch (...) {
    }

}
void Widget::on_ButtonC5_clicked()
{
    QColor chosenColor  = QColorDialog::getColor(colorList[4] , this , "choose Color") ;
    try {
        int ret = chosenColor.isValid() ;
        colorList[4] = chosenColor ;
        if(ret == 1 ) {
            QString _BColor = QString("background-color : %1").arg(chosenColor.name()) ;

            ui->ButtonC5->setStyleSheet(_BColor) ;
        }
    } catch (...) {
    }
}
void Widget::on_ButtonC7_clicked()
{
    QColor chosenColor  = QColorDialog::getColor(colorList[6] , this , "choose Color") ;

    try {
        int ret = chosenColor.isValid() ;
        colorList[6] = chosenColor ;
        if(ret == 1 ) {
            QString _BColor = QString("background-color : %1").arg(chosenColor.name()) ;

            ui->ButtonC7->setStyleSheet(_BColor) ;
        }
    } catch (...) {
    }
}
void Widget::on_ButtonC8_clicked()
{
    QColor chosenColor  = QColorDialog::getColor(colorList[7] , this , "choose Color") ;

    try {
        int ret = chosenColor.isValid() ;
        colorList[7] = chosenColor ;

        if(ret == 1 ) {
            QString _BColor = QString("background-color : %1").arg(chosenColor.name()) ;

            ui->ButtonC8->setStyleSheet(_BColor) ;
        }
    } catch (...) {
    }
}
void Widget::SaveData(QString key, QColor color)
{
 int red  = color.red() ;
 int blue = color.blue() ;
 int green = color.green() ;
 QSettings settings("Window" , "Application") ;
 settings.beginGroup("Color Application") ;
 settings.setValue(key+ "r", red) ;
 settings.setValue(key+ "b", blue) ;
 settings.setValue(key+ "g", green) ;
 settings.endGroup() ;
}

void Widget::resetData(QString key,int index ,QPushButton *button)
{
    QColor color = loadColor(key) ;
    blackList[index] = color ;
    QString _BColor = QString("background-color : %1").arg(color.name()) ;
    button->setStyleSheet(_BColor) ;
}

void Widget::SetLoadData(QString key, int index, QLabel *label)
{
    QColor color = loadColor(key) ;
    colorList[index] = color ;
    QString _BColor = QString("background-color : %1").arg(color.name()) ;
    label->setStyleSheet(_BColor) ;
}
QColor Widget::loadColor(QString k)
{
    int red ;
    int blue ;
    int green ;
    QSettings settings("Window" , "Application") ;
    settings.beginGroup("Color Application") ;
    red = settings.value(k+"r", QVariant(0)).toInt() ;
    blue = settings.value(k+"b" , QVariant(0)).toInt() ;
    green =  settings.value(k+"g" , QVariant(0)).toInt() ;
    settings.endGroup() ;
    return  QColor(red,green , blue) ;
}
void Widget::SetLoafData(QString key,  int index, QPushButton *button)
{
    QColor color =  loadColor(key) ;
    colorList[index]  = color  ;
    QString _BColor = QString("background-color : %1").arg(color.name()) ;
    button->setStyleSheet(_BColor) ;
    qDebug() << color.name() ;
}
void Widget::on_LoadButton_clicked()
{
    SetLoafData("Button1" , 0 , ui->ButtonC1) ;
    SetLoafData("Button2" , 1 , ui->ButtonC2) ;
    SetLoafData("Button3" , 2 , ui->ButtonC3) ;
    SetLoafData("Button4" , 3 , ui->ButtonC4) ;
    SetLoafData("Button5" , 4 , ui->ButtonC5) ;
    SetLoafData("Button6" , 5 , ui->ButtonC6) ;
    SetLoafData("Button7" , 6 , ui->ButtonC7) ;
    SetLoafData("Button8" , 7 , ui->ButtonC8) ;
    SetLoafData("Button9" , 8 , ui->ButtonC9) ;
}
void Widget::on_SaveButton_clicked()
{
    SaveData("Button1" ,colorList[0]) ;
    SaveData("Button2" ,colorList[1]) ;
    SaveData("Button3" ,colorList[2]) ;
    SaveData("Button4" ,colorList[3]) ;
    SaveData("Button5" ,colorList[4]) ;
    SaveData("Button6" ,colorList[5]) ;
    SaveData("Button7" ,colorList[6]) ;
    SaveData("Button8" ,colorList[7]) ;
    SaveData("Button9" ,colorList[8]) ;
    SaveData("label" , colorList[0]) ;
    SaveData("label_2" , colorList[1]) ;
    SaveData("label_3" , colorList[2]) ;
    SaveData("label_4" ,colorList[3]) ;
    SaveData("label_5" ,colorList[4]) ;
    SaveData("label_6" ,colorList[5]) ;
    SaveData("label_7" ,colorList[6]) ;
    SaveData("label_8" ,colorList[7]) ;
    SaveData("label_9" ,colorList[8]) ;


}
void Widget::on_pushButton_clicked()
{
        SaveData("Button1" ,blackList[0]) ;
        SaveData("Button2" ,blackList[1]) ;
        SaveData("Button3" ,blackList[2]) ;
        SaveData("Button4" ,blackList[3]) ;
        SaveData("Button5" ,blackList[4]) ;
        SaveData("Button6" ,blackList[5]) ;
        SaveData("Button7" ,blackList[6]) ;
        SaveData("Button8" ,blackList[7]) ;
        SaveData("Button9" ,blackList[8]) ;
        SetLoafData("Button1" , 0 , ui->ButtonC1) ;
        SetLoafData("Button2" , 1 , ui->ButtonC2) ;
        SetLoafData("Button3" , 2 , ui->ButtonC3) ;
        SetLoafData("Button4" , 3 , ui->ButtonC4) ;
        SetLoafData("Button5" , 4 , ui->ButtonC5) ;
        SetLoafData("Button6" , 5 , ui->ButtonC6) ;
        SetLoafData("Button7" , 6 , ui->ButtonC7) ;
        SetLoafData("Button8" , 7 , ui->ButtonC8) ;
        SetLoafData("Button9" , 8 , ui->ButtonC9) ;
}

void Widget::on_HasbeenButton_clicked()
{
    test*StackColor = new test(this) ;
    StackColor->exec() ;
}

QList<QColor> Widget::getColorList() const
{
    return colorList;
}
