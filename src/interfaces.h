#pragma once

#include <QtPlugin>

class RowInterface
{
    public:
        virtual ~RowInterface() {}

        virtual void setFixedDistanceWorkout(int distance) = 0;
        virtual void setFixedTimeWorkout(int time) = 0;
        virtual void setJustRow() = 0;
        virtual void setReset() = 0;
        virtual void setIdle() = 0;

        virtual int getVersionInfo() const = 0;
        virtual int getSerialNumber() const = 0;
        virtual int getOdometr() const = 0;
        virtual int getDragFactor() const = 0;
        virtual int getWorkTime() const = 0;
        virtual int getWorkTimeHighRes() const = 0;
        virtual int getDistance() const = 0;
        virtual int getDistanceHighRes() const = 0;
        virtual int getCurrent500mPace() const = 0;
        virtual int getStrokeRating() const = 0;
        virtual int getStrokeState() const = 0;
        virtual int getHeartRate() const = 0;
}

Q_DECLARE_INTERFACE(RowInterface,
        "com.rower.RowInterface")
