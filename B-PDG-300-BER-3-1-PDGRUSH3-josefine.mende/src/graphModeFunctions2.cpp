/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** graphModeFunctions2
*/

#include <SFML/Graphics.hpp>
#include "../include/GraphMode.hpp"
#include "../include/UsernameModule.hpp"
#include <iostream>

void showNetworkModule(GraphMode *appWindow, NetworkModule network)
{
    if (network.getActivated() != true)
        return;
    
    std::string incoming = "Incoming :       ";
    std::string outgoing = "Outgoing :       ";

    sf::Text InText;
    sf::Text OutText;
    sf::RectangleShape NetworkBox;

    incoming.append(network.getIncoming());
    outgoing.append(network.getOutgoing());

    NetworkBox.setSize(sf::Vector2f(600.0, 100.0));
    NetworkBox.setFillColor(sf::Color::Green);
    NetworkBox.setOutlineColor(sf::Color::Black);
    NetworkBox.setOutlineThickness(-2.0);
    NetworkBox.setPosition(sf::Vector2f(0.0, 505.0));

    InText.setString(incoming);
    InText.setCharacterSize(16);
    InText.setPosition(sf::Vector2f(10.0, 530.0));
    InText.setFont(appWindow->font);
    InText.setFillColor(sf::Color::Blue);

    OutText.setString(outgoing);
    OutText.setCharacterSize(16);
    OutText.setPosition(sf::Vector2f(10.0, 565.0));
    OutText.setFont(appWindow->font);
    OutText.setFillColor(sf::Color::Blue);

    appWindow->window.draw(NetworkBox);
    appWindow->window.draw(InText);
    appWindow->window.draw(OutText);
}

void showShortcutsMenu(GraphMode *appWindow, GraphicalMonitor Monitor)
{
    std::string USER = "USER :                U";
    std::string DATE = "DATE :                D";
    std::string OS =   "OS :                      O";
    std::string RAM =  "RAM :                 R";
    std::string NETWORK = "NETWORK :     N";
    std::string CPU =  "CPU :                 C";
    std::string QUIT = "QUIT : Q";

    sf::Text UText;
    sf::Text DText;
    sf::Text OText;
    sf::Text RText;
    sf::Text NText;
    sf::Text CText;
    sf::Text QText;
    sf::RectangleShape MenuBox;

    MenuBox.setSize(sf::Vector2f(600.0, 100.0));
    MenuBox.setFillColor(sf::Color::Green);
    MenuBox.setOutlineColor(sf::Color::Black);
    MenuBox.setOutlineThickness(-2.0);
    MenuBox.setPosition(sf::Vector2f(0.0, 606.0));

    UText.setString(USER);
    UText.setCharacterSize(16);
    UText.setPosition(sf::Vector2f(10.0, 625.0));
    UText.setFont(appWindow->font);
    if (Monitor.getUsernameModule().getActivated() != true)
        UText.setFillColor(sf::Color::Red);
    else
        UText.setFillColor(sf::Color::Blue);

    DText.setString(DATE);
    DText.setCharacterSize(16);
    DText.setPosition(sf::Vector2f(10.0, 650.0));
    DText.setFont(appWindow->font);
    if (Monitor.getDateModule().getActivated() != true)
        DText.setFillColor(sf::Color::Red);
    else
        DText.setFillColor(sf::Color::Blue);

    OText.setString(OS);
    OText.setCharacterSize(16);
    OText.setPosition(sf::Vector2f(10.0, 675.0));
    OText.setFont(appWindow->font);
    if (Monitor.getOSKernelModule().getActivated() != true)
        OText.setFillColor(sf::Color::Red);
    else
        OText.setFillColor(sf::Color::Blue);

    RText.setString(RAM);
    RText.setCharacterSize(16);
    RText.setPosition(sf::Vector2f(400.0, 625.0));
    RText.setFont(appWindow->font);
    if (Monitor.getRAMModule().getActivated() != true)
        RText.setFillColor(sf::Color::Red);
    else
        RText.setFillColor(sf::Color::Blue);
    
    NText.setString(NETWORK);
    NText.setCharacterSize(16);
    NText.setPosition(sf::Vector2f(400.0, 650.0));
    NText.setFont(appWindow->font);
    if (Monitor.getNetworkModule().getActivated() != true)
        NText.setFillColor(sf::Color::Red);
    else
        NText.setFillColor(sf::Color::Blue);

    CText.setString(CPU);
    CText.setCharacterSize(16);
    CText.setPosition(sf::Vector2f(400.0, 675.0));
    CText.setFont(appWindow->font);
    if (Monitor.getCPUModule().getActivated() != true)
        CText.setFillColor(sf::Color::Red);
    else
        CText.setFillColor(sf::Color::Blue);
    
    QText.setString(QUIT);
    QText.setCharacterSize(16);
    QText.setPosition(sf::Vector2f(270.0, 690.0));
    QText.setFont(appWindow->font);
    QText.setFillColor(sf::Color::Black);

    appWindow->window.draw(MenuBox);
    appWindow->window.draw(UText);
    appWindow->window.draw(DText);
    appWindow->window.draw(OText);
    appWindow->window.draw(RText);
    appWindow->window.draw(NText);
    appWindow->window.draw(CText);
    appWindow->window.draw(QText);
}