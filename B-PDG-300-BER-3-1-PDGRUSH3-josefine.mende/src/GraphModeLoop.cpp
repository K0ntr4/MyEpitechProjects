/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** sfmlLoop
*/

#include "../include/GraphMode.hpp"
#include "../include/UsernameModule.hpp"

void graphModeDisplayer(GraphicalMonitor monitor)
{
    GraphMode *appWindow = new GraphMode;

    while (appWindow->window.isOpen()) {
        //HERE UPDATE ALL DATA WITH UPDATE FUNCTION OF MONITOR CALLING UPDATES OF MODULES;
        while (appWindow->window.pollEvent(appWindow->event)) {
            if (appWindow->event.type == sf::Event::Closed ||
                (appWindow->event.type == sf::Event::KeyPressed &&
                appWindow->event.key.code == sf::Keyboard::Q))
                appWindow->window.close();
            if (appWindow->event.type == sf::Event::KeyPressed) {
                if (appWindow->event.key.code == sf::Keyboard::U)
                    monitor.getUsernameModule().activate();
                if (appWindow->event.key.code == sf::Keyboard::D)
                    monitor.getDateModule().activate();
                if (appWindow->event.key.code == sf::Keyboard::O)
                    monitor.getOSKernelModule().activate();
                if (appWindow->event.key.code == sf::Keyboard::R)
                    monitor.getRAMModule().activate();
                if (appWindow->event.key.code == sf::Keyboard::N)
                    monitor.getNetworkModule().activate();
                if (appWindow->event.key.code == sf::Keyboard::C)
                    monitor.getCPUModule().activate();
            }            
        }
        appWindow->window.clear(sf::Color(100, 100, 100));

        monitor.updateModules();

        showUserModule(appWindow, monitor.getUsernameModule());
        showDateModule(appWindow, monitor.getDateModule());
        showOsKernelModule(appWindow, monitor.getOSKernelModule());
        showRAMModule(appWindow, monitor.getRAMModule());
        showCPUModule(appWindow, monitor.getCPUModule());
        showNetworkModule(appWindow, monitor.getNetworkModule());
        showShortcutsMenu(appWindow, monitor);
        //here come all the other display functions

        appWindow->window.display();
    }    
}