#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Gracz : public sf::Sprite
{
public:
    Gracz(std::string a, sf::Texture &baza)
    {
        name = a;
        lives = 3;
        poziom = 1;
        velocity_x = 100;
        velocity_y = 100;
        setTexture(baza);
        setTextureRect(sf::IntRect(32,32,32,32));
        setPosition(0,0);
    }
    void LoadingTier(sf::Texture &baza)
    {
        Tier.emplace_back(baza);
    }
    void Upgrade()
    {
        poziom++;
        velocity_x*=poziom;
        velocity_y*=poziom;
        //setTexture(Tier[poziom]);
        //setTextureRect(sf::IntRect(32,32,32,32));
    }
    void animate(sf::Time elapsed)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
                move(0.0, -(velocity_y*elapsed.asSeconds()));
                setTextureRect(sf::IntRect(32,0,32,32));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
                move(0.0, (velocity_y*elapsed.asSeconds()));
                setTextureRect(sf::IntRect(32,64,32,32));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
                move(-(velocity_x*elapsed.asSeconds()), 0.0);
                setTextureRect(sf::IntRect(0,32,32,32));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
                move((velocity_x*elapsed.asSeconds()), 0.0);
                setTextureRect(sf::IntRect(64,32,32,32));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            Upgrade();
        }
    }

private:
    std::string name;
    int lives;
    int poziom;
    float velocity_x;
    float velocity_y;
    std::vector<sf::Texture> Tier;
};

int main()
{
    sf::RenderWindow program(sf::VideoMode(1000, 600), "Sea of Traders");
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
    Gracz PlayerOne("Alpa",statek);
    sf::Texture statek1;
    if (!statek1.loadFromFile("StatekTier2.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture statek2;
    if (!statek2.loadFromFile("StatekTier3.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    PlayerOne.LoadingTier(statek);
    PlayerOne.LoadingTier(statek1);
    PlayerOne.LoadingTier(statek2);
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
        PlayerOne.animate(elapsed);
        program.draw(PlayerOne);
        program.display();
    }

}
