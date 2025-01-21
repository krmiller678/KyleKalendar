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

    // Note to self -> definitely want to convert all this into an unordered_map at some point with days as keys

    //mondayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    //tuesdayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    //wednesdayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    //thursdayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    //fridayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    //saturdayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));
    //sundayEvents.push_back(Event("11 am to ", "12 pm: ", "NapTime!"));

    //EventWriteOut(mondayEvents, "Monday");
    //EventWriteOut(tuesdayEvents, "Tuesday");
    //EventWriteOut(wednesdayEvents, "Wednesday");
    //EventWriteOut(thursdayEvents, "Thursday");
    //EventWriteOut(fridayEvents, "Friday");
    //EventWriteOut(saturdayEvents, "Saturday");
    //EventWriteOut(sundayEvents, "Sunday");

    //weeklyToDos.push_back(ToDo("test"));
    //financialToDos.push_back(ToDo("test"));
    //personalToDos.push_back(ToDo("test"));

    //ToDoWriteOut(weeklyToDos, "Weekly");
    //ToDoWriteOut(financialToDos, "Financial");
    //ToDoWriteOut(personalToDos, "Personal");

    return a.exec();
}
