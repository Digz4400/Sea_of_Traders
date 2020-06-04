#include "player.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void Player::LoadingTier(sf::Texture &baza)
{
    Tier.emplace_back(baza);
}
void Player::Upgrade()
{
    poziom++;
    velocity_x*=poziom;
    velocity_y*=poziom;
};
void Player::Animate(sf::Time elapsed)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(this->getPosition().y>0)
        {
            move(0.0, -(velocity_y*elapsed.asSeconds()));
        }
        else
        {
            move(0,0);
        }
            setTextureRect(sf::IntRect(32,0,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(this->getPosition().y<300-32)
        {
            move(0.0, (velocity_y*elapsed.asSeconds()));
        }
        else
        {
            move(0,0);
        }
            setTextureRect(sf::IntRect(32,64,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(this->getPosition().x>0)
        {
         move(-(velocity_x*elapsed.asSeconds()), 0.0);
         }
        else
        {
            move(0,0);
        }
         setTextureRect(sf::IntRect(0,32,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
         if(this->getPosition().x<500-32)
         {
            move((velocity_x*elapsed.asSeconds()), 0.0);
          }
         else
         {
             move(0,0);
         }
            setTextureRect(sf::IntRect(64,32,32,32));
    }
    //std::cout<<"X: "<<this->getPosition().x<<" Y: "<<this->getPosition().y<<std::endl;
}
