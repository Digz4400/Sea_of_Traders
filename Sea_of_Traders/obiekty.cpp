#include "obiekty.h"
#include <time.h>
#include <cstdlib>
Obiekty::Obiekty(sf::Texture &baza, bool can_S, int wx,int wy)
{
    this->setTexture(baza);
    if(can_S)
    {
    this->can_search=true;
    gold = rand()%200+50;
    }
    velocity_x=10;
    velocity_y=0;
}
void Obiekty::animate(sf::Time elapsed)
{
    move(velocity_x*elapsed.asSeconds(),velocity_y*elapsed.asSeconds());
    bounce();
}
void Obiekty::bounce()
{
    auto object_bounds = this->getGlobalBounds();
    if(object_bounds.left < 0)
    {
        velocity_x = std::abs(velocity_x);
    }

    if(object_bounds.top < 0)
    {
        velocity_y = std::abs(velocity_y);
    }

    if(object_bounds.left+object_bounds.width > 500)
    {
        velocity_x = -std::abs(velocity_x);
    }

    if(object_bounds.top+object_bounds.height > 300)
    {
        velocity_y = -std::abs(velocity_y);
    }
}
