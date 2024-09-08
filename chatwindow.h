#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHostAddress>

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);  // Constructor
    ~ChatWindow();  // Destructor

private slots:
    void connectToServer();  // Slot to connect to the server
    void sendMessage();      // Slot to send a message
    void receiveMessage();   // Slot to receive a message
    void handleError(QAbstractSocket::SocketError socketError);  // Slot to handle socket errors

private:
    QTcpSocket *tcpSocket;  // TCP socket for network communication
    QTextEdit *messageDisplay;  // Text edit for displaying messages
    QLineEdit *messageInput;    // Line edit for typing messages
    QPushButton *sendButton;    // Button to send messages
    QPushButton *connectButton; // Button to connect to server

    void setupUI();  // Method to set up the user interface
};

#endif // CHATWINDOW_H
