#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "singletondemo.h"
#include <iostream>
#include "ListNode.h"
#include "threadsafequeue.h"
#include <thread>
#include <vector>
#include "matrix_multiplication.h"
#include "invalid_argument_exception.h"
#include "merge_sort.h"
#include "graph.h"
#include "mystring.h"

#include <QStyle>
#include <QFileDialog>
#include <QTextStream>
#include "dragdropwindow.h"
#include "filesystemmonitor.h"
#include "Base.h"
#include <memory>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set default icons using standard icons
    ui->actionOpen->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionSave->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton));
    ui->actionQuit->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCloseButton));
    ui->actionCopy->setIcon(QApplication::style()->standardIcon(QStyle::SP_FileDialogNewFolder));
    ui->actionPaste->setIcon(QApplication::style()->standardIcon(QStyle::SP_FileDialogNewFolder));
    ui->actionRedo->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowForward));
    ui->actionUndo->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowBack));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void validateInput(int number) {
    if (number < 0) {
        throw InvalidArgumentException("Invalid input: number cannot be negative.");
    }
    std::cout << "Valid input: " << number << std::endl;
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
    SingletonDemo* s1 = SingletonDemo::getInstance();
    SingletonDemo* s2 = SingletonDemo::getInstance();
    // Should output the same address, confirming both pointers point to the same instance
    std::cout << "Instance 1 address: " << s1 << std::endl;
    std::cout << "Instance 2 address: " << s2 << std::endl;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    ListNode* reversedHead = reverseList(head);

    std::cout << "Reversed List: ";
    printList(reversedHead);

    ThreadSafeQueue<int> queue;

    // Producer thread that pushes elements into the queue
    std::thread producer([&queue]() {
        for (int i = 0; i < 5; ++i) {
            queue.push(i);
            std::cout << "Produced: " << i << std::endl;
        }
    });

    // Consumer thread that pops elements from the queue
    std::thread consumer([&queue]() {
        for (int i = 0; i < 5; ++i) {
            int value;
            queue.wait_and_pop(value);
            std::cout << "Consumed: " << value << std::endl;
        }
    });

    producer.join();
    consumer.join();


    // Define two matrices
    std::vector<std::vector<int>> matrixA = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::vector<std::vector<int>> matrixB = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    try {
        // Multiply the matrices
        std::vector<std::vector<int>> result = multiplyMatrices(matrixA, matrixB);

        // Print the result
        std::cout << "Result matrix:" << std::endl;
        for (const auto& row : result) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Test with valid input
        validateInput(10);

        // Test with invalid input
        validateInput(-5);
    } catch (const InvalidArgumentException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(arr); // Sort the array

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    Graph g;

    // Add edges to the graph
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    int start = 1;
    int end = 6;

    // Find and print the shortest path between start and end
    g.findShortestPath(start, end);

    MyString str1("Hello");
    MyString str2("World");

    // Test concatenation
    MyString s3 = str1 + ", " + str2 + "!";
    std::cout << "Concatenated string: " << s3 << std::endl;

    // Test comparison
    MyString s4("Hello");
    std::cout << "s1 and s4 are " << (str1 == s4 ? "equal" : "not equal") << std::endl;

    // Test length
    std::cout << "Length of s3: " << s3.length() << std::endl;

    // Test substring
    MyString sub = s3.substring(7, 5);
    std::cout << "Substring of s3: " << sub << std::endl;


    QMessageBox::information(this, "Button Clicked", "You clicked the button!");
}



void MainWindow::on_secondButton_clicked()
{

}


void MainWindow::on_testButton_clicked()
{
    ui->testButton->setText("Button clicked");

    DragDropWindow* window = new DragDropWindow();
    window->show();
    window->raise();  // Bring it to the front
    window->activateWindow();  // Give it focus
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) return;  // User cancelled the dialog

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file: " + file.errorString());
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) return;  // User cancelled the dialog

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot save file: " + file.errorString());
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
}


void MainWindow::on_watcherButton_clicked()
{
    FileSystemMonitor* window = new FileSystemMonitor();
    window->show();
    window->raise();  // Bring it to the front
    window->activateWindow();  // Give it focus
}


void MainWindow::on_templateButton_clicked()
{
    auto d = std::make_unique<Derived>();
    d->interface();  // Output: "Derived implementation"
}


void MainWindow::on_loadTableButton_clicked()
{
    // Create a standard item model with 5 rows and 3 columns
    QStandardItemModel *model = new QStandardItemModel(5, 3);

    // Set headers for the columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Age")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Occupation")));

    // Populate data in the model
    model->setItem(0, 0, new QStandardItem(QString("John Doe")));
    model->setItem(0, 1, new QStandardItem(QString("30")));
    model->setItem(0, 2, new QStandardItem(QString("Engineer")));

    model->setItem(1, 0, new QStandardItem(QString("Jane Smith")));
    model->setItem(1, 1, new QStandardItem(QString("25")));
    model->setItem(1, 2, new QStandardItem(QString("Designer")));

    model->setItem(2, 0, new QStandardItem(QString("Alice Johnson")));
    model->setItem(2, 1, new QStandardItem(QString("27")));
    model->setItem(2, 2, new QStandardItem(QString("Writer")));

    // Set the model to the QTableView
    ui->tableView->setModel(model);

    // Show the QTableView
    ui->tableView->show();
}

