#include "digitalclock.h"
#include <QPainter>
#include <QFont>
#include <QTime>

DigitalClock::DigitalClock(QWidget *parent)
    : QWidget(parent), timer(new QTimer(this))
{
    // Initialize the timer and connect its timeout signal to updateTime slot
    connect(timer, &QTimer::timeout, this, &DigitalClock::updateTime);
    timer->start(1000);  // Start the timer with a 1-second interval

    // Initialize the current time
    currentTime = QTime::currentTime();
    updateTime();  // Initial call to display the time
}

DigitalClock::~DigitalClock()
{
    // Destructor - Cleanup if needed
}

// Slot to update the current time
void DigitalClock::updateTime()
{
    currentTime = QTime::currentTime();  // Get the current time
    update();  // Trigger a repaint event
}

// Override paintEvent to draw the digital clock
void DigitalClock::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);  // Mark event as unused since we don't use it directly

    // Set up the painter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set font size relative to the widget's size
    QFont font = painter.font();
    font.setPointSize(static_cast<int>(height() / 3.5));  // Adjust the font size
    painter.setFont(font);

    // Draw the time in the center of the widget
    QString timeString = currentTime.toString("hh:mm:ss");
    QRect rect = this->rect();  // Get the widget's rectangle
    painter.drawText(rect, Qt::AlignCenter, timeString);  // Draw text centered
}
