#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QtPlugin>

class PluginInterface
{
public:
    virtual ~PluginInterface() {}
    virtual QString pluginName() const = 0;  // Pure virtual function for plugin name
    virtual void doSomething() = 0;  // Pure virtual function for plugin functionality
};

// Use the Q_DECLARE_INTERFACE macro to register the interface with the Qt meta-object system
#define PluginInterface_iid "com.example.PluginInterface"
Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // PLUGININTERFACE_H
