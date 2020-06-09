#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>

class Player : public sf::Sprite
{
public:
    Player(std::string a, sf::Texture &baza);
    void Animate(sf::Time);
    void LoadingTier(sf::Texture &baza);
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
    void showLives();
    void resetPosition();
    void setWiatr(int a,int b);
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
    sf::Vector2f wiatr;
};

#endif // PLAYER_H
