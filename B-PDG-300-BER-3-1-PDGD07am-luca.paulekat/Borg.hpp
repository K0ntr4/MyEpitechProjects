#ifndef Borg_hpp_
    #define Borg_hpp_

#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ensign;
        class Captain;
        class Ship;
    };
    class Ship;
}

namespace Borg
{
    class Ship {
        int _side = 300;
        short _maxWarp = 9;
        Destination _location;
        Destination _home = UNICOMPLEX;
        public:
            Ship();
            Ship(int weaponFrequency);
            Ship(int weaponFrequency, short repair);
            WarpSystem::Core *core;
            int _weaponFrequency;
            short _repair = 3;
            int _shield = 100;
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp , Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield ();
            void setShield(int shield);
            int getWeaponFrequency ();
            void setWeaponFrequency(int frequency);
            short getRepair ();
            void setRepair(short repair);
            void fire(Federation::Ship *target);
            void fire(Federation::Starfleet::Ship *target);
            void repair ();
    };
}

#endif