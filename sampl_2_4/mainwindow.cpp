#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();
    iniSingalSlots();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniUI()
{
    setCentralWidget(ui->textEdit);
    fLabelCurFile = new QLabel;
    fLabelCurFile->setMidLineWidth(150);
    fLabelCurFile->setText("当前文件：");
    ui->statusbar->addWidget(fLabelCurFile);

    progressBar = new QProgressBar;
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar);

    spinFontSize = new QSpinBox;
    spinFontSize->setMaximum(50);
    spinFontSize->setMinimum(5);
    ui->toolBar->addWidget(new QLabel("字体大小"));

    ui->toolBar->addWidget(spinFontSize);

    comboFont = new QFontComboBox;
    ui->toolBar->addWidget(new QLabel(" 字体"));
    ui->toolBar->addWidget(comboFont);
}


void MainWindow::on_actionBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actionItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if(checked)
        fmt.setFontItalic(checked);
    else
        fmt.setFontItalic(false);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actionUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if(checked)
        fmt.setFontUnderline(checked);
    else
        fmt.setFontUnderline(false);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actionCut->setEnabled(b);
    ui->actionCopy->setEnabled(b);
    ui->actionPaste->setEnabled(ui->textEdit->canPaste());
}

void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    ui->actionItalic->setChecked(fmt.fontItalic());
    ui->actionBold->setChecked(fmt.font().bold());
    ui->actionUnderline->setChecked(fmt.fontUnderline());
    spinFontSize->setValue(fmt.fontPointSize());
    comboFont->setCurrentFont(fmt.font());
}

void MainWindow::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontPointSize(aFontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBar->setValue(aFontSize);
}

void MainWindow::on_comboFont_currentIndexChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontFamily(arg1);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::iniSingalSlots()
{
    void(QSpinBox:: *valueChangedPtr)( int ) = &QSpinBox::valueChanged;
    connect(spinFontSize,valueChangedPtr,this,&MainWindow::on_spinBoxFontSize_valueChanged);

    void(QComboBox:: *currentIndexChangedPtr)(const QString &) = &QComboBox::currentIndexChanged;
    connect(comboFont, currentIndexChangedPtr,this,&MainWindow::on_comboFont_currentIndexChanged);
}






