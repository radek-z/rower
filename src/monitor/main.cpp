#include <QApplication>
#include "monitor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Monitor monitor;
    monitor.show();
    return app.exec();
}
