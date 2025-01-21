#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ImportantDates->addItem("test");
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
