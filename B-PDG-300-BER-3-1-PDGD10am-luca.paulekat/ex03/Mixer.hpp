//
// Created by Luca on 1/25/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_MIXER_HPP
#define B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_MIXER_HPP

#include "MixerBase.hpp"
#include "FruitBox.hpp"

class Mixer : public MixerBase {
    public:
        Mixer() : MixerBase() {};
        void plugMixer();
        int mix(FruitBox &fruits) const;
};

#endif //B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_MIXER_HPP
