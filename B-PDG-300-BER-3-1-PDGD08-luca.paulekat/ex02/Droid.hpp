#ifndef Droid_hpp_
    #define Droid_hpp_

#include <string>
#include <iostream>
#include "DroidMemory.hpp"

class Droid
{
    private:
        std::string ID;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
        DroidMemory *BattleData;
    public:
        Droid(std::string str);
        Droid(const Droid& second);
        ~Droid();
        void operator=(const Droid& second);
        bool operator==(const Droid& second);
        inline bool operator!=(const Droid& second) { return !(*this==second); };
        void operator<<(size_t& energy);
        void operator<<(Droid& second);
        Droid *copy(std::string str);
        void assignment (std::string);
        std::string getId() const;
        void setId(std::string str);
        size_t getEnergy() const;
        void setEnergy(size_t energy);
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        void setStatus(std::string *status);
        DroidMemory *getBattleData() const;
        void setBattleData(DroidMemory *mem);
        bool operator()(const std::string *task, const size_t exp);
};

std::ostream& operator<<(std::ostream& os, const Droid& droid);

#endif