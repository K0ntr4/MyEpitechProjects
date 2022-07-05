//
// Created by Luca on 1/25/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_MIXERBASE_HPP
#define B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_MIXERBASE_HPP

class MixerBase
{
    public:
        MixerBase ();
        int mix(FruitBox &fruits) const;
    protected:
        bool _plugged;
        int (* _mixfunc)(FruitBox &fruits);
};

#endif //B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_MIXERBASE_HPP
