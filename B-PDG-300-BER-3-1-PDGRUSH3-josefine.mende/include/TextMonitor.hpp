/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** TextMonitor
*/

#ifndef TEXTMONITOR_HPP_
#define TEXTMONITOR_HPP_

#include "IMonitor.hpp"

class TextMonitor : public IMonitor {
    public:
        TextMonitor() {};
        ~TextMonitor() {};

        int display(int parentY) override {
            int line = 0;
            if (_cpuModule.getActivated())
                line = _cpuModule.displayText(line, parentY);
            if (_dateTimeModule.getActivated())
                line = _dateTimeModule.displayText(line, parentY);
            if (_networkModule.getActivated())
                line = _networkModule.displayText(line, parentY);
            if (_osKernelModule.getActivated())
                line = _osKernelModule.displayText(line, parentY);
            if (_ramModule.getActivated())
                line = _ramModule.displayText(line, parentY);
            if (_usernameModule.getActivated())
                line = _usernameModule.displayText(line, parentY);
            return line;
        }
    protected:
    private:
};

#endif /* !TEXTMONITOR_HPP_ */
