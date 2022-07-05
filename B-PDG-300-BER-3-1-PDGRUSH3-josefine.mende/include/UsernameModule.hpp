/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** UsernameModule
*/

#ifndef USERNAMEMODULE_HPP_
#define USERNAMEMODULE_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Getter.hpp"

class UsernameModule : public IMonitorDisplay, public IMonitorModule {
    public:
        UsernameModule() : _hostname(""), _username("") {};
        ~UsernameModule() {};

        void updateData() override { this->_hostname = get_hostname(); this->_username = get_username(); };

        int displayText(int startX, int windowY) override {
            const char *title = "User- & Hostname";

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
            mvprintw(startX, 2, ("Username: " + _username).c_str());
            startX = drawSideBorders(startX, windowY);
            mvprintw(startX, 2, ("Hostname: " + _hostname).c_str());
            startX = drawSideBorders(startX, windowY);
            return startX;
        };
        void displayGraphical() override {};

        std::string &getHostname() { return _hostname; };
        std::string &getUsername() { return _username; };

    private:
        std::string _hostname;
        std::string _username;
};

#endif /* !USERNAMEMODULE_HPP_ */
