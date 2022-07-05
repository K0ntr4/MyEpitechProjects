#ifndef Federation_hpp_
    #define Federation_hpp_

#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ensign {
            std:: string _name;
            public:
                Ensign(std::string name);
        };
        class Captain {
            std::string _name;
            int _age;
            public:
                Captain(std:: string name);
                std:: string getName ();
                int getAge ();
                void setAge(int age);
        };
        class Ship {
            int _length;
            int _width;
            std:: string _name;
            short _maxWarp;
            Captain *_captain = NULL;
            Destination _location;
            Destination _home = EARTH;
            public:
                Ship(int length, int width, std:: string name, short maxWarp);
                Ship(int length, int width, std:: string name, short maxWarp, int torpedo);
                Ship();
                WarpSystem::Core *core;
                int _shield = 100;
                int _photonTorpedo;
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Captain *captain);
                bool move(int warp , Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield ();
                void setShield(int shield);
                int getTorpedo ();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes , Borg::Ship *target);
        };
    };
    class Ship {
        int _length;
        int _width;
        std:: string _name;
        short _maxWarp = 1;
        Destination _location;
        Destination _home = VULCAN;
        public:
            Ship(int length, int width, std:: string name);
            WarpSystem::Core *core;
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp , Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore();
    };
}

#endif