/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <iostream>

class IMonitorModule {
    public:
        IMonitorModule() : _activated(true) {};
        ~IMonitorModule() {};

        virtual void updateData() = 0;
        virtual void activate() { _activated = !_activated; };
        bool getActivated() { return _activated; };

    protected:
        bool _activated;
};

#endif /* !IMONITORMODULE_HPP_ */
