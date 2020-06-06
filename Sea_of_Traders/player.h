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
        lives = lives_max;
        velocity_x = 100;
        velocity_y = 100;
        iloscUderzonychObiektow=0;
        setTexture(baza);
        setTextureRect(sf::IntRect(32,32,32,32));
        setPosition(15,270);
    };
    void Animate(sf::Time);
    void LoadingTier(sf::Texture&);
    void addMoney(int a)
    {
        gold +=a;
    }
    void showMoney()
    {
        std::cout<<"Ilosc pieniedzy: "<<gold<<std::endl;
    }
    void upgrade(sf::Texture &a)
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
    int retrunMoney()
    {
        return gold;
    }
    void LoseMoney(int a)
    {
        if(gold-a<=0)
        {
            gold = 0;
        }
        else
        {
           gold=-a;
        }
    }
    void loseLives()
    {
        lives--;
    }
    int returnLives()
    {
       return lives;
    }
    void resetLives()
    {
        lives = lives_max;
    }
    void ShowStatistic(int level)
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
    void AddHit()
    {
        iloscUderzonychObiektow++;
    }
    void showLives()
    {
        std::cout<<"Lives left: "<<lives<<std::endl;
    }
private:
    std::string name;
    int lives;
    float velocity_x;
    float velocity_y;
    std::vector<sf::Texture> Tier;
    int gold = 0;
    int lives_max = 3;
    bool afterupgrage = false;
    int iloscUderzonychObiektow;
};

#endif // PLAYER_H
