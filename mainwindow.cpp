#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "singletondemo.h"
#include <iostream>
#include "ListNode.h"
#include "threadsafequeue.h"
#include <thread>
#include <vector>

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


    QMessageBox::information(this, "Button Clicked", "You clicked the button!");
}


