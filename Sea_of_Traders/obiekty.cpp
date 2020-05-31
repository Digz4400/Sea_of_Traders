#include "obiekty.h"

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
