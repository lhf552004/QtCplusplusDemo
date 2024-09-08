#include "contactsmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>

ContactsManager::ContactsManager(QWidget *parent)
    : QMainWindow(parent), model(new QSqlTableModel(this))
{
    setupUI();         // Set up the user interface
    setupDatabase();   // Set up the SQLite database
    setupModelView();  // Set up the model and view
}

ContactsManager::~ContactsManager()
{
    db.close();  // Close the database connection on destruction
}

void ContactsManager::setupUI()
{
    // Set up the central widget and layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Set up input fields
    nameEdit = new QLineEdit(this);
    phoneEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    nameEdit->setPlaceholderText("Name");
    phoneEdit->setPlaceholderText("Phone");
    emailEdit->setPlaceholderText("Email");

    // Set up buttons
    QPushButton *addButton = new QPushButton("Add Contact", this);
    QPushButton *deleteButton = new QPushButton("Delete Contact", this);

    connect(addButton, &QPushButton::clicked, this, &ContactsManager::addContact);
    connect(deleteButton, &QPushButton::clicked, this, &ContactsManager::deleteContact);

    // Set up layout for input fields and buttons
    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(nameEdit);
    inputLayout->addWidget(phoneEdit);
    inputLayout->addWidget(emailEdit);
    inputLayout->addWidget(addButton);
    inputLayout->addWidget(deleteButton);

    mainLayout->addLayout(inputLayout);

    // Set up table view
    tableView = new QTableView(this);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(tableView);
}

void ContactsManager::setupDatabase()
{
    // Initialize and open the SQLite database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("contacts.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Unable to open database: " + db.lastError().text());
        return;
    }

    // Create the contacts table if it doesn't exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS contacts ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT, "
               "phone TEXT, "
               "email TEXT)");
}

void ContactsManager::setupModelView()
{
    // Set up the model
    model->setTable("contacts");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    // Set up the table view to use the model
    tableView->setModel(model);
    tableView->hideColumn(0);  // Hide the ID column
}

void ContactsManager::addContact()
{
    // Get input values
    QString name = nameEdit->text();
    QString phone = phoneEdit->text();
    QString email = emailEdit->text();

    if (name.isEmpty() || phone.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    // Insert a new contact into the database
    QSqlQuery query;
    query.prepare("INSERT INTO contacts (name, phone, email) VALUES (?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(phone);
    query.addBindValue(email);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to add contact: " + query.lastError().text());
    } else {
        model->select();  // Refresh the view
        nameEdit->clear();
        phoneEdit->clear();
        emailEdit->clear();
    }
}

void ContactsManager::deleteContact()
{
    // Get the selected row in the table view
    QModelIndexList selectedRows = tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Delete Error", "Please select a contact to delete.");
        return;
    }

    int row = selectedRows.first().row();
    model->removeRow(row);

    if (!model->submitAll()) {
        QMessageBox::critical(this, "Error", "Failed to delete contact: " + model->lastError().text());
    } else {
        model->select();  // Refresh the view
    }
}
