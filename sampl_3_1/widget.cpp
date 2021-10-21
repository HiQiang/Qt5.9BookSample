#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBoxBoy->setProperty("isBoy",true);
    ui->spinBoxGirl->setProperty("isBoy",false);

    //boy
    boy = new QPerson("王小明");
    boy->setProperty("score",95);
    boy->setProperty("age",10);
    boy->setProperty("sex","boy");
    connect(boy,&QPerson::ageChanged,this,&Widget::on_ageChanged);

    //girl
    girl = new QPerson("李小红");
    girl->setProperty("score",85);
    girl->setProperty("age",15);
    girl->setProperty("sex","girl");
    connect(girl,&QPerson::ageChanged,this,&Widget::on_ageChanged);

    void(QSpinBox::*valueChangedPtr)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBoxBoy,valueChangedPtr,this,&Widget::on_spin_valueChanged);
    connect(ui->spinBoxGirl,valueChangedPtr,this,&Widget::on_spin_valueChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_spin_valueChanged(int arg1)
{
    //Q_UNUSED(arg1)//指明arg1参数在函数中不使用
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    if(spinBox->property("isBoy").toBool() == true)
    {
        boy->setAge(arg1);
    }
    else
    {
        girl->setAge(arg1);
    }
}

void Widget::on_ageChanged()
{
//    Q_UNUSED(value)//指明某一变量在函数中不使用，消除警告
    QPerson * aPerson = qobject_cast<QPerson *>(sender());
    QString aName = aPerson->property("name").toString();
    QString aSex = aPerson->property("sex").toString();
    unsigned aAge = aPerson->age();
    ui->textEdit->appendPlainText(aName + "," + aSex + QString::asprintf(",年龄=%d",aAge));
}


void Widget::on_btnBoyInc_clicked()
{
    boy->incAge();
}

void Widget::on_btnGirlInc_clicked()
{
    girl->incAge();
}

void Widget::on_btnClassInfo_clicked()
{
    const QMetaObject *meta = boy->metaObject();
    ui->textEdit->clear();
    ui->textEdit->appendPlainText("==元对象信息==\n");
    ui->textEdit->appendPlainText(
                QString("类命名：%1\n").arg(meta->className()));
    ui->textEdit->appendPlainText("Property");
    for(int i=meta->propertyOffset();i<meta->propertyCount();i++)
    {
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propValue = boy->property(propName).toString();
        ui->textEdit->appendPlainText(
                    QString("属性名称：%1. 属性值：%2").arg(propName).arg(propValue));
    }
    ui->textEdit->appendPlainText(QString("\n"));
    meta = girl->metaObject();
    for(int i=meta->propertyOffset();i<meta->propertyCount();i++)
    {
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propValue = girl->property(propName).toString();
        ui->textEdit->appendPlainText(
                    QString("属性名称：%1. 属性值：%2").arg(propName).arg(propValue));
    }

    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo");
    for(int i = meta->classInfoOffset();i<meta->classInfoCount();i++)
    {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->textEdit->appendPlainText(QString("Name=%1,Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
}
