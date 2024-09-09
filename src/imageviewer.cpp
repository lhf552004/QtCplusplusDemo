#include "imageviewer.h"
#include <QWheelEvent>
#include <QImageReader>
#include <QMessageBox>

ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent), scaleFactor(1.0)
{
    // Initialize UI elements
    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);  // Allow scaling of content

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);

    QPushButton *openButton = new QPushButton("Open Image", this);
    QPushButton *zoomInButton = new QPushButton("Zoom In", this);
    QPushButton *zoomOutButton = new QPushButton("Zoom Out", this);

    connect(openButton, &QPushButton::clicked, this, &ImageViewer::openImage);
    connect(zoomInButton, &QPushButton::clicked, this, &ImageViewer::zoomIn);
    connect(zoomOutButton, &QPushButton::clicked, this, &ImageViewer::zoomOut);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(openButton);
    buttonLayout->addWidget(zoomInButton);
    buttonLayout->addWidget(zoomOutButton);

    QWidget *buttonWidget = new QWidget(this);
    buttonWidget->setLayout(buttonLayout);
    setMenuWidget(buttonWidget);

    // Set window properties
    setWindowTitle("Image Viewer");
    resize(800, 600);
}

ImageViewer::~ImageViewer()
{
    // Destructor
}

void ImageViewer::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpeg *.jpg *.bmp);;All Files (*)");
    if (fileName.isEmpty()) return;

    QImage image(fileName);
    if (image.isNull()) {
        QMessageBox::warning(this, "Open Image", "The image could not be loaded.");
        return;
    }

    imageLabel->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;
    updateImageDisplay();
}

void ImageViewer::zoomIn()
{
    scaleFactor *= 1.25;  // Increase the scale factor
    updateImageDisplay();
}

void ImageViewer::zoomOut()
{
    scaleFactor /= 1.25;  // Decrease the scale factor
    updateImageDisplay();
}

void ImageViewer::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) {
        zoomIn();  // Zoom in on mouse wheel up
    } else {
        zoomOut();  // Zoom out on mouse wheel down
    }
}

void ImageViewer::updateImageDisplay()
{
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());
}
