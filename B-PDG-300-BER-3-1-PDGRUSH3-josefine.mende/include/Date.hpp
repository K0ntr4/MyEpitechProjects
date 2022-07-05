/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** Date
*/

#ifndef DATE_HPP_
#define DATE_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Getter.hpp"

class Date : public IMonitorModule, public IMonitorDisplay {
    public:
        Date() : _dateTime("") {};
        ~Date() {};

        void updateData() override { this->_dateTime = get_time(); };

        int displayText(int startX, int windowY) override {
            const char *title = "Date & Time";

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
            mvprintw(startX, 2, ("Date & Time: " + _dateTime).c_str());
            startX = drawSideBorders(startX, windowY);
            return startX;
        };
        void displayGraphical() override {};

        std::string &getDateTime() { return _dateTime; };

    protected:
    private:
        std::string _dateTime;
};

#endif /* !DATE_HPP_ */
