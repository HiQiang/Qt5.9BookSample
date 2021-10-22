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


void Widget::on_pushButton_29_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();
    ui->edtResult_2->setText(str1.append(str2));

}

void Widget::on_pushButton_19_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    ui->spinBox_2->setValue(str1.count());
    ui->LabSpin_2->setText("count()");
}

void Widget::on_pushButton_23_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();
    ui->checkBox_2->setChecked(str1.endsWith(str2));
}
