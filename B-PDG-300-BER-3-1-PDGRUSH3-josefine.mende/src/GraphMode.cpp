/*
** EPITECH PROJECT, 2022
** FINAL
** File description:
** GraphMode
*/

#include "../include/GraphMode.hpp"

GraphMode::GraphMode() : window(sf::VideoMode(600,706), "GKrellm")
{
    this->font.loadFromFile("font/Minecraftia-Regular.ttf");
}

GraphMode::~GraphMode()
{
}

