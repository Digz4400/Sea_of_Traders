#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
public:
    Player(std::string a, sf::Texture &baza)
    {
        name = a;
        lives = 3;
        poziom = 1;
        velocity_x = 100;
        velocity_y = 100;
        setTexture(baza);
        setTextureRect(sf::IntRect(32,32,32,32));
        setPosition(15,270);
    };
    void Upgrade();
    void Animate(sf::Time,sf::IntRect);
    void LoadingTier(sf::Texture&);
private:
    std::string name;
    int lives;
    int poziom;
    float velocity_x;
    float velocity_y;
    std::vector<sf::Texture> Tier;
    int gold = 0;
};

#endif // PLAYER_H
