#ifndef Sounds_hpp_
    #define Sounds_hpp_

#include <string>
#include <iostream>

class Sounds
{
    public:
        std:: string Regular;
        std:: string Plasma;
        std:: string Rocket;
        Sounds(std::string regular, std::string plasma, std::string rocket) : Regular(regular), Plasma(plasma), Rocket(rocket) {};
};

#endif