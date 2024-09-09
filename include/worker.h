#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = nullptr);  // Constructor

signals:
    void progressUpdated(int progress);  // Signal to indicate progress
    void finished();                     // Signal to indicate task completion

public slots:
    void startTask();  // Slot to start the task

private:
    bool stopRequested;  // Flag to stop the task if needed
};

#endif // WORKER_H
