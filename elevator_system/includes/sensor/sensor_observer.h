#ifndef __SENSOR_OBSERVER__
#define __SENSOR_OBSERVER__

class SensorObserver {
    private:
    public:
        SensorObserver();
        virtual void notify() = 0;
};

#endif
