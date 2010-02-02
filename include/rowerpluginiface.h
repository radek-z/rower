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

#include <QtPlugin>

/*!
 * @class RowerPluginInterface
 * Interface definition for rower machine plugins
 */
class RowerPluginInterface
{
public:
    /*!
     * Destructor.
     */
    virtual ~RowerPluginInterface() {}
        /*!
     * Set fixed distance workout.
     * @param distance distance to set the workout
     */
    virtual void setFixedDistanceWorkout(int distance) = 0;

    /*!
     * Set fixed time workout.
     * @param time time to set the workout
     */
    virtual void setFixedTimeWorkout(int time) = 0;

    /*!
     * Set quick start workout.
     */
    virtual void setJustRow() = 0;

    /*!
     * Reset the workout.
     */
    virtual void reset() = 0;

    /*!
     * Idle the workout.
     */
    virtual void idle() = 0;
    
    /*!
     * Get version information of row machine.
     *
     * @return version info
     */
    virtual int getVersion() const = 0;

    /*!
     * Get the row machine serial number.
     *
     * @return serial number
     */
    virtual int getSerialNumber() const = 0;


    /*!
     * Get the odometr.
     * @param odometr 
     */
    virtual int getOdometr() const = 0;
      
    /*!
     * Get the drag factor.
     * @param drag factor 
     */
    virtual int getDragFactor() const = 0;
      
    /*!
     * Get the workout time.
     * @param workout time 
     */
    virtual int getWorkoutTime() const = 0;
    
    /*!
     * Get the distance.
     * @param distance 
     */
    virtual int getDistance() const = 0;
    
    /*!
     * Get the current 500m pace.
     * @param 500m pace 
     */
    virtual int getCurrent500mPace() const = 0;
    
    /*!
     * Get the stroke rating.
     * @param stroke rating 
     */
    virtual int getStrokeRating() const = 0;
    
    /*!ing
     * Get the stroke state.
     * @param stroke state 
     */
    virtual int getStrokeState() const = 0;
    
    /*!
     * Get the heart rate.
     * @param heart rate 
     */
    virtual int getHeartRate() const = 0;

};

Q_DECLARE_INTERFACE(RowerPluginInterface,
            "com.rower.PluginInterface/1.1")
