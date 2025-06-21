#ifndef __FLOOR_SENSOR__
#define __FLOOR_SENSOR__

#include "sensor.h"

class FloorSensor : public Sensor {
    private:
        int m_floor_number;
    public:
        FloorSensor();
        void senseChange();
        int getFloorNumber();
};

#endif
