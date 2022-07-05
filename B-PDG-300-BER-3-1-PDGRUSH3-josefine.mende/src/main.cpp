/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** main
*/

#include "../include/IMonitor.hpp"
#include "../include/TextMonitor.hpp"
#include "../include/GraphicalMonitor.hpp"
#include "../include/GraphMode.hpp"
#include <string.h>

void ncursesLoop(TextMonitor monitor);

void printHelp()
{
    std::cout << "Usage: ./MyGKrellm [TEXT|GRAPHICAL]" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printHelp();
        return -1;
    };
    if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0) {
        printHelp();
        return 0;
    }
    enum DisplayMode {
        TEXT,
        GRAPHICAL
    };
    DisplayMode mode;
    if (strcmp(av[1], "TEXT") == 0)
        mode = TEXT;
    else if (strcmp(av[1], "GRAPHICAL") == 0)
        mode = GRAPHICAL;
    else {
        printHelp();
        return -1;
    }

    if (mode == TEXT) {
        TextMonitor monitor;
        monitor.initialize();
        monitor.updateModules();
        ncursesLoop(monitor);
    } else {
        GraphicalMonitor monitor;
        monitor.initialize();
        graphModeDisplayer(monitor);
    }
    return 0;
}