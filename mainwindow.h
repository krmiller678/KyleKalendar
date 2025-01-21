#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QString>

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


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
