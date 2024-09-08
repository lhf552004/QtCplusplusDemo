#include "worker.h"
#include <QThread>
#include <QMutex>
#include <QMutexLocker>

Worker::Worker(QObject *parent)
    : QObject(parent), stopRequested(false)
{
}

void Worker::startTask()
{
    // Simulate a long-running task
    for (int i = 0; i <= 100; ++i) {
        QThread::sleep(1);  // Simulate a time-consuming operation

        emit progressUpdated(i);  // Emit the progress signal

        // Check if the stop has been requested
        if (stopRequested) {
            emit finished();
            return;
        }
    }

    emit finished();  // Emit the finished signal when the task is done
}
