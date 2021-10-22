#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    QTimer *fTimer;
    QElapsedTimer fTimeCounter;


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnGetTime_clicked();

    void on_btnSetTime_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_timer_timeout();

    void on_btnSetIntv_clicked();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_spinBoxIntv_valueChanged(int arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
