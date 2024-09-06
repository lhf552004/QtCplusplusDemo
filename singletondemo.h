#ifndef SINGLETONDEMO_H
#define SINGLETONDEMO_H

#include <QObject>
#include <mutex>

class SingletonDemo : public QObject
{
    Q_OBJECT
private:
    SingletonDemo();
    // Deleted copy constructor and assignment operator to prevent copying
    SingletonDemo(const SingletonDemo&) = delete;
    SingletonDemo& operator=(const SingletonDemo&) = delete;
    // Static pointer to hold the single instance of the class
    static SingletonDemo* instance;

    // Mutex to ensure thread safety
    static std::mutex mutex;
public:
    static SingletonDemo* getInstance();

signals:

};

#endif // SINGLETONDEMO_H
