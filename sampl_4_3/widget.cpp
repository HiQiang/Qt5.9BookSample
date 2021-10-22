#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCal_2_clicked()
{
    int num = ui->spinNum_2->value();
    double price = ui->spinPrice_2->value();
    ui->spinTotal_2->setValue(num * price);

}

void Widget::on_spinNum_2_valueChanged(int arg1)
{
    double price = ui->spinPrice_2->value();
    ui->spinTotal_2->setValue(arg1 * price);
}

void Widget::on_btnDec_2_clicked()
{
    int value = ui->spinDec_2->value();
    ui->spinBin_2->setValue(value);
    ui->spinHex_2->setValue(value);
}
