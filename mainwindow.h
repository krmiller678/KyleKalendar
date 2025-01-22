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

signals:
    void EnterKeyPressed();  // Declare the signal

private slots:
    // Daily selector
    void on_Sunday_clicked();
    void on_Monday_clicked();
    void on_Tuesday_clicked();
    void on_Wednesday_clicked();
    void on_Thursday_clicked();
    void on_Friday_clicked();
    void on_Saturday_clicked();

    void on_ImportantDates_itemDoubleClicked(QListWidgetItem *item);

private:
    // private variables - dailyEvents and toDos
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

    std::vector<Event> currentDay = sundayEvents;

    QString GetNewInputImportant();
    void keyPressEvent(QKeyEvent* event);

    Ui::MainWindow *ui;

    // pulled over from main -> read in and write out functions
    void EventReadIn(std::vector<Event>& dailyEvents, std::string dayOfWeek);
    void EventWriteOut(std::vector<Event>& dailyEvents, std::string dayOfWeek);

    void ToDoReadIn(std::vector<ToDo>& toDos, std::string toDoCategory);
    void ToDoWriteOut(std::vector<ToDo>& toDos, std::string toDoCategory);
};
#endif // MAINWINDOW_H
