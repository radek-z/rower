/*
 * This file is part of Rower.
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

#pragma once

#include <QtCore/qobject.h>
#include <QtCore/qplugin.h>

/*!
 * @class RowerPluginInterface
 * Interface definition for rower machine plugins
 */
class RowerPluginInterface : public QObject
{
    Q_OBJECT

public:
    RowerPluginInterface(QObject *parent = 0) : QObject(parent) {}
    /*!
     * Destructor.
     */
    virtual ~RowerPluginInterface() {}
    /*!
     * Get version information of row machine.
     *
     * @return version info
     */
    virtual int version() const = 0;

    /*!
     * Get the row machine serial number.
     *
     * @return serial number
     */
    virtual int serialNumber() const = 0;

Q_SLOTS:
    /*!
     * Set fixed distance workout.
     * @param distance distance to set the workout
     */
    virtual void fixedDistanceWorkout(int distance) = 0;

    /*!
     * Set fixed time workout.
     * @param time time to set the workout
     */
    virtual void fixedTimeWorkout(int time) = 0;

    /*!
     * Set quick start workout.
     */
    virtual void justRow() = 0;

    /*!
     * Reset the workout.
     */
    virtual void reset() = 0;

    /*!
     * Idle the workout.
     */
    virtual void idle() = 0;

Q_SIGNALS:
    /*!
     * Emitted when the odometr is changed
     * @param new odometr 
     */
    virtual odometr(int) const = 0;
      
    /*!
     * Emitted when the drag factor is changed
     * @param new drag factor 
     */
    virtual int dragFactor(int) const = 0;
      
    /*!
     * Emitted when the work time is changed
     * @param new work time 
     */
    virtual int workTime(int) const = 0;
    
    /*!
     * Emitted when the distance is changed
     * @param new distance 
     */
    virtual int distance(int) const = 0;
    
    /*!
     * Emitted when the current 500m pace is changed
     * @param new 500m pace 
     */
    virtual int current500mPace(int) const = 0;
    
    /*!
     * Emitted when the stroke is changed
     * @param new stroke rating 
     */
    virtual int strokeRating(int) const = 0;
    
    /*!
     * Emitted when the stroke state is changed
     * @param new stroke state 
     */
    virtual int strokeState(int) const = 0;
    
    /*!
     * Emitted when the heart rate is changed
     * @param new heart rate 
     */
    virtual int heartRate(int) const = 0;

};

Q_DECLARE_INTERFACE(RowerPluginInterface,
            "com.rower.PluginInterface/1.1")
