#ifndef DRAGDROPWINDOW_H
#define DRAGDROPWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QMimeData>

class DragDropWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DragDropWindow(QWidget *parent = nullptr);  // Constructor
    ~DragDropWindow();  // Destructor

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;  // Override drag enter event
    void dragMoveEvent(QDragMoveEvent *event) override;    // Override drag move event
    void dropEvent(QDropEvent *event) override;            // Override drop event

private:
    QListWidget *fileListWidget;  // Widget to display file names

    bool isValidFileType(const QString &fileName);  // Helper method to check file type
};

#endif // DRAGDROPWINDOW_H
