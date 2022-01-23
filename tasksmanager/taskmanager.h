#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <QMainWindow>
#include<QStringListModel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QCloseEvent>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QMouseEvent>
#include "task.h"
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class taskmanager; }
QT_END_NAMESPACE

class taskmanager : public QMainWindow
{
    Q_OBJECT

public:
    taskmanager(QWidget *parent = nullptr);
    ~taskmanager();
    QStandardItemModel *model=nullptr;
    QStandardItemModel *model1=nullptr;
     QStandardItemModel *model2=nullptr;
      QStandardItemModel *model3=nullptr;

      QStringList Todaytasks;
      QStringList Finishedtasks;
      QStringList Pendingtasks;


      QFile lyouma{"Today tasks.txt"};
      QFile salaw{"Finished tasks.txt"};
      QFile apres{"Pending tasks.txt"};






     void loadContent(QFile *filename=nullptr);

      void saveFinishedContent(QFile *filename=nullptr) const;
      void saveTodayContent(QFile *filename=nullptr) const;
      void savePendingContent(QFile *filename=nullptr) const;
      //void erase(QFile *filename=nullptr);


public slots:
    void on_actionNew_triggered();

public:
    Ui::taskmanager *ui;
private slots:

 void closeEvent (QCloseEvent *event);
 void on_actionExit_triggered();
 void on_actionShow_Pending_triggered();
 void on_actionShow_Finished_triggered();
 void on_actionShow_Today_tasks_triggered();
 void on_actionDelete_triggered();
 void on_actionShow_All_triggered();

//to change a task from a listView to another

    void on_listView1_doubleClicked(const QModelIndex &index);
    void on_listView2_doubleClicked(const QModelIndex &index);
    void on_listView3_doubleClicked(const QModelIndex &index);
};
#endif // TASKMANAGER_H
