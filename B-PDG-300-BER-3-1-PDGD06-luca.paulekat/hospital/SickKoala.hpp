#ifndef SickKoala_hpp_
    #define SickKoala_hpp_

#include <string>
#include <iostream>
#include <regex>

class SickKoala {
    private:
        std::string name;
    public:
        SickKoala(std::string input_name) {
            name = input_name;
        };
        ~SickKoala() {
            std::cout << "Mr." << name << ": Kreooogg !! I\'m cuuuured!" << std::endl;
        };
        void poke();
        bool takeDrug(std::string med);
        void overDrive(std::string mes);
        std::string getName();
};

#endif