QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ListNode.cpp \
    basic_file_system.cpp \
    customwidget.cpp \
    longest_palindrome.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix_multiplication.cpp \
    memory_pool_allocator.cpp \
    merge_sort.cpp \
    singletondemo.cpp

HEADERS += \
    ListNode.h \
    basic_file_system.h \
    customwidget.h \
    invalid_argument_exception.h \
    longest_palindrome.h \
    mainwindow.h \
    matrix_multiplication.h \
    memory_pool_allocator.h \
    merge_sort.h \
    observer_pattern.h \
    singletondemo.h \
    threadsafequeue.h

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
