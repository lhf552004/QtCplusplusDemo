#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worker.h"
//#include <QThread>
#include <QProgressBar>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_myButton_clicked();

    void on_secondButton_clicked();

    void on_testButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_watcherButton_clicked();

    void on_templateButton_clicked();

    void on_loadTableButton_clicked();

private:
    Ui::MainWindow *ui;
    QThread *workerThread;  // Thread to run the worker
    Worker *worker;  // Worker object to perform the task
};
#endif // MAINWINDOW_H
