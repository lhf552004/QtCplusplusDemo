#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = nullptr);  // Constructor
    ~ImageViewer();  // Destructor

private slots:
    void openImage();    // Slot for opening an image
    void zoomIn();       // Slot for zooming in
    void zoomOut();      // Slot for zooming out

protected:
    void wheelEvent(QWheelEvent *event) override;  // Override mouse wheel event for zooming

private:
    QLabel *imageLabel;        // Label to display the image
    QScrollArea *scrollArea;   // Scroll area for handling image overflow
    QVBoxLayout *layout;       // Main layout
    double scaleFactor;        // Current scale factor for zooming

    void updateImageDisplay();  // Helper method to update the image display
};

#endif // IMAGEVIEWER_H
