#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // line edit validators
    mCalculator = new Bmi();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mCalculator;
}


void MainWindow::on_btn_Quit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_btn_Calculate_clicked()
{
    double      value = 0.0;
    QString     category;

    // calculate BMI
    value               = static_cast<double>(mCalculator->Calculate(category));
    QString strValue    = QString::number(value,'f',1);

    ui->lbl_BmiValue->setText(strValue);
    ui->lbl_BmiCategoryValue->setText(category);
}


void MainWindow::on_spbx_HeightFeet_valueChanged(int arg1)
{
    mCalculator->SetHeightFeet(arg1);
}

void MainWindow::on_spbx_HeightInch_valueChanged(int arg1)
{
    mCalculator->SetHeightInch(arg1);
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    float value = static_cast<float>(arg1);
    mCalculator->SetWeight(value);
}
