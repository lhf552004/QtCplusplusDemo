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
    complex.cpp \
    contactsmanager.cpp \
    customwidget.cpp \
    digitalclock.cpp \
    dragdropwindow.cpp \
    filesystemmonitor.cpp \
    graph.cpp \
    imageviewer.cpp \
    longest_palindrome.cpp \
    lru.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    matrix_multiplication.cpp \
    memory_pool_allocator.cpp \
    merge_sort.cpp \
    myplugin.cpp \
    mystring.cpp \
    node.cpp \
    producer_consumer.cpp \
    rectangle.cpp \
    singletondemo.cpp \
    stack.cpp \
    utils.cpp \
    worker.cpp

HEADERS += \
    Base.h \
    ListNode.h \
    Queen.h \
    basic_file_system.h \
    chatwindow.h \
    commonseq.h \
    complex.h \
    contactsmanager.h \
    customwidget.h \
    digitalclock.h \
    dragdropwindow.h \
    filesystemmonitor.h \
    graph.h \
    imageviewer.h \
    invalid_argument_exception.h \
    longest_palindrome.h \
    lru.h \
    mainwindow.h \
    matrix.h \
    matrix_multiplication.h \
    memory_pool_allocator.h \
    merge_sort.h \
    myplugin.h \
    mystring.h \
    node.h \
    observer_pattern.h \
    plugininterface.h \
    producer_consumer.h \
    rectangle.h \
    simplesmartpointer.h \
    singletondemo.h \
    solveNQueens.h \
    stack.h \
    threadsafequeue.h \
    treenode.h \
    utils.h \
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

RESOURCES += \
    resource.qrc

DISTFILES += \
    main.qml
