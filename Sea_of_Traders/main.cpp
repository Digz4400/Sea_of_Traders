#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "obiekty.h"
#include <time.h>
#include <cstdlib>
void New_Level(Player &PlayerOne, std::vector<Obiekty> &Elementy, std::vector<Obiekty> &Baza)
{

    /*if(rand()%5==3)
    {
        switch (rand()%7)
        {
        case 0:{PlayerOne.setWiatr(0,-10);std::cout<<"Masz wiatr N"<<std::endl;break;}
        case 1:{PlayerOne.setWiatr(10,-10);std::cout<<"Masz wiatr NE"<<std::endl;break;}
        case 2:{PlayerOne.setWiatr(10,0);std::cout<<"Masz wiatr E"<<std::endl;break;}
        case 3:{PlayerOne.setWiatr(10,10);std::cout<<"Masz wiatr SE"<<std::endl;break;}
        case 4:{PlayerOne.setWiatr(0,10);std::cout<<"Masz wiatr S"<<std::endl;break;}
        case 5:{PlayerOne.setWiatr(-10,10);std::cout<<"Masz wiatr SW"<<std::endl;break;}
        case 6:{PlayerOne.setWiatr(-10,0);std::cout<<"Masz wiatr W"<<std::endl;break;}
        case 7:{PlayerOne.setWiatr(-10,-10);std::cout<<"Masz wiatr NW"<<std::endl;break;}
        }
    }*/
    if(rand()%2)
    {
        Elementy=Baza;
    }
    else
    {
        Elementy.clear();
        Elementy.emplace_back(Baza[0]);
    for(int i =0;i<rand()%20+10;i++)
    {
        Elementy.emplace_back(Baza[1]);
    }
    for(int i=0;i<rand()%20+10;i++)
    {
        Elementy.emplace_back(Baza[2]);
    }
    }
    //std::cout<<"New Level"<<std::endl;
    //std::cout<<PlayerOne.retrunMoney()<<std::endl;
    PlayerOne.resetLives();
    PlayerOne.resetPosition();
    for(auto &pi:Elementy)
    {
            int a=rand()%450+50;
            int b=rand()%250+35;
            pi.setPosition(a,b);
    }
}
void Menu(sf::Sprite &background)
{
    sf::RenderWindow menu(sf::VideoMode(500,300),"Menu");
    sf::Texture button_baza;

    if (!button_baza.loadFromFile("Inne/Button.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture title_baza;
    if(!title_baza.loadFromFile("Inne/Title.png"))
    {
       std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture button2_baza;
    if(!button2_baza.loadFromFile("Inne/Button2.png"))
    {
       std::cerr << "Could not load texture" << std::endl;
    }

    sf::Sprite button;
    button.setTexture(button_baza);
    button.setScale(4,4);
    button.setPosition(100,156);

    sf::Sprite title;
    title.setTexture(title_baza);
    title.setScale(3,3);
    title.setPosition(136,68);

    sf::Sprite button2;
    button2.setTexture(button2_baza);
    button2.setScale(4,4);
    button2.setPosition(280,156);

    while (menu.isOpen())
    {
        sf::Event event;
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                menu.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
                    {
                        if(event.mouseButton.button == sf::Mouse::Left)
                        {
                            sf::Vector2i mouse_pos = sf::Mouse::getPosition(menu);
                            if((mouse_pos.x > button.getGlobalBounds().left)&&(mouse_pos.x < button.getGlobalBounds().left + button.getGlobalBounds().width)&&(mouse_pos.y > button.getGlobalBounds().top)&&(mouse_pos.y < button.getGlobalBounds().top + button.getGlobalBounds().height))
                            {
                                menu.close();
                            }
                        }
                        if(event.mouseButton.button == sf::Mouse::Left)
                        {
                            sf::Vector2i mouse_pos = sf::Mouse::getPosition(menu);
                            if((mouse_pos.x > button2.getGlobalBounds().left)&&(mouse_pos.x < button2.getGlobalBounds().left + button2.getGlobalBounds().width)&&(mouse_pos.y > button2.getGlobalBounds().top)&&(mouse_pos.y < button2.getGlobalBounds().top + button2.getGlobalBounds().height))
                            {
                                system("Instrukcja.txt");
                            }
                        }
                    }
        menu.draw(background);
        menu.draw(title);
        menu.draw(button);
        menu.draw(button2);
        menu.display();
    }
}
int main()
{
    sf::Texture background;
    if (!background.loadFromFile("Ocean.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    background.setRepeated(true);
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(1,1);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,500,300));

    Menu(backgroundSprite);


    sf::RenderWindow program(sf::VideoMode(500, 300), "Sea of Traders");
        std::vector<Obiekty> Baza;
    std::vector<Obiekty> Elementy;
    srand(time(NULL));
    std::cout<<"Loading"<<std::endl;
    sf::Texture we;
    if (!we.loadFromFile("Przeszkody/KSuperHuge.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Sprite pulapka;
    pulapka.setTexture(we);
    pulapka.setPosition(0,0);
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
    sf::Sprite start;
    start.setTexture(startb);
    start.setPosition(0,260);
    sf::Sprite finish;
    finish.setTexture(finishb);
    finish.setPosition(485,0);
    New_Level(PlayerOne,Elementy,Baza);
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
            pi.animate(elapsed,level,start,pulapka);
        }
        program.draw(pulapka);
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
                    PlayerOne.AddHit();
                    PlayerOne.loseLives();
                    PlayerOne.showLives();
                    PlayerOne.setPosition(15,270);
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {

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

            }
        }
        if(PlayerOne.getGlobalBounds().intersects(pulapka.getGlobalBounds()))
        {
            PlayerOne.resetPosition();
        }
        if(finish.getGlobalBounds().intersects(PlayerOne.getGlobalBounds()))
        {
            level ++;
            Elementy=Baza;
            PlayerOne.addMoney(100);
            New_Level(PlayerOne,Elementy,Baza);
        }
        if(PlayerOne.returnLives()==0)
        {
            std::cout<<"Przegrales, dziekuje za gre"<<std::endl;
            PlayerOne.ShowStatistic(level);
            return 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            New_Level(PlayerOne,Elementy,Baza);
        }
    }

}
