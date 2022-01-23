#ifndef TASK_H
#define TASK_H
#include <QDialog>
#include <QStringListModel>
#include "taskmanager.h"
#include<QtDebug>

namespace Ui {
class task;
}

class task : public QDialog
{
    Q_OBJECT

public:
 explicit task(QWidget *parent = nullptr);

    ~task();
bool logic=false;

Ui::task *ui;
public slots:

private slots:
void on_OK_clicked();

void on_Cancel_clicked();
private:

};

#endif // TASK_H
