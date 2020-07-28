#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bmi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_Quit_clicked();
    void on_btn_Calculate_clicked();

    void on_spbx_HeightFeet_valueChanged(int arg1);
    void on_spbx_HeightInch_valueChanged(int arg1);
    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    Bmi * mCalculator;
};
#endif // MAINWINDOW_H
