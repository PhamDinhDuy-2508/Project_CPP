#ifndef STACKCOLOR_H
#define STACKCOLOR_H

#include <QDialog>

namespace Ui {
class StackColor;
}

class StackColor : public QDialog
{
    Q_OBJECT

public:
    explicit StackColor(QWidget *parent = nullptr);
    ~StackColor();

private:
    Ui::StackColor *ui;
};

#endif // STACKCOLOR_H
