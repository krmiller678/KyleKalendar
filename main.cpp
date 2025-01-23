#include "mainwindow.h"

/*
This program is designed to serve as a weekly calendar to keep track of important events,
enable a to-do list to be constructed from stored memory, and keep track of long term goals.
Inspired by Kyle's Office Chalkboard :D
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("KyleKalendar");
    w.show();

    return a.exec();
}
