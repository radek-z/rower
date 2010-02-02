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

#pragma once

#include <QtCore>

#include "rowerpluginiface.h"

/*!
 * @class Concept2Plugin
 */
class Concept2Plugin : public RowerPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(RowerPluginInterface)

public:
    Concept2Plugin(QObject *parent = 0);
    ~Concept2Plugin();
    int version() const;
    int serialNumber() const;

public Q_SLOTS:
    void fixedDistanceWorkout(int distance);
    void fixedTimeWorkout(int time);
    void justRow();
    void reset();
    void idle();

public Q_SIGNALS:
    void odometr(int);
    void dragFactor(int);
    void workTime(int);
    void distance(int);
    void current500mPace(int);
    void strokeRating(int);
    void strokeState(int);
    void heartRate(int);

private:
    class Private;
    Private *d; 
};
