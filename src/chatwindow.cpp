#include "chatwindow.h"
#include <QMessageBox>
#include <QInputDialog>

ChatWindow::ChatWindow(QWidget *parent)
    : QMainWindow(parent), tcpSocket(new QTcpSocket(this))
{
    setupUI();

    connect(connectButton, &QPushButton::clicked, this, &ChatWindow::connectToServer);
    connect(sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &ChatWindow::receiveMessage);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred),
            this, &ChatWindow::handleError);
}

ChatWindow::~ChatWindow()
{
    tcpSocket->disconnectFromHost();
}

void ChatWindow::setupUI()
{
    // Set up the GUI components
    messageDisplay = new QTextEdit(this);
    messageDisplay->setReadOnly(true);

    messageInput = new QLineEdit(this);

    sendButton = new QPushButton("Send", this);
    connectButton = new QPushButton("Connect", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(messageDisplay);
    layout->addWidget(messageInput);
    layout->addWidget(sendButton);
    layout->addWidget(connectButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setWindowTitle("Networked Chat Application");
    resize(400, 300);
}

void ChatWindow::connectToServer()
{
    QString serverAddress = QInputDialog::getText(this, "Server Address", "Enter server IP address:");
    quint16 serverPort = QInputDialog::getInt(this, "Server Port", "Enter server port:", 1234);

    tcpSocket->connectToHost(QHostAddress(serverAddress), serverPort);
}

void ChatWindow::sendMessage()
{
    QString message = messageInput->text();
    if (message.isEmpty()) {
        return;
    }

    QByteArray data = message.toUtf8();
    tcpSocket->write(data);  // Send the message over the network
    messageDisplay->append("Me: " + message);  // Display the sent message
    messageInput->clear();  // Clear the input field
}

void ChatWindow::receiveMessage()
{
    QByteArray data = tcpSocket->readAll();  // Read the incoming message
    QString message = QString::fromUtf8(data);
    messageDisplay->append("Friend: " + message);  // Display the received message
}

void ChatWindow::handleError(QAbstractSocket::SocketError socketError)
{
    QMessageBox::critical(this, "Error", tcpSocket->errorString());
}
