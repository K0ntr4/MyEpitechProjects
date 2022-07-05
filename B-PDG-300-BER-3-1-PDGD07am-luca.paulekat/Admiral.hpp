#ifndef Admiral_hpp_
    #define Admiral_hpp_

#include <string>
#include <iostream>
#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Admiral {
            private:
                std:: string _name;
            public:
                Admiral(std::string name);
                bool (Ship::*movePtr)(Destination d) = &Ship::move;
                void (Ship::*firePtr)(Borg::Ship *target) = &Ship::fire;
                void fire(Federation :: Starfleet ::Ship *ship , Borg::Ship *target);
                bool move(Federation :: Starfleet ::Ship *ship , Destination dest);
        };
    }
}

#endif