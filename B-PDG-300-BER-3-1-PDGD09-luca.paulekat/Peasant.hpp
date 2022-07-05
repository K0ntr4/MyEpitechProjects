#ifndef Peasant_hpp_
    #define Peasant_hpp_

#include "ICharacter.hpp"

class Peasant : public ICharacter {
protected:
    std::string name;
    unsigned int power;
    unsigned int health;
public:
    Peasant(std::string name, unsigned int power);
    ~Peasant() override;
    std::string getName() const override;
    int getPower() const override;
    int getHp() const override;
    int attack () override;
    int special () override;
    void rest() override;
    void damage(int damage) override;
    void drink(const IPotion& potion) override;
    void drink(const HealthPotion& potion) override;
    void drink(const PoisonPotion& potion) override;
    void drink(const PowerPotion& potion) override;
};

#endif