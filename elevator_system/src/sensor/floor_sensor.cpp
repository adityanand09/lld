#include "sensor/floor_sensor.h"

FloorSensor::FloorSensor() {
}

void FloorSensor::senseChange() {
    // Logic to sense the floor change and set floor number
    notify();
}

int FloorSensor::getFloorNumber() {
    return m_floor_number;
}