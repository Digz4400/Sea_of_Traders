#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "new_level.h"
#include "obiekty.h"
int main()
{
    sf::RenderWindow program(sf::VideoMode(500, 300), "Sea of Traders");
    sf::IntRect bounds_program(0,0,program.getSize().x,program.getSize().y);
    sf::Clock clock;
    sf::Texture background;
    if (!background.loadFromFile("Ocean.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    background.setRepeated(true);
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(1,1);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,1000,600));
    sf::Texture statek;
    if (!statek.loadFromFile("StatekTier1.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    Player PlayerOne("Alpa",statek);
    sf::Texture startb;
    if (!startb.loadFromFile("StartDoc.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture finishb;
    if (!finishb.loadFromFile("FinishDoc.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Sprite start;
    start.setTexture(startb);
    start.setPosition(0,269);
    sf::Sprite finish;
    finish.setTexture(finishb);
    finish.setPosition(485,0);
    while (program.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (program.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                program.close();
        }
        program.clear();
        program.draw(backgroundSprite);
        program.draw(start);
        program.draw(finish);
        PlayerOne.Animate(elapsed,bounds_program);
        program.draw(PlayerOne);
        program.display();
    }

}
