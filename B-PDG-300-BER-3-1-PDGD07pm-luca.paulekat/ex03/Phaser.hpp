#ifndef Phaser_hpp_
    #define Phaser_hpp_

#include <string>
#include <iostream>
#include <vector>
#include "Sounds.hpp"

class Phaser {
    public:
        enum AmmoType { REGULAR, PLASMA, ROCKET };
        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~ Phaser();
        void fire();
        void ejectClip();
        void changeType(AmmoType type);
        void reload();
        void addAmmo(AmmoType type);
        int getCurrentAmmos();
        std::string getSound(AmmoType type);
    private:
        Sounds *sounds;
        static const int Empty = 0;
        unsigned int _maxAmmo;
        AmmoType _defaultType;
        std::vector <AmmoType> _mag;
};

#endif