#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void colorCheanged();

private slots:
    void on_SliderRed_2_valueChanged(int value);

    void on_SliderGreen_2_valueChanged(int value);

    void on_SliderBlue_2_valueChanged(int value);

    void on_SliderAlpha_2_valueChanged(int value);

    void on_SliderH_2_valueChanged(int value);

    void on_dial_2_valueChanged(int value);

    void on_radioBtnHex_2_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
