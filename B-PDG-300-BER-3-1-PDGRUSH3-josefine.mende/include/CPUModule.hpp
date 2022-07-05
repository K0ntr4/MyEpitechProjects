/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** CPUModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Getter.hpp"

class CPUModule : public IMonitorDisplay, public IMonitorModule {
    public:
        CPUModule() : _cpu_model(""), _cpu_freq(""), _cores(""), _cpu_usage("") {};
        ~CPUModule() {};

        void updateData() override {
            this->_cpu_model = get_cpu_model();
            this->_cpu_freq = get_cpu_freq(0).append(" MHz");
            this->_cpu_usage = std::to_string(get_cpu_usage(0)).append(" %");
            this->_cores = std::to_string(get_core_amount()); };

        int displayText(int startX, int windowY) override {
            const char *title = "CPU";

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
            mvprintw(startX, 2, ("Frequency: " + _cpu_freq).c_str());
            startX = drawSideBorders(startX, windowY);
            mvprintw(startX, 2, ("Model: " + _cpu_model).c_str());
            startX = drawSideBorders(startX, windowY);
            mvprintw(startX, 2, ("Usage: " + _cpu_usage + "%").c_str());
            startX = drawSideBorders(startX, windowY);
            mvprintw(startX, 2, ("Cores: " + _cores).c_str());
            startX = drawSideBorders(startX, windowY);
            return startX;
        };
        void displayGraphical() override {};

        std::string &getModel() { return _cpu_model; };
        std::string &getFreq() { return _cpu_freq; };
        std::string &getUsage() { return _cpu_usage; };
        std::string &getCores() { return _cores; };

    private:
        std::string _cpu_freq;
        std::string _cpu_model;
        std::string _cpu_usage;
        std::string _cores;
};

#endif
