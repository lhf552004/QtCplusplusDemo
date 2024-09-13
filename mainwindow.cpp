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
#include <QtConcurrent>
#include <QFuture>
#include <QDebug>
#include <QStandardItemModel>
#include "simplesmartpointer.h"
#include "utils.h"
#include "stack.h"
#include "lru.h"
#include "longest_palindrome.h"

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

int computeSum(int a, int b) {
    return a + b;
}

std::string reverseString(const std::string& input) {

    std::string reversed = input; // Create a copy of the input string
    int start = 0;
    int len = reversed.length();
    char temp;
    for(start =0; start< len/2; start++ ) {
        temp = reversed[start];
        reversed[start] = reversed[len - start - 1];
        reversed[len - start - 1] = temp;
    }

    return reversed;
}

int findMaxElement(const std::vector<int>& numbers) {
    int maxium = INT_MIN;
    for(int i =0; i< numbers.size(); i++) {
        int item = numbers.at(i);
        if(maxium < item) {
            maxium = item;
        }
    }
    return maxium;
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for(int i = 2; i <= std::sqrt(number); i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}
// dynamically allocates an integer array of the given size using pointers.
void allocateArray(int* arr, int size) {
    arr = new int[size];
}

// Function to free the dynamically allocated integer array
void freeArray(int* arr) {
    delete[] arr; // Free the dynamically allocated memory
}

std::mutex mtx; // Mutex to protect shared resources
std::condition_variable cv; // Condition variable for synchronization
bool printEven = true; // Flag to control which thread prints

void printEvenNumbers() {
    for (int i = 0; i <= 100; i += 2) {
        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
        cv.wait(lock, [] { return printEven; }); // Wait until it's time to print even numbers

        std::cout << i << " "; // Print even number

        printEven = false; // Set flag to allow odd number printing
        cv.notify_one(); // Notify the other thread
    }
}

void printOddNumbers() {
    for (int i = 1; i < 100; i += 2) {
        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
        cv.wait(lock, [] { return !printEven; }); // Wait until it's time to print odd numbers

        std::cout << i << " "; // Print odd number

        printEven = true; // Set flag to allow even number printing
        cv.notify_one(); // Notify the other thread
    }
}

template<typename T>
T maxValue(T val1, T val2) {
    return val1 > val2? val1: val2;
}

void readFiles(std::string file1, std::string file2) {

}

int lengthOfLongestSubstring2(std::string s) {
    std::unordered_map<char, int> charIndexMap;
    int maxLength = 0, start = 0;

    for (int i = 0; i < s.length(); i++) {
        if (charIndexMap.find(s[i]) != charIndexMap.end()) {
            start = std::max(start, charIndexMap[s[i]] + 1);
        }
        charIndexMap[s[i]] = i;
        maxLength = std::max(maxLength, i - start + 1);
    }

    return maxLength;
}

int lengthOfLongestSubstring(std::string s) {
    int len= s.length();
    if(len == 0) return 0;
    int max_len = 1;
    std::unordered_map<char, int> map;
    int k = 0;
    for(int i = 0; i < len; i++) {
        std::cout << "i: " << i << std::endl;
        if(map.find(s[i]) == map.end()) {
            map[s[i]] = i;
//            std::cout <<"i: "<< i << ", " << s[i] <<" is not in the map, added." << std::endl;
        }
        if(k <= i) k = i+1;
        while(k < len) {
            std::cout << "k: " << k << std::endl;
            if(map.find(s[k]) == map.end()) {
                map[s[k]] = k;
                max_len = std::max(k-i+1, max_len);
//                std::cout <<"k: "<< k << ", " << s[k] <<" is not in the map, added." << std::endl;
            }else {
                map.erase(s[k]);
                break;
            }
            k++;
        }
      \
    }
    return max_len;
}
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr; // Handle empty input

    ListNode* head = new ListNode(values[0]); // Initialize the head of the list
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]); // Create new node and link it
        current = current->next; // Move to the next node
    }

    return head;
}
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i=0, j = 0;
        std::vector<int> res;
        while(i < len1 && j < len2) {
            int cur;
            if(nums1[i] < nums2[j]) {
                cur = nums1[i];

                i++;
            }else {
                cur = nums2[j];
                j++;
            }
            res.push_back(cur);
        }

        for(;i< len1;i++) {
             res.push_back(nums1[i]);
        }

        for(;j< len2;j++) {
             res.push_back(nums2[j]);
        }

        int len = res.size();
        int middle_idx = len / 2;
        if(len % 2 == 0) {
            return (static_cast<double>(res[middle_idx - 1] + res[middle_idx]))/2;
        }else {
            return res[middle_idx];
        }
    }
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    ListNode* result = new ListNode();
    ListNode* ret = result;
    int overflow = 0;
    while(l1 != nullptr || l2 != nullptr) {

        int val1 = 0;
        int val2 = 0;
        if(l1 != nullptr) val1 = l1->val;
        if(l2 != nullptr) val2 = l2->val;
        int sum = val1 + val2 + overflow;
        int res_val = sum % 10;
        overflow = sum / 10;
        result->val = res_val;
        result->next = new ListNode(); // Create the next node
        result = result->next; // Move to the next node
        l1 = l1->next;
        l2 = l2->next;
    }
    // Handle any remaining overflow
    if (overflow > 0) {
         result->val = overflow; // Set the last node value if there is an overflow
    }
    return ret;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp; // Delete the current node
    }
}
void MainWindow::on_templateButton_clicked()
{
    //    auto d = std::make_unique<Derived>();
    //    d->interface();  // Output: "Derived implementation"

    //    std::string input = "This is a string";
    //    std::string output = reverseString(input);

    //    std::cout << input << std::endl;
    //    std::cout << output << std::endl;

    //    std::vector<int> numbers = {3, 5, 2, 9, 7, 1, 6};
    //    int theMax = findMaxElement(numbers);
    //    std::cout << "Max number in the vector: " << theMax << std::endl;

    //    int theNumber = 211;
    //    std::cout << "Is number: " << theNumber << " a prime number: "
    //              << (isPrime(theNumber) ? "Yes" : "No") << std::endl;

    //    int* myArray = nullptr;
    //    int size = 5;

    //    allocateArray(myArray, size);
    //    for (int i = 0; i < size; ++i) {
    //        myArray[i] = i * 2; // Assign values
    //    }

    //    std::cout << "Array elements: ";
    //    for (int i = 0; i < size; ++i) {
    //        std::cout << myArray[i] << " ";
    //    }
    //    std::cout << std::endl;
    //    freeArray(myArray);


    //    // Create a SimpleSmartPointer to manage a dynamically allocated integer
    //    SimpleSmartPointer<int> ptr(new int(42));
    //    std::cout << "Value: " << *ptr << std::endl; // Output: 42

    //    // Transfer ownership using move semantics
    //    SimpleSmartPointer<int> ptr2 = std::move(ptr);
    //    std::cout << "Value after move: " << *ptr2 << std::endl; // Output: 42

    //    // Use reset to manage a new resource
    //    ptr2.reset(new int(100));
    //    std::cout << "Value after reset: " << *ptr2 << std::endl; // Output: 100

    // Launch two threads
    //    std::thread evenThread(printEvenNumbers);
    //    std::thread oddThread(printOddNumbers);

    //    // Wait for both threads to finish
    //    evenThread.join();
    //    oddThread.join();

    //    std::cout << std::endl; // Print newline at the end
    Utils util;
    util.readFiles("/home/yawen/dev/qt/Myproject/input.txt");

    Stack stack;
    stack.push(2);
    stack.push(1);
    stack.push(3);
    int last = stack.top();
    std::cout << "Last element " << last << std::endl;
    while(!stack.isEmpty()) {
        std::cout << "Last element " << stack.pop() << std::endl;
    }

    LRU lru(3);
    lru.put(3, 34);
    lru.put(1, 22);
    lru.put(2, 26);
    std::cout << "The element wit key 1 " << lru.get(1) << std::endl;

    lru.put(4, 11);
    std::cout << "Get key 3: " << lru.get(3) << std::endl; // Returns -1 (not found)

    std::string palinedrone_str1 = "appa";
    std::string palinedrone_str2 = "abpaaba";
    std::cout << "is palinedrome " << util.isPalinedrome(palinedrone_str1) << std::endl;
    std::cout << "is palinedrome " << util.isPalinedrome(palinedrone_str2) << std::endl;
    std::string sentence = "Hello world this is C++";
    auto reversed = util.reverseWords(sentence);
    std::cout << "Original: " << sentence << std::endl;
    std::cout << "Reversed: " << reversed << std::endl;

    std::string aa = "qaws123";
    auto it = aa.begin();
    std::advance(it, 2);
    std::sort(it, aa.end());
    std::cout << "sorted string: " << aa << std::endl;
    std::string test1 = "abcabcbb";
    int length1 = lengthOfLongestSubstring2(test1);
    std::cout << length1 << std::endl;
    std::string test2 = "bbbbb";
    int length2 = lengthOfLongestSubstring2(test1);
    std::cout << "length2" << length2 << std::endl;


    // Initialize l1 and l2
//    std::vector<int> values1 = {9, 9, 9, 9, 9, 9, 9};
//    std::vector<int> values2 = {9, 9, 9, 9};

//    ListNode* l1 = createList(values1);
//    ListNode* l2 = createList(values2);

//    ListNode* res = addTwoNumbers(l1, l2);
//    while(res != nullptr) {
//        std::cout << "Add two number" << res->val << std::endl;
//        res = res->next;
//    }
//    int temp = 1 / 10;
//    std::cout << temp << std::endl;
//    delete l1;
//    delete l2;
//    delete res;
    auto s1 = "babad";
    auto s2 = "cbbd";
    std::cout << longest_palindrome(s1) << std::endl;

    std::cout << longest_palindrome(s2) << std::endl;
}

