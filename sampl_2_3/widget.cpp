#include "widget.h"

void Widget::iniUI()
{
    checkBoxUnderline = new QCheckBox(tr("Underine"));
    checkBoxItalic = new QCheckBox(tr("Italic"));
    checkBoxBold = new QCheckBox(tr("Bold"));

    rBtnBlack = new QRadioButton("Black");
    rBtnBlack->setChecked(true);
    rBtnBlue = new QRadioButton("Blue");
    rBtnRed = new QRadioButton("Red");

    plainTextEdit = new QPlainTextEdit;
    QFont font = plainTextEdit->font();
    font.setPointSize(20);
    plainTextEdit->setFont(font);
    plainTextEdit->setPlainText("Hello World!\n\nThis is HiQiang!");

    btnOK = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("退出");

    HLayout1 = new QHBoxLayout;
    HLayout1->addWidget(checkBoxUnderline);
    HLayout1->addWidget(checkBoxItalic);
    HLayout1->addWidget(checkBoxBold);
    VLayout = new QVBoxLayout;
    VLayout->addLayout(HLayout1);

    HLayout2 = new QHBoxLayout;
    HLayout2->addWidget(rBtnBlack);
    HLayout2->addWidget(rBtnBlue);
    HLayout2->addWidget(rBtnRed);
    VLayout->addLayout(HLayout2);

    HLayout3 = new QHBoxLayout;
    HLayout3->addStretch();
    HLayout3->addWidget(btnOK);
    HLayout3->addWidget(btnCancel);
    HLayout3->addStretch();
    HLayout3->addWidget(btnClose);
    VLayout->addWidget(plainTextEdit);
    VLayout->addLayout(HLayout3);
    setLayout(VLayout);
}

void Widget::iniSignalSlots()
{
    connect(btnOK,&QPushButton::clicked,this,&QWidget::close);
    connect(btnCancel,&QPushButton::clicked,this,&QWidget::close);
    connect(btnClose,&QPushButton::clicked,this,&QWidget::close);

    connect(checkBoxUnderline,&QCheckBox::clicked,this,&Widget::on_checkUnderline);
    connect(checkBoxItalic,&QCheckBox::clicked,this,&Widget::on_checkItalic);
    connect(checkBoxBold,&QCheckBox::clicked,this,&Widget::on_checkBold);
    connect(rBtnBlack,&QRadioButton::clicked,this,&Widget::setTextFontColor);
    connect(rBtnRed,&QRadioButton::clicked,this,&Widget::setTextFontColor);
    connect(rBtnBlue,&QRadioButton::clicked,this,&Widget::setTextFontColor);
}

void Widget::on_checkUnderline(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setUnderline(checked);
    plainTextEdit->setFont(font);
}

void Widget::on_checkItalic(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setItalic(checked);
    plainTextEdit->setFont(font);
}

void Widget::on_checkBold(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setBold(checked);
    plainTextEdit->setFont(font);
}

void Widget::setTextFontColor()
{
    QPalette palette = plainTextEdit->palette();
    if(rBtnBlack->isChecked())
    {
        palette.setColor(QPalette::Text,Qt::black);
    }
    else if(rBtnRed->isChecked())
    {
        palette.setColor(QPalette::Text,Qt::red);
    }
    else if(rBtnBlue->isChecked())
    {
        palette.setColor(QPalette::Text,Qt::blue);
    }
    plainTextEdit->setPalette(palette);

}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   iniUI();
   iniSignalSlots();
}

Widget::~Widget()
{
}

