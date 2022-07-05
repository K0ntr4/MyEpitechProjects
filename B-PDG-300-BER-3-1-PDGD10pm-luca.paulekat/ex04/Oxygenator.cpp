#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator() :
    _quantity(0)
{
}

void    Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void    Oxygenator::useOxygen(int quantity)
{
    if (this->_quantity - quantity <= 5) {
        LifeCriticalError err ("Not enough oxygen to live.", "Oxygenator");
        throw err;
    }
    if (this->_quantity - quantity <= 15) {
        MissionCriticalError err ("Not enough oxygen to continue the mission.", "Oxygenator");
        throw err;
    }
    _quantity -= quantity;
}
