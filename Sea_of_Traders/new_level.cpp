#include "new_level.h"
#include "player.h"
#include "obiekty.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
New_Level::New_Level(Player &PlayerOne, std::vector<Obiekty> &p, sf::RenderWindow &program)
{
    std::cout<<"New Level"<<std::endl;

    PlayerOne.setPosition(15,270);
    for(auto &pi:p)
    {
        pi.setPosition(rand()%500,rand()%300);
    }

}
