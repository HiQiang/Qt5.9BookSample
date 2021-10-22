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

void Widget::colorCheanged()
{
    QPalette pal = ui->textEdit_2->palette();
    QColor color;
    color.setRgb(ui->SliderRed_2->value(),ui->SliderGreen_2->value(),ui->SliderBlue_2->value(),ui->SliderAlpha_2->value());
    pal.setColor(QPalette::Base,color);
    ui->textEdit_2->setPalette(pal);
}



void Widget::on_SliderRed_2_valueChanged(int value)
{
    Q_UNUSED(value)
    colorCheanged();
}

void Widget::on_SliderGreen_2_valueChanged(int value)
{
    Q_UNUSED(value)
    colorCheanged();
}

void Widget::on_SliderBlue_2_valueChanged(int value)
{
    Q_UNUSED(value)
    colorCheanged();
}

void Widget::on_SliderAlpha_2_valueChanged(int value)
{
    Q_UNUSED(value)
    colorCheanged();
}

void Widget::on_SliderH_2_valueChanged(int value)
{
    ui->progBarH_2->setValue(value);
    ui->ScrollBarH_2->setValue(value);
}

void Widget::on_dial_2_valueChanged(int value)
{
    ui->LCDDisplay_2->display(value);
}

void Widget::on_radioBtnHex_2_clicked()
{
    ui->LCDDisplay_2->setHexMode();
}
