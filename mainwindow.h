#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtMath>
#include <QStack>
#include "compiler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_ansbutton_clicked();
    void on_zeroButton_clicked();
    void on_oneButton_clicked();
    void on_twoButton_clicked();
    void on_threeButton_clicked();
    void on_fourButton_clicked();
    void on_fiveButton_clicked();
    void on_sixButton_clicked();
    void on_sevenButton_clicked();
    void on_eightButton_clicked();
    void on_nineButton_clicked();
    void on_semicolonButton_clicked();
    void on_powerButton_clicked();
    void on_sqrtButton_clicked();
    void on_modButton_clicked();
    void on_CEButton_clicked();
    void on_CButton_clicked();
    void on_backButton_clicked();
    void on_divButton_clicked();
    void on_mulButton_clicked();
    void on_subButton_clicked();
    void on_addButton_clicked();
    void on_pointButton_clicked();

private:
    Ui::MainWindow *ui;
    bool status;//等待运算符
    QString exp,ans;

    void clearEdit();
    void getAns();

    QString RPN(QString);
    float work(QString);
};

#endif // MAINWINDOW_H
