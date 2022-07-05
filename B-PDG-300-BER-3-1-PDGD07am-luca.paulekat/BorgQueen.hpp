#ifndef Borgqueen_hpp_
    #define Borgqueen_hpp_

#include <string>
#include <iostream>
#include "Borg.hpp"

namespace Borg
{
    class BorgQueen {
        public:
            BorgQueen();
            bool (Ship::*movePtr)(Destination d);
            void (Ship::*firePtr)(Federation::Starfleet::Ship *target);
            void (Ship::*destroyPtr)(Federation::Ship *);
            bool move(Ship *ship , Destination dest);
            void fire(Ship *ship , Federation :: Starfleet ::Ship *target);
            void destroy(Ship *ship , Federation ::Ship *target);
    };
}

#endif