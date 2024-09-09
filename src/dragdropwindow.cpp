#include "dragdropwindow.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QFileInfo>

DragDropWindow::DragDropWindow(QWidget *parent)
    : QMainWindow(parent), fileListWidget(new QListWidget(this))
{
    setWindowTitle("Drag and Drop File Viewer");
    setAcceptDrops(true);  // Enable drag-and-drop on the window

    // Set up the QListWidget
    setCentralWidget(fileListWidget);
}

DragDropWindow::~DragDropWindow()
{
    // Destructor
}

void DragDropWindow::dragEnterEvent(QDragEnterEvent *event)
{
    // Accept the event if it contains URLs (files)
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void DragDropWindow::dragMoveEvent(QDragMoveEvent *event)
{
    // Accept the event if it contains URLs (files)
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void DragDropWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    // Ensure the event contains URLs (files)
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        for (const QUrl &url : urlList) {
            QString fileName = url.toLocalFile();

            if (isValidFileType(fileName)) {
                fileListWidget->addItem(fileName);  // Add valid file to the list
            } else {
                QMessageBox::warning(this, "Invalid File Type", "Only text files or images are allowed.");
            }
        }
    }
    event->acceptProposedAction();
}

bool DragDropWindow::isValidFileType(const QString &fileName)
{
    QFileInfo fileInfo(fileName);
    QString fileExtension = fileInfo.suffix().toLower();

    // Allow only text files or images
    return (fileExtension == "txt" || fileExtension == "png" || fileExtension == "jpg" ||
            fileExtension == "jpeg" || fileExtension == "bmp");
}
