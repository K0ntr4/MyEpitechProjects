//
// Created by Luca on 1/26/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_TOY6_HPP
#define B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_TOY6_HPP

#include "Picture.hpp"
#include <iostream>

class Toy {
    public:
        class Error {
        public:
            enum ErrorType {UNKNOWN, PICTURE, SPEAK};
            [[nodiscard]] std::string what() const;
            [[nodiscard]] std::string where() const;
            ErrorType type;
            explicit Error(ErrorType err = UNKNOWN);
        } error;
        enum ToyType { BASIC_TOY, ALIEN, BUZZ, WOODY };
        [[nodiscard]] ToyType getType() const;
        [[nodiscard]] std::string getName() const;
        void setName(std::string name);
        bool setAscii(const std::string &file);
        [[nodiscard]] std::string getAscii() const;
        Toy();
        Toy(ToyType type, std::string name, const std::string &filename);
        Toy(const Toy &other);
        Toy& operator=(const Toy &other) noexcept;
        virtual bool speak(const std::string message);
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
