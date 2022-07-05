/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** OSKernelModule
*/

#ifndef OSKERNELMODULE_HPP_
#define OSKERNELMODULE_HPP_

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Getter.hpp"

class OSKernelModule : public IMonitorDisplay, public IMonitorModule {
    public:
        OSKernelModule() : _operatingSystemName(""), _kernelVersion("") {};
        ~OSKernelModule() {};

        void updateData() override {
            this->_kernelVersion = get_os()->release;
            this->_operatingSystemName = get_os()->sysname; };

        int displayText(int startX, int windowY) override {
            const char *title = "Operation System & Kernel";

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
            mvprintw(startX, 2, ("Operation System: " + _operatingSystemName).c_str());
            startX = drawSideBorders(startX, windowY);
            mvprintw(startX, 2, ("Kernel Version: " + _kernelVersion).c_str());
            startX = drawSideBorders(startX, windowY);
            return startX;
        };
        void displayGraphical() override {};

        std::string &getOperatingSystemName() { return _operatingSystemName; };
        std::string &getKernelVersion() { return _kernelVersion; };

    protected:
    private:
        std::string _operatingSystemName;
        std::string _kernelVersion;
};

#endif /* !OSKERNELMODULE_HPP_ */
