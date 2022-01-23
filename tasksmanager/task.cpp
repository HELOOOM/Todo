#include "task.h"
#include "ui_task.h"
#include "taskmanager.h"
#include "ui_taskmanager.h"
#include <QDate>
task::task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task)
{
    ui->setupUi(this);
}

task::~task()
{
    delete ui;
}

void task::on_OK_clicked()
{

    logic=true;
    close();


}


void task::on_Cancel_clicked()
{
    logic=false;
    close();
}


