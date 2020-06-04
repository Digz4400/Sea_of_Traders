#include "new_level.h"
#include "player.h"
#include "obiekty.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
New_Level::New_Level(Player &PlayerOne, std::vector<Obiekty> &p)
{
    std::cout<<"New Level"<<std::endl;
    PlayerOne.resetLives();
    PlayerOne.setPosition(15,270);
    for(auto &pi:p)
    {
        int a=rand()%475;
        int b=rand()%259+42;
        pi.setPosition(a,b);
        if(pi.cansearch())
        {
            pi.setScale(a,b);
        }
        else
        {
            double x =(rand()%201+150)/100;
            pi.setScale(x,x);
        }
    }

}
