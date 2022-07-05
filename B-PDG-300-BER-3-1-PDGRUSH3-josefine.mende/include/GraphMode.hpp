/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** GraphMode
*/

#ifndef GRAPHMODE_HPP_
#define GRAPHMODE_HPP_

#include <SFML/Graphics.hpp>
#include "../include/GraphicalMonitor.hpp"

class GraphMode
{
    public:
        GraphMode();
        ~GraphMode();

        sf::RenderWindow window;
        sf::Event event;
        sf::Font font;
};

void graphModeDisplayer(GraphicalMonitor Monitor);

void showUserModule(GraphMode *appWindow, UsernameModule user);
void showDateModule(GraphMode *appWindow, Date date);
void showOsKernelModule(GraphMode *appWindow, OSKernelModule oskernel);
void showRAMModule(GraphMode *appWindow, RAMModule ram);
void showCPUModule(GraphMode *appWindow, CPUModule cpu);
void showNetworkModule(GraphMode *appWindow, NetworkModule network);
void showShortcutsMenu(GraphMode *appWindow, GraphicalMonitor Monitor);

#endif /* !GRAPHMODE_HPP_ */
