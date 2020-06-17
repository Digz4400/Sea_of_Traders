#include "player.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
int Player::returnHit()
{
    return iloscUderzonychObiektow;
}
void Player::hearts(sf::Sprite &s)
{
    if(afterupgrage)
    {
        s.setTextureRect(sf::IntRect(0,0,80-8*(lives_max-lives),16));
    }
    else
    {
       s.setTextureRect(sf::IntRect(0,0,80-16*(lives_max-lives),16));
    }
}
void Player::resetPosition()
{
    setPosition(15,570);
    sf::Clock *cl=new sf::Clock;
    while (cl->getElapsedTime().asSeconds()<0.25)
    {

    }
    delete cl;
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
        if(this->getPosition().y<600-32)
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
            move(0,0);
        }
         setTextureRect(sf::IntRect(0,32,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
         if(this->getPosition().x<1000-32)
         {
            move((velocity_x*elapsed.asSeconds()), 0);
          }
         else
         {
             move(0,0);
         }
         setTextureRect(sf::IntRect(64,32,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
         setTextureRect(sf::IntRect(64,0,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
         setTextureRect(sf::IntRect(64,64,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
         setTextureRect(sf::IntRect(0,64,32,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
         setTextureRect(sf::IntRect(0,0,32,32));
    }
}
Player::Player(sf::Texture &baza)
{

    lives = lives_max;
    velocity_x = 100;
    velocity_y = 100;
    iloscUderzonychObiektow=0;
    setTexture(baza);
    setTextureRect(sf::IntRect(32,32,32,32));
    setPosition(15,570);
    lives_max = 5;
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
