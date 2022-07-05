/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** graphModeFunctions
*/

#include <SFML/Graphics.hpp>
#include "../include/GraphMode.hpp"
#include "../include/UsernameModule.hpp"
#include <iostream>

void showUserModule(GraphMode *appWindow, UsernameModule user)
{
    if (user.getActivated() != true)
        return;
    
    sf::Text displayUserName;
    sf::Text displayHostName;
    sf::RectangleShape userBox;

    std::string usr = "User :                 ";
    std::string host = "Host :                  ";

    usr.append(user.getUsername());
    host.append(user.getHostname());


    userBox.setSize(sf::Vector2f(600.0, 100.0));
    userBox.setFillColor(sf::Color::Green);
    userBox.setOutlineColor(sf::Color::Black);
    userBox.setOutlineThickness(-2.0);
    userBox.setPosition(sf::Vector2f(0.0, 0.0));

    displayUserName.setString(usr);
    displayUserName.setCharacterSize(16);
    displayUserName.setPosition(sf::Vector2f(10.0, 30.0));
    displayUserName.setFont(appWindow->font);
    displayUserName.setFillColor(sf::Color::Blue);

    displayHostName.setString(host);
    displayHostName.setCharacterSize(16);
    displayHostName.setPosition(sf::Vector2f(10.0, 65.0));
    displayHostName.setFont(appWindow->font);
    displayHostName.setFillColor(sf::Color::Blue);

    appWindow->window.draw(userBox);
    appWindow->window.draw(displayHostName);
    appWindow->window.draw(displayUserName);
}

void showDateModule(GraphMode *appWindow, Date date)
{

    if (date.getActivated() != true)
        return;

    std::string datetime = "Date & Time :   ";
    sf::Text dateTime;
    sf::RectangleShape DateBox;
    sf::Texture *image;

    datetime.append(date.getDateTime());

    DateBox.setSize(sf::Vector2f(600.0, 100.0));
    DateBox.setFillColor(sf::Color::Green);
    DateBox.setOutlineColor(sf::Color::Black);
    DateBox.setOutlineThickness(-2.0);
    DateBox.setPosition(sf::Vector2f(0.0, 101.0));

    dateTime.setString(datetime);
    dateTime.setCharacterSize(16);
    dateTime.setPosition(sf::Vector2f(10.0, 151.0));
    dateTime.setFont(appWindow->font);
    dateTime.setFillColor(sf::Color::Blue);

    appWindow->window.draw(DateBox);
    appWindow->window.draw(dateTime);
}

void showOsKernelModule(GraphMode *appWindow, OSKernelModule oskernel)
{
    if (oskernel.getActivated() != true)
        return;
    
    std::string OS = "OS :                       ";
    std::string Kernel = "Kernel :            ";
    OS.append(oskernel.getOperatingSystemName());
    Kernel.append(oskernel.getKernelVersion());

    sf::Text OsText;
    sf::Text KernelText;
    sf::RectangleShape OSKernelBox;

    OSKernelBox.setSize(sf::Vector2f(600.0, 100.0));
    OSKernelBox.setFillColor(sf::Color::Green);
    OSKernelBox.setOutlineColor(sf::Color::Black);
    OSKernelBox.setOutlineThickness(-2.0);
    OSKernelBox.setPosition(sf::Vector2f(0.0, 202.0));

    OsText.setString(OS);
    OsText.setCharacterSize(16);
    OsText.setPosition(sf::Vector2f(10.0, 230.0));
    OsText.setFont(appWindow->font);
    OsText.setFillColor(sf::Color::Blue);

    KernelText.setString(Kernel);
    KernelText.setCharacterSize(16);
    KernelText.setPosition(sf::Vector2f(10.0, 265.0));
    KernelText.setFont(appWindow->font);
    KernelText.setFillColor(sf::Color::Blue);

    appWindow->window.draw(OSKernelBox);
    appWindow->window.draw(OsText);
    appWindow->window.draw(KernelText);
}

void showRAMModule(GraphMode *appWindow, RAMModule ram)
{
    if (ram.getActivated() != true)
        return;
    
    std::string freememory = "Free Memory : ";
    std::string totalram = "Total Memory : ";

    sf::Text FreeRAMText;
    sf::Text TotalRAMText;
    sf::RectangleShape RAMBox;
    
    freememory.append(ram.getFreeRAM());
    totalram.append(ram.getAvRAM());

    RAMBox.setSize(sf::Vector2f(600.0, 100.0));
    RAMBox.setFillColor(sf::Color::Green);
    RAMBox.setOutlineColor(sf::Color::Black);
    RAMBox.setOutlineThickness(-2.0);
    RAMBox.setPosition(sf::Vector2f(0.0, 303.0));

    FreeRAMText.setString(freememory);
    FreeRAMText.setCharacterSize(16);
    FreeRAMText.setPosition(sf::Vector2f(10.0, 330.0));
    FreeRAMText.setFont(appWindow->font);
    FreeRAMText.setFillColor(sf::Color::Blue);

    TotalRAMText.setString(totalram);
    TotalRAMText.setCharacterSize(16);
    TotalRAMText.setPosition(sf::Vector2f(10.0, 365.0));
    TotalRAMText.setFont(appWindow->font);
    TotalRAMText.setFillColor(sf::Color::Blue);

    appWindow->window.draw(RAMBox);
    appWindow->window.draw(FreeRAMText);
    appWindow->window.draw(TotalRAMText);
}

void showCPUModule(GraphMode *appWindow, CPUModule cpu)
{
    if (cpu.getActivated() != true)
        return;
    
    std::string model = "Model :               ";
    std::string freq = "Frequency : ";
    std::string usage = "Usage :             ";
    std::string cores = "Cores :             ";

    sf::Text ModelText;
    sf::Text FreqText;
    sf::Text UsageText;
    sf::Text CoresText;
    sf::RectangleShape CPUBox;

    model.append(cpu.getModel());
    freq.append(cpu.getFreq());
    usage.append(cpu.getUsage());
    cores.append(cpu.getCores());

    CPUBox.setSize(sf::Vector2f(600.0, 100.0));
    CPUBox.setFillColor(sf::Color::Green);
    CPUBox.setOutlineColor(sf::Color::Black);
    CPUBox.setOutlineThickness(-2.0);
    CPUBox.setPosition(sf::Vector2f(0.0, 404.0));

    ModelText.setString(model);
    ModelText.setCharacterSize(16);
    ModelText.setPosition(sf::Vector2f(10.0, 420.0));
    ModelText.setFont(appWindow->font);
    ModelText.setFillColor(sf::Color::Blue);

    FreqText.setString(freq);
    FreqText.setCharacterSize(16);
    FreqText.setPosition(sf::Vector2f(10.0, 443.0));
    FreqText.setFont(appWindow->font);
    FreqText.setFillColor(sf::Color::Blue);

    UsageText.setString(usage);
    UsageText.setCharacterSize(16);
    UsageText.setPosition(sf::Vector2f(10.0, 468.0));
    UsageText.setFont(appWindow->font);
    UsageText.setFillColor(sf::Color::Blue);

    CoresText.setString(cores);
    CoresText.setCharacterSize(16);
    CoresText.setPosition(sf::Vector2f(10.0, 490.0));
    CoresText.setFont(appWindow->font);
    CoresText.setFillColor(sf::Color::Blue);

    appWindow->window.draw(CPUBox);
    appWindow->window.draw(ModelText);
    appWindow->window.draw(FreqText);
    appWindow->window.draw(UsageText);
    appWindow->window.draw(CoresText);
}
