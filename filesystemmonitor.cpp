#include "filesystemmonitor.h"
#include <QFileInfo>
#include <QDateTime>

FileSystemMonitor::FileSystemMonitor(QWidget *parent)
    : QMainWindow(parent), fileSystemWatcher(new QFileSystemWatcher(this))
{
    setupUI();

    // Connect signals to handle changes
    connect(fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &FileSystemMonitor::directoryChanged);
    connect(fileSystemWatcher, &QFileSystemWatcher::fileChanged, this, &FileSystemMonitor::fileChanged);
}

FileSystemMonitor::~FileSystemMonitor()
{
    // Destructor
}

void FileSystemMonitor::setupUI()
{
    // Set up the GUI components
    QPushButton *selectButton = new QPushButton("Select Directory", this);
    connect(selectButton, &QPushButton::clicked, this, &FileSystemMonitor::selectDirectory);

    changeListWidget = new QListWidget(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(selectButton);
    layout->addWidget(changeListWidget);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setWindowTitle("File System Monitor");
    resize(400, 300);
}

void FileSystemMonitor::selectDirectory()
{
    QString directory = QFileDialog::getExistingDirectory(this, "Select Directory to Monitor");

    if (!directory.isEmpty()) {
        fileSystemWatcher->addPath(directory);  // Add the selected directory to the watcher
        changeListWidget->addItem("Monitoring directory: " + directory);
    }
}

void FileSystemMonitor::directoryChanged(const QString &path)
{
    changeListWidget->addItem("Directory changed: " + path);
    changeListWidget->item(changeListWidget->count() - 1)->setForeground(Qt::blue);  // Color-code for directory change
}

void FileSystemMonitor::fileChanged(const QString &path)
{
    QFileInfo fileInfo(path);
    QString changeDescription = QString("File changed: %1 (Last modified: %2)")
                                    .arg(path)
                                    .arg(fileInfo.lastModified().toString());

    QListWidgetItem *item = new QListWidgetItem(changeDescription);
    item->setForeground(Qt::red);  // Color-code for file change
    changeListWidget->addItem(item);
}
