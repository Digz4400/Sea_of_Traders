#ifndef OBIEKTY_H
#define OBIEKTY_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Obiekty : public sf::Sprite
{
public:
    Obiekty(sf::Texture &baza,std::vector<sf::Vector2f> positions, bool can_S);
private:
    bool can_search = false;
    int gold;
    float velocity_x;
    float velocity_y;


};

#endif // OBIEKTY_H
