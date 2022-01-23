###### Top
[Bottom](#bottom)
# ToDo Application using containers

BY : Lakhmiri / Sakassa / Benzemroun

## Introduction
### **TODO** List are the lists that we generally use to maintain our day to day tasks or list of everything that we have to do. It is helpful in planning our daily schedules. We can add more tasks any time and delete a task which is completed. The four major tasks that we can perform in a TODO list are:

1. Add tasks
2. Update tasks
3. Read tasks
4. Delete tasks


## First let's describe our application
### In our Task Manager application we have:
1. A menu bar containing : "File , Options , Help"
   - file menu containing : "New , Exit"
     - **_New_** is an action which can add a new task to our application
     - **_Exit_** is an action which **save** the contents befor leaving the application
   - options menu containing : "Delete, show all, show pending task, show finished task, show today task"
     - **_Delete task_** is an action which can delete a selected task
     - **_Show all_** is an action which show pending,today and finished task
     - **_Show pending_** is an action which show pending task
     - **_Show finished_** is an action which show finished task
     - **_Show today task_** is an action which show today task
   - Help menu containing : "About , About Qt"
2. A Tool bar containing actions like : "new task, show finished, show pending, delete, exit"
3. A List view; in our application we have tree each one display a specific type of tasks
   
# our application look like this:
![image](https://user-images.githubusercontent.com/53974876/150644640-0ee5e304-e3f2-4e39-b20e-95321bdb8a71.png)

- ### when you click **N** (in your keyboard) or presing new file in the application a Qdialoge will pop out

![image](https://user-images.githubusercontent.com/53974876/150644932-c500a620-9f5e-4d16-a10f-ff85d63bf88b.png)

## this QDialog is containing 
1. A description for your task 
2. A check box for finished tasks
3. tags 
4. date for the task (for today or for a specifique date)
5. two push buttons (ok and cancel)



- ## let's make (today, tomorrow and a finished task) with our application, after creating each one now we can see the tasks in the appropriate list 

![image](https://user-images.githubusercontent.com/53974876/150645421-5cb99089-212a-4f38-81ed-b4f9949a0b00.png)

- ### now we want to place a pending task in the listView of today task 
1. first we double click on the task 
2. the Qdialog will pop out to change the description and the date for the selected task
3. after changing the date you press ok 

![image](https://user-images.githubusercontent.com/53974876/150645875-940b7ad8-7774-41d2-be49-a155ac9efb1b.png)

- ### now you can see the task go from pending tasks to today tasks

![image](https://user-images.githubusercontent.com/53974876/150645881-25d6726a-209f-49fa-9142-cc53a9106538.png)

- ### to delete a task you click on it then you press the delet icon in the tool bar

![Untitled-1](https://user-images.githubusercontent.com/53974876/150646443-66a0756c-b9ff-45ba-97c5-8afddf202ac8.png)

- ### To save and exit the application press exit icon in the tool bar then press ok

![Screenshot-2022-01-22-171020](https://user-images.githubusercontent.com/53974876/150646724-6e89aeff-266c-4264-81d8-5429ef43833a.png)

- ### if you want to check your saves go to the `build-tasksmanager-Desktop_Qt_5_15_0_MinGW_64_bit-Debug` folder

![image](https://user-images.githubusercontent.com/53974876/150646852-22d77763-2d50-4895-b388-b5875f522ee5.png)

    
# **To result with such a functional application you have to go through multiple functions, slots, actions and methods (But don't worry we will explain the functionality and role of each part of our code)** 

 - ## First we create two **UI** **( task.ui , taskmanager.ui )**

![Screenshot-2022-01-23-095808](https://user-images.githubusercontent.com/53974876/150671610-901ec496-e154-4ab5-a7e8-788c793304d7.png)

- ## Now let's see the (Header) task

## Task.h
- ### our class task will inherit from QDialog

```c++
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
```
- ### Now we will add boolean named ` logic ` we will see in the next steps why
 ```c++
 bool logic=false;

Ui::task *ui;
```
- ### Two private slot
```c++
private slots:
void on_OK_clicked();
void on_Cancel_clicked();
private:
};
 ```
 ## Task.cpp

- ### First we setup our UI
```c++
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
```
- ### Now the implementation for the Two slots already declared in [task.h](#taskh)  
```c++
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
```

- ### Moving to taskmanager and starting with `taskmanager.h`

## taskmanager.h

- ###  first our class taskmanager will inherit from QMainWindow

```c++
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

```

- ### we will need a model ( our model is of type QStandardItemModel )
- ### we will need three string where we will store the three tasks
- ### we will need a file for each one ,in this files we can find our saves
```c++
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
      
      QFile  lyouma{"Today tasks.txt"};
      QFile salaw{"Finished tasks.txt"};
      QFile apres{"Pending tasks.txt"};
```
- ### A void function for load content

```c++
void loadContent(QFile *filename=nullptr);
```
- ### three void function for saving
```c++
void saveFinishedContent(QFile *filename=nullptr) const;
void saveTodayContent(QFile *filename=nullptr) const;
void savePendingContent(QFile *filename=nullptr) const;
```
- ### A public slot to create new task
 ```c++
 public slots:
    void on_actionNew_triggered();
 ```
 - ### Here we have all the private slots for our actions
 ```c++
 private slots:
 void closeEvent (QCloseEvent *event);
 void on_actionExit_triggered();
 void on_actionShow_Pending_triggered();
 void on_actionShow_Finished_triggered();
 void on_actionShow_Today_tasks_triggered();
 void on_actionDelete_triggered();
 void on_actionShow_All_triggered(); 
 //to move a task from a listView to another
 void on_listView1_doubleClicked(const QModelIndex &index);
 void on_listView2_doubleClicked(const QModelIndex &index);
 void on_listView3_doubleClicked(const QModelIndex &index);
 ```   
    
 - ### Now we will see the implementation of eache slot and function   
    
 ## taskmanager.cpp
 - ### _includes_
 ```c++
 #include "taskmanager.h"
#include "ui_taskmanager.h"
#include "task.h"
#include "ui_task.h"
#include <stdlib.h>
#include <QDrag>
#include <QMimeData>
#include <QDropEvent>
 ```
 
 - ### Starting with the constructor and Destructor
 ```c++
 taskmanager::taskmanager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::taskmanager)
{
    ui->setupUi(this);

    QStandardItem *model = new QStandardItem;

   model1 = new QStandardItemModel();
   model2 = new QStandardItemModel();
   model3 = new QStandardItemModel();

   QFile  lyouma{"Today tasks.txt"};
   QFile salaw{"Finished tasks.txt"};
   QFile apres{"Pending tasks.txt"};

   model->setText("");
   model1->appendRow(model);
   ui->listView1->setModel(model1);
   model2->appendRow(model);
   ui->listView2->setModel(model2);
   model3->appendRow(model);
   ui->listView3->setModel(model3);

   model1->removeRow(0);
   model2->removeRow(0);
   model3->removeRow(0);

   loadContent(&lyouma);
   loadContent(&salaw);
   loadContent(&apres);

   setAcceptDrops(false);
      //ui->listView1->setAcceptDrops(true);
   ui->listView1->setAcceptDrops(true);
   ui->listView2->setAcceptDrops(true);
   ui->listView3->setAcceptDrops(true);
}
taskmanager::~taskmanager()
{
    delete ui;
}
 ```
- ### The implementation of the `on_actionNew_triggered()` slot
here we will use the bool `logic` already declared in `task` if the **Ok** button in `task.ui` is clicked `logic=true` if **Cancel** is clicked `logic=false`
after checking the logic if is it true or not now we should check the type of the task (finished,today or pending) . We passed through this conditions to store each task in their appropriate listView  


```c++
void taskmanager::on_actionNew_triggered()
{
task T;
T.ui->date->setDate(QDate::currentDate());
T.exec();
  QStandardItem *it = new QStandardItem();
  
if(T.logic){
    if(T.ui->fincheck->isChecked()){
      Finishedtasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
      it->setIcon(QPixmap(":/new/prefix1/prfix1/task-completed.png"));
      it->setText(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
      model3->appendRow(it);
      ui->listView3->setModel(model3);
      ui->listView3->update();
    }
     else if(T. ui->date->date().toString("ddd MMMM d yyyy")==QDate::currentDate().toString("ddd MMMM d yyyy")){
     Todaytasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
     it->setIcon(QPixmap(":/new/prefix1/task.png"));
     it->setText(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
     model1->appendRow(it);
     ui->listView1->setModel(model1);
     ui->listView1->update();
   }
       else{
    Pendingtasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
    it->setIcon(QPixmap(":/new/prefix1/data-pending.png"));
    it->setText(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
    model2->appendRow(it);
    ui->listView2->setModel(model2);
    ui->listView2->update();
  }
T.close();
  }
}
```
    
    
    
    
   
    
    
    
    
    
    
    
    
    
    
    
    
    
 [Top](#top)  
 ###### Bottom

```diff 
@@ gfngn @@
```
- [x] #739

- [ ] ldkhfds\kl 
