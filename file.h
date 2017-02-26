#ifndef FILE_H
#define FILE_H

#include <QMainWindow>

namespace Ui {
class File;
}

class File : public QMainWindow
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = 0);
    ~File();

private:
    Ui::File *ui;
};

#endif // FILE_H
