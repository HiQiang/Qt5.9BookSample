#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->rBtBlack, &QRadioButton::clicked, this, &Dialog::setTextFontColor);
    connect(ui->rBtBlue, &QRadioButton::clicked, this, &Dialog::setTextFontColor);
    connect(ui->rBtRed, &QRadioButton::clicked, this, &Dialog::setTextFontColor);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_checkBoxUnderline_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
    ui->plainTextEdit->setFont(font);
}

void Dialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);
    ui->plainTextEdit->setFont(font);

}

void Dialog::setTextFontColor()
{
    QPalette palette = ui->textEdit->palette();
    if(ui->rBtBlack->isChecked())
    {
        palette.setColor(QPalette::Text,Qt::black);
    }
    else if(ui->rBtBlue->isChecked())
    {
        palette.setColor(QPalette::Text,Qt::blue);
    }
    else if(ui->rBtRed->isChecked())
    {
        palette.setColor(QPalette::Text,Qt::red);
    }
    ui->textEdit->setPalette(palette);
    ui->plainTextEdit->setPalette(palette);
}
