#ifndef KoalaNurse_hpp_
    #define KoalaNurse_hpp_

#include <string>
#include <iostream>
#include <regex>
#include <fstream>
#include "SickKoala.hpp"

class KoalaNurse {
    private:
        int working = 0;
        int ID;
    public:
        KoalaNurse(int input_id) {
            ID = input_id;
        };
        ~KoalaNurse() {
            std::cout << "Nurse " << ID << ": Finally some rest!" << std::endl;
        };
        void dest();
        void timeCheck();
        void giveDrug(std::string med, SickKoala *patiant);
        std::string readReport(std::string filename);
        int getID();
};

#endif