#ifndef MYPLUGIN_H
#define MYPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class MyPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterface_iid)  // Macro to provide plugin metadata
    Q_INTERFACES(PluginInterface)  // Macro to declare the interfaces the plugin implements

public:
    QString pluginName() const override { return "MyPlugin"; }
    void doSomething() override;
};

#endif // MYPLUGIN_H
