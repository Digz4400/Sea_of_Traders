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
    velocity_x=wx;
    velocity_y=wy;
}
void Obiekty::animate(sf::Time elapsed,double poziom, sf::RectangleShape &start)
{
    poziom/=10;
    move(velocity_x*poziom*elapsed.asSeconds(),velocity_y*poziom*elapsed.asSeconds());
    bounce(start);
}
void Obiekty::bounce(sf::RectangleShape &start)
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
    if(getGlobalBounds().intersects(start.getGlobalBounds()))
    {
        velocity_y = -std::abs(velocity_y);
        velocity_x = std::abs(velocity_x);
    }
}
bool Obiekty::cansearch()
{
    if(this->can_search)
    {
        return true;
    }
    else
    {
        return false;
    }
}
