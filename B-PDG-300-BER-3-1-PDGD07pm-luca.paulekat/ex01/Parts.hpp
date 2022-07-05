#ifndef Parts_hpp_
    #define Parts_hpp_

#include <string>
#include <iostream>

class Parts
{
    std::string _type;
    std::string _serial;
    public:
        Parts(std::string &serial, bool functional, std::string type);
        bool isFunctional() const;
        std::string serial() const;
        bool _functional = true;
        void informations() const;
};

class Arms : public Parts
{
    std::string type = "Arms";
    std::string _serial = "A-01";
    public:
        Arms (std::string serial = "A-01", bool functional = true) : Parts(serial, functional, "Arms") {};
};

class Legs : public Parts
{
    std::string type = "Legs";
    std::string _serial = "L-01";
    public:
        Legs(std::string serial = "L-01", bool functional = true) : Parts(serial, functional, "Legs") {};
};

class Head : public Parts
{
    std::string type = "Head";
    std::string _serial = "H-01";
    public:
        Head(std::string serial = "H-01", bool functional = true) : Parts(serial, functional, "Head") {};
};

#endif