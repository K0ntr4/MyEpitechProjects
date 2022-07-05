/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** NetworkModule
*/

#ifndef NetworkModule_HPP_
#define NetworkModule_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Getter.hpp"

class NetworkModule : public IMonitorDisplay, public IMonitorModule {
    public:
        NetworkModule() : _incoming(""), _outgoing("") {};
        ~NetworkModule() {};

        void updateData() override {
            this->_incoming = std::to_string(get_ram_free()).append(" B/s");
            this->_outgoing = std::to_string(get_ram_av()).append(" B/s"); };

        int displayText(int startX, int windowY) override {
            const char *title = "Network";

            mvprintw(startX, 0, "+");
            mvprintw(startX, windowY - 1, "+");
            for (int i = 1; i < (windowY - 1); i++) {
                mvprintw(startX, i, "-");
            }
            startX++;
            attron(A_BOLD);
            mvprintw(startX, 2, title);
            attroff(A_BOLD);
            startX = drawSideBorders(startX, windowY);
            mvprintw(startX, 2, ("Incoming: " + _incoming).c_str());
            startX = drawSideBorders(startX, windowY);
            mvprintw(startX, 2, ("Outgoing: " + _outgoing).c_str());
            startX = drawSideBorders(startX, windowY);
            return startX;
        };
        void displayGraphical() override {};

        std::string &getIncoming() { return _incoming; };
        std::string &getOutgoing() { return _outgoing; };

    private:
        std::string _incoming;
        std::string _outgoing;
};

#endif
