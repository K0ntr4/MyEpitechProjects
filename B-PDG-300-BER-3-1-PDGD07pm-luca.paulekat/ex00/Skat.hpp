#ifndef Skat_hpp_
    #define Skat_hpp_

#include <string>
#include <iostream>

class Skat {
    private:
        std::string _name;
        int _stimPaks;
    public :
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();
        int &stimPaks();
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
};

#endif