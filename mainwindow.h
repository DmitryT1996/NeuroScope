#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_actionExit_triggered();

    void on_actionInstruction_triggered();

    void on_Add_clicked();

    void on_Teach_clicked();

private:
    int t_1 = 0;
    int t_11 = 0;
    int t_2 = 0;
    int t_22 = 1;
    int ans_1 = 0;
    int ans_11 = 3;

    int InN;
    int OutN;
    int outer;
    float sig;
    float etta;
    double enters[2];
    double hidden[2];
    double hidd_ent_w[2];
    double ent_hidd_w[2][2];
    double patterns[7][2];
    double err[2];
    int answers[7];
    double patt[7][2];
    void Weight();
    float sigma(float value);
    void Count();
    void Study();
    Ui::MainWindow *ui;
    void init_Mass();
};

#endif // MAINWINDOW_H
