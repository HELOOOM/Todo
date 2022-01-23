#include "taskmanager.h"
#include "ui_taskmanager.h"
#include "task.h"
#include "ui_task.h"
#include <stdlib.h>
#include <QDrag>
#include <QMimeData>
#include <QDropEvent>
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


void taskmanager::on_actionNew_triggered()
{
task T;
T.ui->date->setDate(QDate::currentDate());
T.exec();
  QStandardItem *it = new QStandardItem();

if(T.logic){


       if(T.ui->fincheck->isChecked()){

          Finishedtasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
          it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (2).jpeg"));
          it->setText(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
          model3->appendRow(it);
          ui->listView3->setModel(model3);
          ui->listView3->update();



       }
       else if(T. ui->date->date().toString("ddd MMMM d yyyy")==QDate::currentDate().toString("ddd MMMM d yyyy")){
           Todaytasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
           it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (1).jpeg"));
           it->setText(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
           model1->appendRow(it);
           ui->listView1->setModel(model1);
           ui->listView1->update();

       }
       else{
           Pendingtasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
           it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01.jpeg"));
           it->setText(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
           model2->appendRow(it);
           ui->listView2->setModel(model2);
           ui->listView2->update();


       }
T.close();

  }




}


void taskmanager::loadContent(QFile *filename){

    if (filename->open(QIODevice::ReadOnly)) {
        QTextStream in(filename);
        if(filename->fileName()==salaw.fileName()){
            while (!in.atEnd()) {
                QStandardItem *it = new QStandardItem();

                QString line = in.readLine();
            Finishedtasks.append(line);
            it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (2).jpeg"));
            it->setText(line);
              model3->appendRow(it);
              ui->listView3->setModel(model3);
         }
     }
        else if(filename->fileName()==lyouma.fileName()){
            while (!in.atEnd()) {
                QStandardItem *it = new QStandardItem();

                QString line = in.readLine();
             Todaytasks.append(line);
             it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (1).jpeg"));
             it->setText(line);
             model1->appendRow(it);
                 ui->listView1->setModel(model1);
     }
  }
        else if(filename->fileName()==apres.fileName()){
            while (!in.atEnd()) {
                QStandardItem *it = new QStandardItem();
                QString line = in.readLine();
                Pendingtasks.append(line);
                it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01.jpeg"));
                 it->setText(line);
                 model2->appendRow(it);

                 ui->listView2->setModel(model2);
             }
         }
    }
}


void taskmanager::saveTodayContent(QFile *filename) const
{
    //Openign the file
    if(filename->open(QIODevice::WriteOnly))  //Opening the file in writing mode
    {
        //Initiating a stream using the file
        QTextStream out(filename);
        for ( int i=0; i < Todaytasks.size(); ++i )
                        out << Todaytasks.at(i) << "\n";
    }
    filename->close();
}

void taskmanager::savePendingContent(QFile *filename) const
{
    //Openign the file
    if(filename->open(QIODevice::WriteOnly))  //Opening the file in writing mode
    {
        //Initiating a stream using the file
        QTextStream out(filename);
        for ( int i=0; i < Pendingtasks.size(); ++i )
                        out << Pendingtasks.at(i) << "\n";
    }
    filename->close();
}

void taskmanager::saveFinishedContent(QFile *filename) const
{
    //Openign the file
    if(filename->open(QIODevice::WriteOnly))  //Opening the file in writing mode
    {
        //Initiating a stream using the file
        QTextStream out(filename);

        for ( int i=0; i < Finishedtasks.size(); ++i )
                        out << Finishedtasks.at(i) << "\n";
    }
    filename->close();
}





void taskmanager::on_actionExit_triggered()
{
        saveTodayContent(&lyouma);
        saveFinishedContent(&salaw);
        savePendingContent(&apres);
         QMessageBox::information(this,"DONE","saveeeed & exited");
         qApp->exit();

}
void taskmanager::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Task MAnager",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        on_actionExit_triggered();
        event->accept();
    }
}


void taskmanager::on_actionShow_Pending_triggered()
{
    ui->listView1->hide();
    ui->listView3->hide();
    ui->listView2->show();
}
void taskmanager::on_actionShow_Finished_triggered()
{
    ui->listView1->hide();
    ui->listView2->hide();
    ui->listView3->show();
}
void taskmanager::on_actionShow_Today_tasks_triggered()
{
    ui->listView2->hide();
    ui->listView3->hide();
    ui->listView1->show();
}


void taskmanager::on_actionDelete_triggered()
{
if( ui->listView1->model()->rowCount()!=0){
    QModelIndexList indexes1;
    indexes1= ui->listView1->selectionModel()->selectedIndexes();

    for(auto iter = indexes1.constBegin(); iter != indexes1.constEnd(); ++iter){
Todaytasks.removeAt((*iter).row());
       model1->removeRow((*iter).row());
        }
}

if (ui->listView2->model()->rowCount()!=0){
    QModelIndexList indexes2;
    indexes2 = ui->listView2->selectionModel()->selectedIndexes();

    for(auto iter = indexes2.constBegin(); iter != indexes2.constEnd(); ++iter){
        Pendingtasks.removeAt((*iter).row());
       model2->removeRow((*iter).row());
    }
}

if(ui->listView3->model()->rowCount()!=0){
    QModelIndexList indexes3;
    indexes3 = ui->listView3->selectionModel()->selectedIndexes();

    for(auto iter = indexes3.constBegin(); iter != indexes3.constEnd(); ++iter){
        Finishedtasks.removeAt((*iter).row());

       model3->removeRow((*iter).row());
      }
   }
}


void taskmanager::on_actionShow_All_triggered()
{
    ui->listView1->show();
    ui->listView2->show();
    ui->listView3->show();
}

void taskmanager::on_listView1_doubleClicked(const QModelIndex &index)
{

    QRegExp rx("(\\:)");
    QStringList query = Todaytasks.at(index.row()).split(rx);
    task T;
    T.ui->date->setDate(QDate::currentDate());
    T.ui->Description->setText(query.at(0));
    T.ui->tag->setCurrentIndex(T.ui->tag->findText(query.at(2)));
    T.exec();
      QStandardItem *it = new QStandardItem();

    if(T.logic){
        Todaytasks.removeAt(index.row());

        model1->removeRow(index.row());

         saveTodayContent(&lyouma);


           if(T.ui->fincheck->isChecked()){

              Finishedtasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
              it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (2).jpeg"));
              it->setText(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());

              model3->appendRow(it);
              ui->listView3->setModel(model3);


           }else if(T. ui->date->date().toString("ddd MMMM d yyyy")==QDate::currentDate().toString("ddd MMMM d yyyy")){
               Todaytasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
               it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (1).jpeg"));
               it->setText(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
               model1->appendRow(it);
               ui->listView1->setModel(model1);

           }
           else{
               Pendingtasks.append(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());
               it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01.jpeg"));
               it->setText(T.ui->Description->text()+":"+ T.ui->date->date().toString("ddd MMMM d yyyy")+":"+ T.ui->tag->currentText());

               model2->appendRow(it);
               ui->listView2->setModel(model2);
           }
    T.close();

      }
    else
        QMessageBox::critical(this,"faaaaalse","Canceled");

}

void taskmanager::on_listView2_doubleClicked(const QModelIndex &index)
{
    QRegExp rx("(\\:)");
    QStringList query = Pendingtasks.at(index.row()).split(rx);
    task T;
    QDate date;
    T.ui->date->setDate(date.fromString(query.at(1),"ddd MMMM d yyyy"));
    T.ui->Description->setText(query.at(0));
    T.ui->tag->setCurrentIndex(T.ui->tag->findText(query.at(2)));
    T.exec();
      QStandardItem *it = new QStandardItem();
    if(T.logic){
        Pendingtasks.removeAt(index.row());

        model2->removeRow(index.row());
         savePendingContent(&apres);

           if(T.ui->fincheck->isChecked()){

              Finishedtasks.append(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
              it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (2).jpeg"));
              it->setText(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());

              model3->appendRow(it);
              ui->listView3->setModel(model3);


           }else if(T. ui->date->date().toString("ddd MMMM d yyyy")==QDate::currentDate().toString("ddd MMMM d yyyy")){
               Todaytasks.append(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
               it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (1).jpeg"));
               it->setText(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
               model1->appendRow(it);
               ui->listView1->setModel(model1);

           }
           else{
               Pendingtasks.append(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
               it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01.jpeg"));
               it->setText(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());

               model2->appendRow(it);
               ui->listView2->setModel(model2);
           }
    T.close();

      }
    else
        QMessageBox::critical(this,"faaaaalse","Canceled");

}


void taskmanager::on_listView3_doubleClicked(const QModelIndex &index)
{
    QRegExp rx("(\\:)");
    QStringList query = Finishedtasks.at(index.row()).split(rx);
    task T;
    QDate date;
    T.ui->date->setDate( date.fromString(query.at(1),"ddd MMMM d yyyy"));
    T.ui->Description->setText(query.at(0));
    T.ui->tag->setCurrentIndex(T.ui->tag->findText(query.at(2)));
    T.ui->fincheck->setChecked(true);
    T.exec();
      QStandardItem *it = new QStandardItem();
    if(T.logic){
        Finishedtasks.removeAt(index.row());
        model3->removeRow(index.row());
         saveFinishedContent(&salaw);
           if(T.ui->fincheck->isChecked()){

              Finishedtasks.append(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
              it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (2).jpeg"));
              it->setText(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
              model3->appendRow(it);
              ui->listView3->setModel(model3);
           }else if(T. ui->date->date().toString("ddd MMMM d yyyy")==QDate::currentDate().toString("ddd MMMM d yyyy")){
               Todaytasks.append(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
               it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01 (1).jpeg"));
               it->setText(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
               model1->appendRow(it);
               ui->listView1->setModel(model1);
           }
           else{
               Pendingtasks.append(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());
               it->setIcon(QPixmap(":/new/prefix1/icone2/WhatsApp Image 2022-01-21 at 21.52.01.jpeg"));
               it->setText(T.ui->Description->text()+" : "+ T.ui->date->date().toString("ddd MMMM d yyyy")+" :"+ T.ui->tag->currentText());

               model2->appendRow(it);
               ui->listView2->setModel(model2);
           }
    T.close();
      }
    else
        QMessageBox::critical(this,"faaaaalse","Canceled");

}

