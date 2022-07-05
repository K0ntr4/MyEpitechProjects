/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <curses.h>
#include <iostream>

int drawSideBorders(int startX, int windowY);

class IMonitorDisplay {
    public:
        IMonitorDisplay() {};
        ~IMonitorDisplay() {};

        virtual int displayText(int startX, int windowY) = 0;
        virtual void displayGraphical() = 0;
};

#endif /* !IMONITORDISPLAY_HPP_ */
