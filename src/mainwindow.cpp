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

    ui->DailyEdit->setVisible(false);
    ui->FinancialEdit->setVisible(false);
    ui->WeeklyEdit->setVisible(false);
    ui->ImportantEdit->setVisible(false);

    AddItemImportant(personalToDos);
    AddItemWeekly(weeklyToDos);
    AddItemFinancial(financialToDos);

    for (unsigned int i = 0; i < sundayEvents.size(); i++) {
        AddItemDaily(sundayEvents[i].GetTitle());
    }

    currentDay = &sundayEvents;

}

// A part of the destructor sequence need to be a pop up to call the write back functions
MainWindow::~MainWindow()
{
    writeBackFinancial();
    writeBackPersonal();
    writeBackWeekly();
    ToDoWriteOut(weeklyToDos, "Weekly");
    ToDoWriteOut(financialToDos, "Financial");
    ToDoWriteOut(personalToDos, "Personal");

    writeBackDailyChange();
    EventWriteOut(mondayEvents, "Monday");
    EventWriteOut(tuesdayEvents, "Tuesday");
    EventWriteOut(wednesdayEvents, "Wednesday");
    EventWriteOut(thursdayEvents, "Thursday");
    EventWriteOut(fridayEvents, "Friday");
    EventWriteOut(saturdayEvents, "Saturday");
    EventWriteOut(sundayEvents, "Sunday");

    delete ui;
}

// AddItem methods -> toDos now store strikeout state
void MainWindow::AddItemImportant(std::vector<ToDo>& toDos) {
    for (unsigned int i = 0; i < toDos.size(); i++) {
        QString newAdd(toDos[i].GetTitle().c_str());
        QListWidgetItem* item = new QListWidgetItem(newAdd);
        auto f = item->font();
        f.setStrikeOut(toDos[i].GetCrossOut());
        item->setFont(f);  // Strikeout the selected item
        ui->ImportantDates->addItem(item);
    }
}
void MainWindow::AddItemWeekly(std::vector<ToDo>& toDos) {
    for (unsigned int i = 0; i < toDos.size(); i++) {
        QString newAdd(toDos[i].GetTitle().c_str());
        QListWidgetItem* item = new QListWidgetItem(newAdd);
        auto f = item->font();
        f.setStrikeOut(toDos[i].GetCrossOut());
        item->setFont(f);  // Strikeout the selected item
        ui->WeeklyToDo->addItem(item);
    }
}
void MainWindow::AddItemFinancial(std::vector<ToDo>& toDos) {
    for (unsigned int i = 0; i < toDos.size(); i++) {
        QString newAdd(toDos[i].GetTitle().c_str());
        QListWidgetItem* item = new QListWidgetItem(newAdd);
        auto f = item->font();
        f.setStrikeOut(toDos[i].GetCrossOut());
        item->setFont(f);  // Strikeout the selected item
        ui->FinancialToDo->addItem(item);
    }
}
void MainWindow::AddItemDaily(std::string toAdd) {
    QString newAdd(toAdd.c_str());
    ui->DailyEvents->addItem(newAdd);
}

// Read in and write out vector functions
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

// Day of the week changed -> change current day and write back to vector
void MainWindow::on_Sunday_clicked()
{
    resetDayFont();
    ui->Sunday->setFlat(true);
    writeBackDailyChange();
    currentDay = &sundayEvents;
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < sundayEvents.size(); i++) {
        AddItemDaily(sundayEvents[i].GetTitle());
    }
}
void MainWindow::on_Monday_clicked()
{
    resetDayFont();
    ui->Monday->setFlat(true);
    writeBackDailyChange();
    currentDay = &mondayEvents;
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < mondayEvents.size(); i++) {
        AddItemDaily(mondayEvents[i].GetTitle());
    }
}
void MainWindow::on_Tuesday_clicked()
{
    resetDayFont();
    ui->Tuesday->setFlat(true);
    writeBackDailyChange();
    currentDay = &tuesdayEvents;
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < tuesdayEvents.size(); i++) {
        AddItemDaily(tuesdayEvents[i].GetTitle());
    }
}
void MainWindow::on_Wednesday_clicked()
{
    resetDayFont();
    ui->Wednesday->setFlat(true);
    writeBackDailyChange();
    currentDay = &wednesdayEvents;
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < wednesdayEvents.size(); i++) {
        AddItemDaily(wednesdayEvents[i].GetTitle());
    }
}
void MainWindow::on_Thursday_clicked()
{
    resetDayFont();
    ui->Thursday->setFlat(true);
    writeBackDailyChange();
    currentDay = &thursdayEvents;
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < thursdayEvents.size(); i++) {
        AddItemDaily(thursdayEvents[i].GetTitle());
    }
}
void MainWindow::on_Friday_clicked()
{
    resetDayFont();
    ui->Friday->setFlat(true);
    writeBackDailyChange();
    currentDay = &fridayEvents;
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < fridayEvents.size(); i++) {
        AddItemDaily(fridayEvents[i].GetTitle());
    }
}
void MainWindow::on_Saturday_clicked()
{
    resetDayFont();
    ui->Saturday->setFlat(true);
    writeBackDailyChange();
    currentDay = &saturdayEvents;
    ui->DailyEvents->clear();
    for (unsigned int i = 0; i < saturdayEvents.size(); i++) {
        AddItemDaily(saturdayEvents[i].GetTitle());
    }
}
void MainWindow::writeBackDailyChange() {
    currentDay->clear();
    emit EnterKeyPressed();
    for (unsigned int i = 0; i < ui->DailyEvents->count(); i++) {
        QListWidgetItem* item = ui->DailyEvents->item(i);
        string toAdd = item->text().toStdString();
        currentDay->push_back(Event("0","0",toAdd));
    }
}
void MainWindow::resetDayFont() {
    ui->Monday->setFlat(false);
    ui->Tuesday->setFlat(false);
    ui->Wednesday->setFlat(false);
    ui->Thursday->setFlat(false);
    ui->Friday->setFlat(false);
    ui->Saturday->setFlat(false);
    ui->Sunday->setFlat(false);
}

// Write backs for toDos
void MainWindow::writeBackWeekly() {
    weeklyToDos.clear();
    for (unsigned int i = 0; i < ui->WeeklyToDo->count(); i++) {
        QListWidgetItem* item = ui->WeeklyToDo->item(i);
        string toAdd = item->text().toStdString();
        auto f = item->font();
        weeklyToDos.push_back(ToDo(toAdd, f.strikeOut()));
    }
}
void MainWindow::writeBackFinancial() {
    financialToDos.clear();
    for (unsigned int i = 0; i < ui->FinancialToDo->count(); i++) {
        QListWidgetItem* item = ui->FinancialToDo->item(i);
        string toAdd = item->text().toStdString();
        auto f = item->font();
        financialToDos.push_back(ToDo(toAdd, f.strikeOut()));
    }
}
void MainWindow::writeBackPersonal() {
    personalToDos.clear();
    for (unsigned int i = 0; i < ui->ImportantDates->count(); i++) {
        QListWidgetItem* item = ui->ImportantDates->item(i);
        string toAdd = item->text().toStdString();
        auto f = item->font();
        personalToDos.push_back(ToDo(toAdd, f.strikeOut()));
    }
}

// Double click to edit loops
void MainWindow::on_ImportantDates_itemDoubleClicked(QListWidgetItem *item)
{
    ui->ImportantEdit->setHidden(false);
    ui->ImportantEdit->setEnabled(true);
    ui->ImportantEdit->setFocus();
    QString newAdd = GetNewInputImportant();
    if (newAdd == "") {newAdd = item->text();}
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
void MainWindow::on_FinancialToDo_itemDoubleClicked(QListWidgetItem *item)
{
    ui->FinancialEdit->setHidden(false);
    ui->FinancialEdit->setEnabled(true);
    ui->FinancialEdit->setFocus();
    QString newAdd = GetNewInputFinancial();
    if (newAdd == "") {newAdd = item->text();}
    ui->FinancialEdit->setHidden(true);
    ui->FinancialEdit->setEnabled(false);
    ui->FinancialEdit->clear();
    item->setText(newAdd);
}
QString MainWindow::GetNewInputFinancial() {
    QEventLoop loop;

    // Create a lambda function to handle key presses
    connect(this, &MainWindow::EnterKeyPressed, &loop, &QEventLoop::quit);

    // Run the loop until the Enter key is pressed
    loop.exec();

    // Return the text from the UI element
    return ui->FinancialEdit->text();
}
void MainWindow::on_WeeklyToDo_itemDoubleClicked(QListWidgetItem *item)
{
    ui->WeeklyEdit->setHidden(false);
    ui->WeeklyEdit->setEnabled(true);
    ui->WeeklyEdit->setFocus();
    QString newAdd = GetNewInputWeekly();
    if (newAdd == "") {newAdd = item->text();}
    ui->WeeklyEdit->setHidden(true);
    ui->WeeklyEdit->setEnabled(false);
    ui->WeeklyEdit->clear();
    item->setText(newAdd);
}
QString MainWindow::GetNewInputWeekly() {
    QEventLoop loop;

    // Create a lambda function to handle key presses
    connect(this, &MainWindow::EnterKeyPressed, &loop, &QEventLoop::quit);

    // Run the loop until the Enter key is pressed
    loop.exec();

    // Return the text from the UI element
    return ui->WeeklyEdit->text();
}
void MainWindow::on_DailyEvents_itemDoubleClicked(QListWidgetItem *item)
{
    ui->DailyEdit->setHidden(false);
    ui->DailyEdit->setEnabled(true);
    ui->DailyEdit->setFocus();
    QString newAdd = GetNewInputDaily();
    if (newAdd == "") {newAdd = item->text();}
    ui->DailyEdit->setHidden(true);
    ui->DailyEdit->setEnabled(false);
    ui->DailyEdit->clear();
    item->setText(newAdd);
}
QString MainWindow::GetNewInputDaily() {
    QEventLoop loop;

    // Create a lambda function to handle key presses
    connect(this, &MainWindow::EnterKeyPressed, &loop, &QEventLoop::quit);

    // Run the loop until the Enter key is pressed
    loop.exec();

    // Return the text from the UI element
    return ui->DailyEdit->text();
}

// Add button for each QListWidget
void MainWindow::on_AddImportant_clicked()
{
    ui->ImportantEdit->setHidden(false);
    ui->ImportantEdit->setEnabled(true);
    ui->ImportantEdit->setFocus();
    QString newAdd = GetNewInputImportant();
    ui->ImportantEdit->setHidden(true);
    ui->ImportantEdit->setEnabled(false);
    ui->ImportantEdit->clear();
    ui->ImportantDates->addItem(newAdd);
}
void MainWindow::on_AddFinancial_clicked()
{
    ui->FinancialEdit->setHidden(false);
    ui->FinancialEdit->setEnabled(true);
    ui->FinancialEdit->setFocus();
    QString newAdd = GetNewInputFinancial();
    ui->FinancialEdit->setHidden(true);
    ui->FinancialEdit->setEnabled(false);
    ui->FinancialEdit->clear();
    ui->FinancialToDo->addItem(newAdd);
}
void MainWindow::on_AddDaily_clicked()

{
    ui->DailyEdit->setHidden(false);
    ui->DailyEdit->setEnabled(true);
    ui->DailyEdit->setFocus();
    QString newAdd = GetNewInputDaily();
    ui->DailyEdit->setHidden(true);
    ui->DailyEdit->setEnabled(false);
    ui->DailyEdit->clear();
    ui->DailyEvents->addItem(newAdd);
}
void MainWindow::on_AddWeekly_clicked()
{
    ui->WeeklyEdit->setHidden(false);
    ui->WeeklyEdit->setEnabled(true);
    ui->WeeklyEdit->setFocus();
    QString newAdd = GetNewInputWeekly();
    ui->WeeklyEdit->setHidden(true);
    ui->WeeklyEdit->setEnabled(false);
    ui->WeeklyEdit->clear();
    ui->WeeklyToDo->addItem(newAdd);
}

// keyPressEvent -> overrides parent class: Enter/Return, Del, Shift
void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        emit EnterKeyPressed();
    }
    if (event->key() == Qt::Key_Delete) {
        emit EnterKeyPressed(); // So that you don't delete a cell while editing
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
    if (event->key() == Qt::Key_Shift) {
        // Get the widget that currently has focus
        QWidget* focusedWidget = this->focusWidget();
        // Check if the focused widget is a QListWidget
        if (QListWidget* listWidget = qobject_cast<QListWidget*>(focusedWidget)) {
            QListWidgetItem* selectedItem = listWidget->currentItem();  // Get the selected item
            if (selectedItem) {
                auto f = selectedItem->font();
                f.setStrikeOut(!f.strikeOut());
                selectedItem->setFont(f);  // Strikeout the selected item
            }
        }
    }

    QMainWindow::keyPressEvent(event);  // Pass the event to the base class
}
