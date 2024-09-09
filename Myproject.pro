QT       += core gui sql network concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ListNode.cpp \
    basic_file_system.cpp \
    chatwindow.cpp \
    contactsmanager.cpp \
    customwidget.cpp \
    digitalclock.cpp \
    dragdropwindow.cpp \
    filesystemmonitor.cpp \
    graph.cpp \
    imageviewer.cpp \
    longest_palindrome.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix_multiplication.cpp \
    memory_pool_allocator.cpp \
    merge_sort.cpp \
    mystring.cpp \
    producer_consumer.cpp \
    singletondemo.cpp \
    worker.cpp

HEADERS += \
    Base.h \
    ListNode.h \
    basic_file_system.h \
    chatwindow.h \
    contactsmanager.h \
    customwidget.h \
    digitalclock.h \
    dragdropwindow.h \
    filesystemmonitor.h \
    graph.h \
    imageviewer.h \
    invalid_argument_exception.h \
    longest_palindrome.h \
    mainwindow.h \
    matrix_multiplication.h \
    memory_pool_allocator.h \
    merge_sort.h \
    mystring.h \
    observer_pattern.h \
    producer_consumer.h \
    singletondemo.h \
    threadsafequeue.h \
    worker.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Myproject_en_CA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    main.qml
