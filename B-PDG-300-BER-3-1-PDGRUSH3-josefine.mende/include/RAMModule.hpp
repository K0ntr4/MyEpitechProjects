/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** RAMModule
*/

#ifndef RAMModule_HPP_
#define RAMModule_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Getter.hpp"

class RAMModule : public IMonitorDisplay, public IMonitorModule {
    public:
        RAMModule() : _free_ram(""), _av_ram("") {};
        ~RAMModule() {};

        void updateData() override {
            this->_free_ram = std::to_string(get_ram_free()).append(" GB");
            this->_av_ram = std::to_string(get_ram_av()).append(" GB"); };

        int displayText(int startX, int windowY) override {
            const char *title = "RAM";

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
            mvprintw(startX, 2, ("Free RAM: " + _free_ram).c_str());
            startX = drawSideBorders(startX, windowY);
            mvprintw(startX, 2, ("Total: " + _av_ram).c_str());
            startX = drawSideBorders(startX, windowY);
            return startX;
        };
        void displayGraphical() override {};

        std::string &getFreeRAM() { return _free_ram; };
        std::string &getAvRAM() { return _av_ram; };

    private:
        std::string _free_ram;
        std::string _av_ram;
};

#endif
