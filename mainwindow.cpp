#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_myButton_clicked()
{
    // Check the current style sheet and toggle the color
    QString currentColor = ui->myButton->styleSheet();

    if (currentColor.contains("red")) {
        ui->myButton->setStyleSheet("background-color: blue;");
    } else {
        ui->myButton->setStyleSheet("background-color: red;");
    }

    QMessageBox::information(this, "Button Clicked", "You clicked the button!");
}


