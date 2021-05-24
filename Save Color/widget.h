#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QColor>
#include"QList"
#include"QPushButton"
#include"QLabel"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QList<QColor> getColorList() const;
    QList<QColor>colorList  ;
    QString k ;
    QList<QColor> blackList ;
    QColor loadColor(QString k ) ;
    void SetLoafData(QString key , int index , QPushButton*button ) ;
    void SaveData(QString key   ,QColor color)  ;
    void resetData(QString key ,int index  , QPushButton *button ) ;
    void SetLoadData(QString key , int index , QLabel*label );

private slots:
    void on_ButtonC1_clicked();

    void on_ButtonC9_clicked();

    void on_ButtonC2_clicked();

    void on_ButtonC3_clicked();

    void on_ButtonC4_clicked();

    void on_ButtonC6_clicked();

    void on_ButtonC5_clicked();

    void on_ButtonC7_clicked();

    void on_ButtonC8_clicked();

    void on_LoadButton_clicked();

    void on_SaveButton_clicked();

    void on_pushButton_clicked();

    void on_HasbeenButton_clicked();

private:
    Ui::Widget *ui;

};
#endif // WIDGET_H ;
