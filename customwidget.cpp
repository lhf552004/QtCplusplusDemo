#include "customwidget.h"
#include <QPainter>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
    // Optional: Set any widget properties, like size or background color
    setMinimumSize(200, 200); // Set a minimum size for the custom widget
}

// Override the paintEvent() method
void CustomWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this); // Create a QPainter object, targeting this widget

    // Set up the painter (pen, brush, etc.)
    painter.setRenderHint(QPainter::Antialiasing, true); // Enable antialiasing for smoother edges
    painter.setPen(Qt::black); // Set the pen color to black
    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern)); // Set the brush to fill shapes with solid blue color

    // Draw a rectangle
    painter.drawRect(20, 20, 100, 100); // Draws a rectangle at (20, 20) with width 100 and height 100

    // Draw a circle (ellipse)
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern)); // Set the brush to fill with solid red color
    painter.drawEllipse(QPoint(150, 50), 40, 40); // Draws a circle centered at (150, 50) with a radius of 40

    // Draw text
    painter.setPen(Qt::black); // Set pen color to black
    painter.drawText(rect(), Qt::AlignCenter, "Custom Painting"); // Draws text in the center of the widget
}
