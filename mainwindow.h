#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Weight();
    float sigma(float value);
    void Count();
    void Study();
    void init_Mass();
    ~MainWindow();
private slots:
    void on_actionExit_triggered();

    void on_actionInstruction_triggered();

    void on_Add_clicked();

    void on_Teach_clicked();

    void on_commandLinkButton_clicked();

    void on_actionSave_triggered();

private:
    int t_1 = 0;
    int t_11 = 0;
    int t_2 = 0;
    int t_22 = 1;
    int v_1 = 0;
    int v_11 = 2;
    int ans_1 = 0;
    int ans_11 = 3;
    int InN;
    int OutN;
    int outer;
    float sig;
    float etta;
    int epoh;
    double enters[3];
    double hidden[4];
    double hidd_ent_w[sizeof(hidden)/sizeof(hidden[0])];
    double ent_hidd_w[3][4];
    int patterns[7][3];
    int output[7][3];
    double err[sizeof(hidd_ent_w)/sizeof(hidd_ent_w[0])];
    int answers[7];
    QFile *save;
    QMessageBox *msg;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
