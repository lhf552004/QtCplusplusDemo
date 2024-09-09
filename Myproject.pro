QT       += core gui sql network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# Include directories
INCLUDEPATH += include
SOURCES += \
    src/ListNode.cpp \
    src/basic_file_system.cpp \
    src/chatwindow.cpp \
    src/contactsmanager.cpp \
    src/customwidget.cpp \
    src/digitalclock.cpp \
    src/dragdropwindow.cpp \
    src/filesystemmonitor.cpp \
    src/graph.cpp \
    src/imageviewer.cpp \
    src/longest_palindrome.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/matrix_multiplication.cpp \
    src/memory_pool_allocator.cpp \
    src/merge_sort.cpp \
    src/mystring.cpp \
    src/producer_consumer.cpp \
    src/singletondemo.cpp \
    src/worker.cpp

HEADERS += \
    include/Base.h \
    include/ListNode.h \
    include/basic_file_system.h \
    include/chatwindow.h \
    include/contactsmanager.h \
    include/customwidget.h \
    include/digitalclock.h \
    include/dragdropwindow.h \
    include/filesystemmonitor.h \
    include/graph.h \
    include/imageviewer.h \
    include/invalid_argument_exception.h \
    include/longest_palindrome.h \
    include/mainwindow.h \
    include/matrix_multiplication.h \
    include/memory_pool_allocator.h \
    include/merge_sort.h \
    include/mystring.h \
    include/observer_pattern.h \
    include/producer_consumer.h \
    singletondemo.h \
    include/threadsafequeue.h \
    include/worker.h

FORMS += \
    ui/mainwindow.ui

TESTSOURCES += \
    tests/test_graph.cpp

TRANSLATIONS += \
    translations/Myproject_en_CA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc

DISTFILES += \
    qml/main.qml

# Define a new target for tests
CONFIG(testcase) {
    TEMPLATE = app
    TARGET = MyProjectTests
    QT += testlib
    SOURCES += $$TESTSOURCES
    MOC_DIR = $$PWD/moc
    OBJECTS_DIR = $$PWD/obj
}
