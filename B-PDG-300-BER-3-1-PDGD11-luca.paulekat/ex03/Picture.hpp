//
// Created by Luca on 1/26/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_PICTURE3_HPP
#define B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_PICTURE3_HPP

#include <string>
#include <fstream>
#include <sstream>

class Picture {
public:
    std::string data;
    bool getPictureFromFile(const std:: string &file);
    Picture(const std:: string &file);
    Picture();
    Picture(const Picture &other);
    Picture& operator=(const Picture &other) noexcept;
};

#endif
