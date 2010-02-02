#pragma once

#include <QWidget>
#include <QLabel>

class Monitor : public QWidget
{
    Q_OBJECT

    public:
        Monitor(QObject *parent = 0);
        ~Monitor();
        void loadPlugin();

    private:
        QLabel *label;
};
