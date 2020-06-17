#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>

class Player : public sf::Sprite
{
public:
    Player(sf::Texture &baza);
    void Animate(sf::Time);
    void addMoney(int a);
    void showMoney();
    void upgrade(sf::Texture &a);
    int retrunMoney();
    void LoseMoney(int a);
    void loseLives();
    int returnLives();
    void resetLives();
    void ShowStatistic(int level);
    void AddHit();
    void resetPosition();
    void hearts(sf::Sprite &);
    int returnHit();
    bool returnUpgrade();
private:
    std::string name;
    int lives;
    float velocity_x = 0;
    float velocity_y = 0;
    int gold = 0;
    int lives_max;
    bool afterupgrage = false;
    int iloscUderzonychObiektow;
};

#endif // PLAYER_H
