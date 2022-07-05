#ifndef _ICHARACTER_HPP_
    #define _ICHARACTER_HPP_

#include <iostream>
#include <string>
#include "IPotion.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"

class ICharacter {
    private:
        std::string name;
        unsigned int power;
        unsigned int health;
    public:
        virtual std::string getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual int attack () = 0;
        virtual int special () = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
        virtual ~ICharacter() = default;
        virtual void drink(const IPotion& potion) = 0;
        virtual void drink(const HealthPotion& potion) = 0;
        virtual void drink(const PoisonPotion& potion) = 0;
        virtual void drink(const PowerPotion& potion) = 0;
    };
#endif
