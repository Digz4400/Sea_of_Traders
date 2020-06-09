#include "player.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void Player::LoadingTier(sf::Texture &baza)
{
    Tier.emplace_back(baza);
}
void Player::resetPosition()
{
    setPosition(15,270);
}
void Player::Animate(sf::Time elapsed)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(this->getPosition().y>0)
        {
            move(0, -(velocity_y*elapsed.asSeconds()));
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
            move(0, (velocity_y*elapsed.asSeconds()));
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
         move(-(velocity_x*elapsed.asSeconds()), 0);
         }
        else
        {
            move(0+wiatr.x,0+wiatr.y);
        }
         setTextureRect(sf::IntRect(0,32,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
         if(this->getPosition().x<500-32)
         {
            move((velocity_x*elapsed.asSeconds()), 0);
          }
         else
         {
             move(0,0);
         }
            setTextureRect(sf::IntRect(64,32,32,32));
    }
    /*else
    {
        move(wiatr.x,wiatr.y);
    }*/
}
Player::Player(std::string a, sf::Texture &baza)
{
    name = a;
    lives = lives_max;
    velocity_x = 100;
    velocity_y = 100;
    iloscUderzonychObiektow=0;
    setTexture(baza);
    setTextureRect(sf::IntRect(32,32,32,32));
    setPosition(15,270);
    wiatr = sf::Vector2f(0,0);
}
void Player::addMoney(int a)
{
    gold +=a;
}
void Player::showMoney()
{
     std::cout<<"Ilosc pieniedzy: "<<gold<<std::endl;
}
void Player::upgrade(sf::Texture &a)
{
    if(afterupgrage)
    {
        std::cout<<"Nie mozesz juz ulepszyc statku"<<std::endl;
    }
    else
    {
    setTexture(a);
    setTextureRect(sf::IntRect(32,32,32,32));
    velocity_x=150;
    velocity_y=150;
    lives_max*=2;
    lives = lives_max;
    afterupgrage=true;
    }
}
int Player::retrunMoney()
{
    return gold;
}
void Player::LoseMoney(int a)
{
    if(gold<=0)
    {
        gold = 0;
    }
    else
    {
       gold=-a;
    }
}
void Player::loseLives()
{
    lives--;
}
int Player::returnLives()
{
    return lives;
}
void Player::resetLives()
{
    lives = lives_max;
}
void Player::ShowStatistic(int level)
{
    std::cout<<"ilosc zagranych poziomow: "<<level<<std::endl;
    std::cout<<"Ilosc zlota: "<<gold<<std::endl;
    if(afterupgrage)
    {
        std::cout<<"Udało ci się ulepszyć statek"<<std::endl;
    }
    else
    {
        std::cout<<"Nie udalo ci sie ulepszyc statku"<<std::endl;
    }
    std::cout<<"Ilosc uderzonych obiektow: "<<iloscUderzonychObiektow<<std::endl;
}
void Player::AddHit()
{
    iloscUderzonychObiektow++;
}
void Player::showLives()
{
    std::cout<<"Lives left: "<<lives<<std::endl;
}
void Player::setWiatr(int a, int b)
{
    wiatr = sf::Vector2f(a,b);
}
