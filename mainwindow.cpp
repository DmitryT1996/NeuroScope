#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file.h"
#include<time.h>
#include<cstdlib>
#include <math.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    setWindowTitle("NeuroScope v0.1 beta");
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "T1" << "T2" << "V1" << "Answers" << "Rezult");
    ui->Teach->setEnabled(false);
    InN = 2;
    OutN = 2;
    sig = 0.5;
    etta = 0.01;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Weight()
{
for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    ent_hidd_w[i][j] = 0.01 * (rand() % 101);
                }
        }
        for (int i = 0; i < 2; i++)
            hidd_ent_w[i] = 0.01 * (rand() % 101);
}

void MainWindow::Count(){

for(int i = 0; i < InN; i ++){
    hidden[i] = 0;
        for(int j = 0; j < OutN; j++){
            hidden[i] += enters[j]*ent_hidd_w[j][i];
        }
        if(hidden[i]>sig)
            hidden[i] = 1;
        else
        hidden[i] = 0;
}
outer = 0;
for(int i = 0; i < InN; i ++){
    outer+=hidden[i]*hidd_ent_w[i];
}
sigma(outer);
}

float MainWindow::sigma(float value){
    return value > sig ? 1 : 0;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionInstruction_triggered()
{
    File *f = new File(this);
    f->show();
}

void MainWindow::on_Add_clicked()
{
    int i = ui->label_T1->text().toDouble();
    int j = ui->label_T2->text().toDouble();
    QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(i));
    ui->tableWidget->setItem(t_1, t_11, itm);
    itm = new QTableWidgetItem(tr("%1").arg(j));
    ui->tableWidget->setItem(t_2, t_22, itm);
    if(ui->radioButton->isChecked())
    {
        itm = new QTableWidgetItem(tr("%1").arg(1));
        ui->tableWidget->setItem(ans_1, ans_11, itm);
    }
    if(ui->radioButton_2->isChecked())
    {
        itm = new QTableWidgetItem(tr("%1").arg(0));
        ui->tableWidget->setItem(ans_1, ans_11, itm);
    }
    t_1++;
    t_2++;
    ans_1++;
    if(t_1 == ui->tableWidget->rowCount() && t_2 == ui->tableWidget->rowCount())
    {
        ui->Teach->setEnabled(true);
    }
}

void MainWindow::init_Mass()
{
    int j = 3;
    QTableWidgetItem *item = new QTableWidgetItem();
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        answers[i] = ui->tableWidget->item(i, j)->text().toDouble();
    }

  for(int i(0); i < ui->tableWidget->rowCount(); i++)
  {
      for(int j(0); j < 2; j++)
          patterns[i][j] = ui->tableWidget->item(i, j)->text().toDouble();
  }

}

void MainWindow::Study()
{
    QTableWidgetItem *out = new QTableWidgetItem();
    double gErr = 0;
        int i = 0;
        while( i < 50000){
            gErr = 0;
            for(int p = 0; p < 7; p++){
                for(int i = 0; i < 2; i++)
                    enters[i] = patterns[p][i];
                    Count();
                    double lErr = answers[p] - outer;
                    gErr+=abs(lErr);
                    for(int i = 0; i < OutN; i++)
                        err[i] = lErr*hidd_ent_w[i];
                    for(int i = 0; i < InN; i++){
                        for(int j = 0; j < OutN; j++){
                            ent_hidd_w[i][j] += etta*err[j]*enters[i];
                        }
                    }
                    for(int i = 0; i < OutN; i++){
                        hidd_ent_w[i] += etta*lErr*hidden[i];
                    }
            }
            i++;
        }
        for(int p = 0; p < 7; p++){
                 for(int i = 0; i < 2; i++)
                     enters[i] = patterns[p][i];
                     Count();
                     out = new QTableWidgetItem(tr("%1").arg(outer));
                     ui->tableWidget->setItem(p, 4, out);
        }
}

void MainWindow::on_Teach_clicked()
{
    init_Mass();
     Weight();
     Study();
}
