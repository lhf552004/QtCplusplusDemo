#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "digitalclock.h"
#include "imageviewer.h"
#include "customwidget.h"#include <QPluginLoader>
#include <QDebug>
#include "plugininterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Load the plugin dynamically
    QPluginLoader loader("myplugin");  // The name of the plugin file without the extension
    QObject *pluginInstance = loader.instance();

    if (pluginInstance) {
        // Cast the plugin to the PluginInterface
        PluginInterface *plugin = qobject_cast<PluginInterface *>(pluginInstance);
        if (plugin) {
            qDebug() << "Loaded plugin:" << plugin->pluginName();
            plugin->doSomething();  // Call the plugin's functionality
        } else {
            qDebug() << "Failed to cast plugin to PluginInterface.";
        }
    } else {
        qDebug() << "Failed to load plugin:" << loader.errorString();
    }
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
