//
// Created by Luca on 1/25/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_LITTLEHAND_HPP
#define B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_LITTLEHAND_HPP

#include "FruitBox.hpp"
#include "Coconut.hpp"
#include "FruitBox.hpp"
#include "Lemon.hpp"
#include "Banana.hpp"
#include "Lime.hpp"
#include "Mixer.hpp"

class LittleHand {
    public:
        void sortFruitBox(FruitBox &unsorted , FruitBox &lemons , FruitBox &bananas , FruitBox &
        limes);
        static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
        void plugMixer(MixerBase &mixer);
};

#endif //B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_LITTLEHAND_HPP
