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
    void AddItemImportant(std::vector<ToDo>& toDos);
    void AddItemWeekly(std::vector<ToDo>& toDos);
    void AddItemFinancial(std::vector<ToDo>& toDos);
    void AddItemDaily(std::string toAdd);

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

    void on_FinancialToDo_itemDoubleClicked(QListWidgetItem *item);

    void on_WeeklyToDo_itemDoubleClicked(QListWidgetItem *item);

    void on_DailyEvents_itemDoubleClicked(QListWidgetItem *item);

    void on_AddImportant_clicked();

    void on_AddFinancial_clicked();

    void on_AddDaily_clicked();

    void on_AddWeekly_clicked();

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

    std::vector<Event>* currentDay;

    QString GetNewInputImportant(); // helper function for editing events and todos
    QString GetNewInputFinancial();
    QString GetNewInputWeekly();
    QString GetNewInputDaily();

    void keyPressEvent(QKeyEvent* event) override; // key sensing

    void writeBackDailyChange(); // helper function for day changes
    void writeBackFinancial();
    void writeBackPersonal();
    void writeBackWeekly();

    Ui::MainWindow *ui;

    // pulled over from main -> read in and write out functions
    void EventReadIn(std::vector<Event>& dailyEvents, std::string dayOfWeek);
    void EventWriteOut(std::vector<Event>& dailyEvents, std::string dayOfWeek);
    void ToDoReadIn(std::vector<ToDo>& toDos, std::string toDoCategory);
    void ToDoWriteOut(std::vector<ToDo>& toDos, std::string toDoCategory);
};
#endif // MAINWINDOW_H
