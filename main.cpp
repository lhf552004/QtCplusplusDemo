#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "digitalclock.h"
#include "imageviewer.h"
#include "customwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //    QTranslator translator;
    //    const QStringList uiLanguages = QLocale::system().uiLanguages();
    //    for (const QString &locale : uiLanguages) {
    //        const QString baseName = "Myproject_" + QLocale(locale).name();
    //        if (translator.load(":/i18n/" + baseName)) {
    //            a.installTranslator(&translator);
    //            break;
    //        }
    //    }

    MainWindow w;

//    CustomWidget *customWidget = new CustomWidget(&w); // Create an instance of the custom widget
//    w.setCentralWidget(customWidget); // Set the custom widget as the central widget of the main window
//    w.setWindowTitle("Custom Painting Example");
//            w.resize(600, 400);
    w.show();
    //    ImageViewer viewer;
    //       viewer.show();
    //      DigitalClock clock;
    //      clock.setWindowTitle("Digital Clock");
    //      clock.resize(200, 100);  // Set initial size of the clock
    //      clock.show();

    return a.exec();
}
