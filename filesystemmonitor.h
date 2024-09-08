#ifndef FILESYSTEMMONITOR_H
#define FILESYSTEMMONITOR_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QListWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPushButton>

class FileSystemMonitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileSystemMonitor(QWidget *parent = nullptr);
    ~FileSystemMonitor();

private slots:
    void selectDirectory();  // Slot to handle directory selection
    void directoryChanged(const QString &path);  // Slot to handle directory changes
    void fileChanged(const QString &path);  // Slot to handle file changes

private:
    QFileSystemWatcher *fileSystemWatcher;  // Object to monitor file system changes
    QListWidget *changeListWidget;  // Widget to display changes

    void setupUI();  // Method to set up the user interface
};

#endif // FILESYSTEMMONITOR_H
