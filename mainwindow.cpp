#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <QKeyEvent>
#include <QEventLoop>
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
    EventWriteOut(mondayEvents, "Monday");

    ui->DailyEdit->setVisible(false);
    ui->FinancialEdit->setVisible(false);
    ui->WeeklyEdit->setVisible(false);
    ui->ImportantEdit->setVisible(false);

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
        AddItemDaily(sundayEvents[i].GetTitle());
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
            throw invalid_argument( "error writing file. \n");
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
            throw invalid_argument( "error writing file. \n");
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

void MainWindow::on_Sunday_clicked()
{
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < sundayEvents.size(); i++) {
        AddItemDaily(sundayEvents[i].GetTitle());
    }
    //auto f = ui->FinancialToDo->currentItem()->font();
    //f.setStrikeOut(true);
    //ui->FinancialToDo->currentItem()->setFont(f);
}

void MainWindow::on_Monday_clicked()
{
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < mondayEvents.size(); i++) {
        AddItemDaily(mondayEvents[i].GetTitle());
    }
}

void MainWindow::on_Tuesday_clicked()
{
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < tuesdayEvents.size(); i++) {
        AddItemDaily(tuesdayEvents[i].GetTitle());
    }
}

void MainWindow::on_Wednesday_clicked()
{
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < wednesdayEvents.size(); i++) {
        AddItemDaily(wednesdayEvents[i].GetTitle());
    }
}

void MainWindow::on_Thursday_clicked()
{
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < thursdayEvents.size(); i++) {
        AddItemDaily(thursdayEvents[i].GetTitle());
    }
}

void MainWindow::on_Friday_clicked()
{
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < fridayEvents.size(); i++) {
        AddItemDaily(fridayEvents[i].GetTitle());
    }
}

void MainWindow::on_Saturday_clicked()
{
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < saturdayEvents.size(); i++) {
        AddItemDaily(saturdayEvents[i].GetTitle());
    }
}

void MainWindow::on_ImportantDates_itemDoubleClicked(QListWidgetItem *item)
{
    ui->ImportantEdit->setHidden(false);
    ui->ImportantEdit->setEnabled(true);
    ui->ImportantEdit->setFocus();
    QString newAdd = GetNewInputImportant();
    ui->ImportantEdit->setHidden(true);
    ui->ImportantEdit->setEnabled(false);
    ui->ImportantEdit->clear();
    item->setText(newAdd);
}

QString MainWindow::GetNewInputImportant() {
    QEventLoop loop;

    // Create a lambda function to handle key presses
    connect(this, &MainWindow::EnterKeyPressed, &loop, &QEventLoop::quit);

    // Run the loop until the Enter key is pressed
    loop.exec();

    // Return the text from the UI element
    return ui->ImportantEdit->text();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        emit EnterKeyPressed();
    }
    if (event->key() == Qt::Key_Delete) {
        // Get the widget that currently has focus
        QWidget* focusedWidget = this->focusWidget();
        // Check if the focused widget is a QListWidget
        if (QListWidget* listWidget = qobject_cast<QListWidget*>(focusedWidget)) {
            QListWidgetItem* selectedItem = listWidget->currentItem();  // Get the selected item
            if (selectedItem) {
                delete selectedItem;  // Delete the selected item
            }
        }
    }
    QMainWindow::keyPressEvent(event);  // Pass the event to the base class
}
