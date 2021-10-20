#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QCheckBox * checkBoxUnderline;
    QCheckBox * checkBoxItalic;
    QCheckBox * checkBoxBold;

    QRadioButton * rBtnBlack;
    QRadioButton * rBtnBlue;
    QRadioButton * rBtnRed;

    QPlainTextEdit * plainTextEdit;
    QPushButton * btnOK;
    QPushButton * btnCancel;
    QPushButton * btnClose;

    QHBoxLayout * HLayout1;
    QHBoxLayout * HLayout2;
    QHBoxLayout * HLayout3;
    QVBoxLayout * VLayout;

    void iniUI();
    void iniSignalSlots();
public:
    void on_checkUnderline(bool checked);
    void on_checkItalic(bool checked);
    void on_checkBold(bool checked);

    void setTextFontColor();

    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
