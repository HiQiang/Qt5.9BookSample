#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qperson.h"
#include <QMetaProperty>
#include <QMetaClassInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    QPerson *boy;
    QPerson *girl;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    void on_spin_valueChanged(int arg1);
    void on_ageChanged();

private slots:
    void on_btnBoyInc_clicked();
    void on_btnGirlInc_clicked();
    void on_btnClassInfo_clicked();
};
#endif // WIDGET_H
