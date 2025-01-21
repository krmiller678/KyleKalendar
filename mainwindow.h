#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlistwidget.h>
#include <string>
#include <QString>
#include "Event.h"
#include "ToDo.h"
#include <QApplication>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Setters
    void AddItemImportant(std::string toAdd);
    void AddItemWeekly(std::string toAdd);
    void AddItemFinancial(std::string toAdd);
    void AddItemDaily(std::string toAdd);

    // Getters


private slots:
    void on_Sunday_clicked();

private:
    // private variables
    std::vector<Event> mondayEvents;
    std::vector<Event> tuesdayEvents;
    std::vector<Event> wednesdayEvents;
    std::vector<Event> thursdayEvents;
    std::vector<Event> fridayEvents;
    std::vector<Event> saturdayEvents;
    std::vector<Event> sundayEvents;

    std::vector<ToDo> weeklyToDos;
    std::vector<ToDo> financialToDos;
    std::vector<ToDo> personalToDos;

    Ui::MainWindow *ui;

    // pulled over from main -> read in and write out functions
    void EventReadIn(std::vector<Event>& dailyEvents, std::string dayOfWeek);
    void EventWriteOut(std::vector<Event>& dailyEvents, std::string dayOfWeek);

    void ToDoReadIn(std::vector<ToDo>& toDos, std::string toDoCategory);
    void ToDoWriteOut(std::vector<ToDo>& toDos, std::string toDoCategory);
};
#endif // MAINWINDOW_H
