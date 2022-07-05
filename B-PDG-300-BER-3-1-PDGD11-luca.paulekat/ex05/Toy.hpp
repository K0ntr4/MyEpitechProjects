//
// Created by Luca on 1/26/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_TOY5_HPP
#define B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_TOY5_HPP

#include "Picture.hpp"
#include <iostream>

class Toy {
    public:
        class Error {
        public:
            enum ErrorType {UNKNOWN, PICTURE, SPEAK};
            std::string what() const;
            std::string where() const;
            ErrorType type;
            Error(ErrorType err = UNKNOWN);
        } error;
        enum ToyType { BASIC_TOY, ALIEN, BUZZ, WOODY };
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(const std:: string &file);
        std::string getAscii() const;
        Toy();
        Toy(ToyType type, std::string name, const std::string &filename);
        Toy(const Toy &other);
        Toy& operator=(const Toy &other) noexcept;
        virtual void speak(std::string message) const;
        Toy& operator<<(const std::string);
        virtual bool speak_es(const std::string message);
        Error getLastError();

    protected:
        std::string name;
        ToyType type;
        Picture picture;
};

std::ostream& operator<<(std::ostream& os, const Toy &toy);

#endif
