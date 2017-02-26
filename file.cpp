#include "file.h"
#include "ui_file.h"
#include <QPlainTextEdit>
File::File(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::File)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->insertPlainText("\t\tИНСТРУКЦИЯ ПО ЭКСПЛУАТАЦИИ ДАНОГО ПП\n\n\n\nfdgbbfjh\nsdgt");
}

File::~File()
{
    delete ui;
}
