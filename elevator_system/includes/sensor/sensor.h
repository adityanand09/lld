#ifndef __SENSOR__
#define __SENSOR__

#include "sensor_observer.h"
#include <unordered_set>

class Sensor {
protected:
    std::unordered_set<SensorObserver*> m_observer;
    static int m_sensor_id;
public:
    Sensor();
    void addObserver(SensorObserver* observer);
    void notify();
    void removeObserver(SensorObserver* observer);
    virtual void senseChange() = 0;
};

#endif