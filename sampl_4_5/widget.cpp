#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    fTimer = new QTimer(this);
    fTimer->setInterval(1000);
    fTimer->stop();
    connect(fTimer,&QTimer::timeout,this,&Widget::on_timer_timeout);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnGetTime_clicked()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->dateEdit->setDate(currentDateTime.date());
    ui->editDate->setText(currentDateTime.toString("yyyy-MM-dd"));

    ui->dateTimeEdit->setDateTime(currentDateTime);
    ui->editTime->setText(currentDateTime.time().toString());

    ui->timeEdit->setTime(currentDateTime.time());
    ui->editDateTime->setText(currentDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

void Widget::on_btnSetTime_clicked()
{
    QString strTime = ui->editTime->text();
    QTime time = QTime::fromString(strTime);
    ui->timeEdit->setTime(time);
}

void Widget::on_calendarWidget_clicked(const QDate &date)
{
    ui->editCalendar->setText(date.toString("yyyy-MM-dd"));
}

void Widget::on_timer_timeout()
{

    ui->LCDHour->display(QTime::currentTime().hour());
    ui->LCDMin->display(QTime::currentTime().minute());
    ui->LCDSec->display(QTime::currentTime().second());
    int value = ui->progressBar->value();
    value++;
    if(value > 100)
        value = 0;
    ui->progressBar->setValue(value);
}

void Widget::on_btnSetIntv_clicked()
{
    fTimer->setInterval(ui->spinBoxIntv->value());
}

void Widget::on_btnStart_clicked()
{
    fTimer->start();
    ui->btnStart->setEnabled(false);
    ui->btnSetIntv->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->spinBoxIntv->setEnabled(false);//开始计时后，将计时器及时周期置于不可更改状态
    fTimeCounter.start();
//    fTimeCounter.start();//暂放 warning
}

void Widget::on_btnStop_clicked()
{
    ui->btnStart->setEnabled(true);
    ui->btnSetIntv->setEnabled(true);
    ui->btnStop->setEnabled(false);
    ui->spinBoxIntv->setEnabled(true);
    fTimer->stop();
//    int tmMsec = fTimeCounter.elapsed();
    int tmMsec = fTimeCounter.elapsed();
    int sec = tmMsec/1000;
    int mSec = tmMsec%1000;
    QString str = QString::asprintf("流逝时间：%d秒%d毫秒",sec,mSec);
    ui->LabElapsTime->setText(str);
}

void Widget::on_spinBoxIntv_valueChanged(int arg1)
{
    fTimer->setInterval(arg1);//修复必须点击设置周期，计时器周期才会生效的不合理之处
}
