#include "obiekty.h"

Obiekty::Obiekty(sf::Texture &baza,std::vector<sf::Vector2f> positions, bool can_S)
{
    this->setTexture(baza);
    int a = rand()%positions.size();
    this->setPosition(positions[a]);
    auto i = positions.begin()+a;
    positions.erase(i);
    if(can_S==true) this->can_search=true;
    gold = rand()%200+50;
}
