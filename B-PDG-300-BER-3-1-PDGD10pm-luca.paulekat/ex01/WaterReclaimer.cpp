#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer() :
    _water(0),
    _started(false)
{
}

void    WaterReclaimer::start()
{
    if (this->_water < 10) {
        MissionCriticalError err("Not enough water to achieve the mission.", "WaterReclaimer");
        throw err;
    }
    _started = true;
}

void    WaterReclaimer::useWater(int water)
{
    if (this->_started == false) {
        UserError err_start("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
        throw err_start;
    }
    if (water < 0) {
        UserError err_neg("Water use should be positif.", "WaterReclaimer");
        throw err_neg;
    }
    if (this->_water - water < 10) {
        LifeCriticalError err("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
        throw err;
    }
    _water -= water;
}

void    WaterReclaimer::generateWater()
{
    if (this->_water + 10 > 100) {
        NasaError err("Cannot generate water, reclaimer already full.", "WaterReclaimer");
        throw err;
    }
    _water += 10;
}
