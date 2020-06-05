#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "new_level.h"
#include "obiekty.h"
#include <time.h>
int main()
{
    sf::RenderWindow program(sf::VideoMode(500, 300), "Sea of Traders");
        std::vector<Obiekty> Baza;
    std::vector<Obiekty> Elementy;
    srand(time(NULL));
    std::cout<<"Loading"<<std::endl;
    sf::Texture p;
    if (!p.loadFromFile("Przeszkody/Wrak.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(p,true,0,0));
    sf::Texture q;
    if (!q.loadFromFile("Przeszkody/KHuge.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(q,false,0,0));
    sf::Texture w;
    if (!w.loadFromFile("Przeszkody/KSmall.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(w,false,0,0));
    sf::Texture e;
    if (!e.loadFromFile("Przeszkody/P7x13.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(e,false,0,30));
    sf::Texture r;
    if (!r.loadFromFile("Przeszkody/P7x14.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(r,false,0,85));
    sf::Texture t;
    if (!t.loadFromFile("Przeszkody/P11x12.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(t,false,75,0));
    sf::Texture y;
    if (!y.loadFromFile("Przeszkody/P12x7.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(y,false,100,0));
    sf::Texture u;
    if (!u.loadFromFile("Przeszkody/P14x5.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(u,false,85,0));
    sf::Texture i;
    if (!i.loadFromFile("Przeszkody/P24x7.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(i,false,100,0));
    sf::Texture o;
    if (!o.loadFromFile("Przeszkody/P29x7.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(o,false,0,50));
    sf::Texture b;
    if (!b.loadFromFile("Przeszkody/P31x9.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(b,false,0,150));
    sf::Texture n;
    if (!n.loadFromFile("Przeszkody/P43x9.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.push_back(Obiekty(n,false,60,0));
    Elementy=Baza;
    sf::RectangleShape astart(sf::Vector2f(47,40));
    astart.setFillColor(sf::Color::Green);
    astart.setPosition(0,268);
    sf::Texture startb;
    if (!startb.loadFromFile("StartDoc.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture finishb;
    if (!finishb.loadFromFile("FinishDoc.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture background;
    if (!background.loadFromFile("Ocean.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture statek;
    if (!statek.loadFromFile("Stateczki/StatekTier1.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture statek1;
    if (!statek1.loadFromFile("Stateczki/StatekTier2.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    Player PlayerOne("Alpa",statek);
    sf::Clock clock;
    background.setRepeated(true);
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(1,1);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,1000,600));
    sf::Sprite start;
    start.setTexture(startb);
    start.setPosition(0,269);
    sf::Sprite finish;
    finish.setTexture(finishb);
    finish.setPosition(485,0);
    New_Level poziom(PlayerOne,Elementy);
    double level = 1;
    std::cout<<"Loading complite"<<std::endl;
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
        program.draw(astart);
        program.draw(backgroundSprite);
        program.draw(start);
        program.draw(finish);
        PlayerOne.Animate(elapsed);
        for(auto &pi:Elementy)
        {
            program.draw(pi);
        }
        for(auto &pi:Elementy)
        {
            pi.animate(elapsed,level,astart);
        }
        program.draw(PlayerOne);
        program.display();

        for(auto &p:Elementy)
        {
            if(p.getGlobalBounds().intersects(PlayerOne.getGlobalBounds()))
            {
                if(p.cansearch())
                {
                    std::cout<<"Zyskujesz pieniadze"<<std::endl;
                    PlayerOne.addMoney(50);
                    Elementy.erase(Elementy.begin());
                }
                else
                {
                    //std::cout<<"Tracisz pieniadze"<<std::endl;
                    PlayerOne.AddHit();
                    PlayerOne.loseLives();
                    PlayerOne.showLives();
                    PlayerOne.setPosition(15,270);
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            PlayerOne.showMoney();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            if(PlayerOne.retrunMoney()>=1000)
            {
                PlayerOne.LoseMoney(1000);
                PlayerOne.upgrade(statek1);
            }
            else
            {
                //std::cout<<"nie stac cie biedaku musisz 1000 złota na to "<<std::endl;
            }

        }
        if(finish.getGlobalBounds().intersects(PlayerOne.getGlobalBounds()))
        {
            level ++;
            Elementy=Baza;
            PlayerOne.addMoney(100);
            New_Level poziom(PlayerOne,Elementy);

        }
        if(PlayerOne.returnLives()==0)
        {
            std::cout<<"Przegrales, dziekuje za gre"<<std::endl;
            PlayerOne.ShowStatistic(level);
            return 1;
        }
    }

}
