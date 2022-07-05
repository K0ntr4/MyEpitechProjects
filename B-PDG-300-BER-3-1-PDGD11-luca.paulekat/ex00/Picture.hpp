#ifndef B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_PICTURE0_HPP
#define B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_PICTURE0_HPP

#include <string>
#include <fstream>
#include <sstream>

class Picture {
public:
    std::string data;
    bool getPictureFromFile(const std:: string &file);
    Picture(const std:: string &file);
    Picture();
};

#endif
