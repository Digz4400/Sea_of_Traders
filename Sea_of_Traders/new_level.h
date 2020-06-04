#ifndef NEW_LEVEL_H
#define NEW_LEVEL_H
#include <iostream>
#include "player.h"
#include "obiekty.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class New_Level
{
public:
    New_Level(Player &a, std::vector<Obiekty> &p,sf::RenderWindow &program);
};

#endif // NEW_LEVEL_H
