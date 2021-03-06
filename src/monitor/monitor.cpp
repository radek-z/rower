#include "rowerpluginiface.h"
#include "monitor.h"

#include <QDir>
#include <QDebug>
#include <QString>
#include <QPluginLoader>
#include <QApplication>

Monitor::Monitor(QObject *parent)
{
    label = new QLabel(this);
    loadPlugin();
}

Monitor::~Monitor()
{}

void Monitor::loadPlugin()
{
    QDir dir = QDir(qApp->applicationDirPath());
    dir.cd("../lib");

    Q_FOREACH(QString fileName, dir.entryList(QDir::Files))
    {
        QPluginLoader loader(dir.absoluteFilePath(fileName));
        
        if (loader.load())
            qDebug() << "Plugin loaded";
        else
            qDebug() << "Plugin ERROR:" << loader.errorString();
        
        RowerPluginInterface *iRower = qobject_cast<RowerPluginInterface *>(loader.instance());
        if (iRower)
            qDebug() << "SUCCESS plugin: " << fileName;
    }
}
