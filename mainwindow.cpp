#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <sstream>
#include <exception>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    EventReadIn(mondayEvents, "Monday");
    EventReadIn(tuesdayEvents, "Tuesday");
    EventReadIn(wednesdayEvents, "Wednesday");
    EventReadIn(thursdayEvents, "Thursday");
    EventReadIn(fridayEvents, "Friday");
    EventReadIn(saturdayEvents, "Saturday");
    EventReadIn(sundayEvents, "Sunday");

    ToDoReadIn(weeklyToDos, "Weekly");
    ToDoReadIn(financialToDos, "Financial");
    ToDoReadIn(personalToDos, "Personal");

    for (unsigned int i = 0; i < personalToDos.size(); i++) {
        AddItemImportant(personalToDos[i].GetTitle());
    }
    for (unsigned int i = 0; i < weeklyToDos.size(); i++) {
        AddItemWeekly(weeklyToDos[i].GetTitle());
    }
    for (unsigned int i = 0; i < financialToDos.size(); i++) {
        AddItemFinancial(financialToDos[i].GetTitle());
    }
    for (unsigned int i = 0; i < financialToDos.size(); i++) {
        AddItemDaily(mondayEvents[i].GetTitle());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddItemImportant(std::string toAdd) {
    QString newAdd(toAdd.c_str());
    ui->ImportantDates->addItem(newAdd);
}

void MainWindow::AddItemWeekly(std::string toAdd) {
    QString newAdd(toAdd.c_str());
    ui->WeeklyToDo->addItem(newAdd);
}

void MainWindow::AddItemFinancial(std::string toAdd) {
    QString newAdd(toAdd.c_str());
    ui->FinancialToDo->addItem(newAdd);
}

void MainWindow::AddItemDaily(std::string toAdd) {
    QString newAdd(toAdd.c_str());
    ui->DailyEvents->addItem(newAdd);
}

void MainWindow::on_Sunday_clicked()
{
    ui->DailyEvents->clear();
    auto f = ui->FinancialToDo->currentItem()->font();
    f.setStrikeOut(true);
    ui->FinancialToDo->currentItem()->setFont(f);
}

void MainWindow::EventWriteOut(vector<Event>& dailyEvents, string dayOfWeek) {
    string fullPath = "events/" + dayOfWeek + ".txt";
    ofstream outputFile(fullPath);
    if (outputFile.is_open()) {
        for (const Event& event : dailyEvents) {
            outputFile << event.GetStartTime() << ',' << event.GetEndTime() << ',' << event.GetTitle() << '\n';
        }
    }
    else {
        try {
            throw invalid_argument( "error opening file. \n");
        }
        catch (invalid_argument& e) {
            cout << "Caught exception: " << e.what() << '\n';
        }
    }
}

void MainWindow::EventReadIn(vector<Event>& dailyEvents, string dayOfWeek) {
    string fullPath = "events/" + dayOfWeek + ".txt";
    ifstream inputFile(fullPath);
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string start, end, title;
        getline(ss, start,',');
        getline(ss, end,',');
        getline(ss, title);

        dailyEvents.push_back(Event(start,end,title));
    }
}

void MainWindow::ToDoWriteOut(vector<ToDo>& toDos, string toDoCategory) {
    string fullPath = "toDos/" + toDoCategory + ".txt";
    ofstream outputFile(fullPath);
    if (outputFile.is_open()) {
        for (const ToDo& toDo : toDos) {
            outputFile << toDo.GetTitle() << "," << toDo.GetCrossOut() << '\n';
        }
    }
    else {
        try {
            throw invalid_argument( "error opening file. \n");
        }
        catch (invalid_argument& e) {
            cout << "Caught exception: " << e.what() << '\n';
        }
    }
}

void MainWindow::ToDoReadIn(vector<ToDo>& toDos, string toDoCategory) {
    string fullPath = "toDos/" + toDoCategory + ".txt";
    ifstream inputFile(fullPath);
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string title, crossout;
        getline(ss, title,',');
        getline(ss, crossout,',');

        toDos.push_back(ToDo(title,(crossout != "0")));
    }
}

