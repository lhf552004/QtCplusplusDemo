#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>

class DigitalClock : public QWidget
{
    Q_OBJECT

public:
    explicit DigitalClock(QWidget *parent = nullptr);  // Constructor
    ~DigitalClock();  // Destructor

protected:
    void paintEvent(QPaintEvent *event) override;  // Override the paint event

private slots:
    void updateTime();  // Slot to update the current time

private:
    QTimer *timer;  // Timer to trigger time updates
    QTime currentTime;  // Holds the current time
};

#endif // DIGITALCLOCK_H
