/*
 * Rower is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Rower is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with RowTrainer.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Written by Radek Zielonka, January 2010. zielonka.radek@gmail.com
 */

#include "concept2plugin.h"
#include "usb.h"

const int CMD_BYTES = 21; 

class Concept2Plugin::Private : public QThread
{
public:
        
    QMutex *mutex;
    usb_dev_handle *usbDev;
    
    Private(QObject *parent)
    {}
    
    ~Private()
    {}

    void run()
    {

        struct usb_device *initDev;
        
        if ((initDev = getDevice()) == NULL)
        {
            qDebug() << "Device NOT found";
        }

        else 
        {
            usbDev = usb_open(initDev);
        }

        exec();
    }

    struct usb_device *getDevice()
    {
        qDebug() << Q_FUNC_INFO;
        usb_init();
        struct usb_device *dev;
        struct usb_bus *bus;

        usb_find_busses();
        usb_find_devices();
        for (bus = usb_get_busses(); bus; bus = bus->next)
            for (dev = bus->devices; dev; dev = dev->next)
            {
                qDebug() << "VendorID: " << dev->descriptor.idVendor;
                if (dev->descriptor.idVendor == 6052)
                {
                    return dev;
                }
            }

        return NULL;
    }

    bool getDataFromPM(const char *send, char *received) const
    {
        if (usbDev == NULL)
        {
            qWarning("Device unconnected");
            return FALSE;
        }
        
        if (usb_interrupt_write(usbDev, 4, &send[0], CMD_BYTES, 1000) < 0)
        {
            qCritical("Error: usb_interrupt_write");
            return FALSE;
        }

        if (usb_interrupt_read(usbDev, 0x83, &received[0], CMD_BYTES, 1000) < 0)
        {
            qCritical("Error: usb_interrupt_read");
            return FALSE;
        }

        return TRUE;
    }

    void version() const
    {
        mutex->lock();
        const char send[] = {0x1, 0xF1, 0x91, 0x91, 0xF2, 0x0, 0x0, 0x0, 0x0,
                             0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                             0x0, 0x0};
        char receive[CMD_BYTES] = {0};

        QString commandString("version info");
     
        if (!getDataFromPM(&send[0], &receive[0]))
        {
            mutex->unlock();
            return;
        }
    
        // The Firmware version are the bytes 10 an 11
        qDebug("This PM3 is running Firmware version: received[10]=%d received[11]=%d",
                receive[10], receive[11]);
        mutex->unlock();
    }
};

Concept2Plugin::Concept2Plugin() : priv(new Private(this))
{
    priv->start();
}

Concept2Plugin::~Concept2Plugin()
{}

void Concept2Plugin::setFixedDistanceWorkout(int distance)
{}

void Concept2Plugin::setFixedTimeWorkout(int time)
{}

void Concept2Plugin::setJustRow()
{}

void Concept2Plugin::reset()
{}
  
void Concept2Plugin::idle()
{}

int Concept2Plugin::getVersion() const
{
    return 0;
}

int Concept2Plugin::getSerialNumber() const
{
    return 0;
}

int Concept2Plugin::getOdometr() const
{
    return 0;
}

int Concept2Plugin::getDragFactor() const
{
    return 0;
}

int Concept2Plugin::getWorkoutTime() const
{
    return 0;
}

int Concept2Plugin::getDistance() const
{
    return 0;
}

int Concept2Plugin::getCurrent500mPace() const
{
    return 0;
}

int Concept2Plugin::getStrokeRating() const
{
    return 0;
}

int Concept2Plugin::getStrokeState() const
{
    return 0;
}

int Concept2Plugin::getHeartRate() const
{
    return 0;
}


Q_EXPORT_PLUGIN2(concept2, Concept2Plugin)
