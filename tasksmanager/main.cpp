#include "taskmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    taskmanager w;

    w.show();
    return a.exec();
}
