#ifndef CONTACTSMANAGER_H
#define CONTACTSMANAGER_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ContactsManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContactsManager(QWidget *parent = nullptr);  // Constructor
    ~ContactsManager();  // Destructor

private slots:
    void addContact();    // Slot for adding a contact
    void deleteContact(); // Slot for deleting a contact

private:
    void setupUI();           // Method to set up the user interface
    void setupDatabase();     // Method to set up the SQLite database
    void setupModelView();    // Method to set up the model and view

    QSqlDatabase db;              // Database connection
    QSqlTableModel *model;        // Model for interacting with the database
    QTableView *tableView;        // View for displaying contacts

    QLineEdit *nameEdit;          // Field for contact name
    QLineEdit *phoneEdit;         // Field for contact phone
    QLineEdit *emailEdit;         // Field for contact email
};

#endif // CONTACTSMANAGER_H
