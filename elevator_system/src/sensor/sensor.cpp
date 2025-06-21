#include "sensor/sensor.h"

int Sensor::m_sensor_id = 0;

Sensor::Sensor() {
    m_sensor_id++;
}

void Sensor::addObserver(SensorObserver* observer) {
    m_observer.insert(observer);
}

void Sensor::notify() {
    for (SensorObserver* observer : m_observer) {
        observer->notify();
    }
}

void Sensor::removeObserver(SensorObserver* observer) {
    m_observer.erase(observer);
}