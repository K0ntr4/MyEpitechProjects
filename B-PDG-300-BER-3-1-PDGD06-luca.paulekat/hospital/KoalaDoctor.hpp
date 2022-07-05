#ifndef KoalaDoctor_hpp_
    #define KoalaDoctor_hpp_

#include <string>
#include <cstring>
#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include "SickKoala.hpp"

class KoalaDoctor {
    std::string name;
    private:
        int working = 0;
    public:
        KoalaDoctor(std::string input_name) {
            name = input_name;
        };
        void timeCheck();
        void diagnose(SickKoala *patiant);
        std::string getName();
};

#endif