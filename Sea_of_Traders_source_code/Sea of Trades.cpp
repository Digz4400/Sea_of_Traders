﻿#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include "obiekty.h"
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <memory>
#include <fstream>
void EndGame(const int& a)
{
    std::fstream plik;
    plik.open("Best.txt", std::ios::in);
    int line1;
    std::string nick;
    plik >> line1;
    if (line1 < a)
    {
        plik.close();
        std::cout << "Brawo masz nowy najlepszy wynik" << std::endl;
        std::cout << "Wpisz teraz swoj nick: " << std::endl;
        std::fstream plik2;
        getline(std::cin, nick);
        std::cout << std::endl;
        plik2.open("Best.txt", std::ios::trunc | std::ios::out);
        plik2 << a << std::endl;
        plik2 << nick << std::endl;
        std::cout << "Dziekuje za gre" << std::endl;
        plik2.close();
    }
    else
    {
        std::cout << "Niestety nie udalo ci sie pokonac najlepszego wyniku" << std::endl;
        plik.close();
    }
    system("Pause");
}

void wait()
{
    sf::sleep(sf::seconds(0.25));
}
void New_Level(Player& PlayerOne, std::vector<Obiekty>& Elementy, const std::vector<Obiekty>& Baza)
{
    if (rand() % 2)
    {
        for (int i = 0; i < 3; i++)
        {
            for (auto& p : Baza)
            {
                Elementy.emplace_back(p);
            }
        }
    }
    else
    {
        Elementy.emplace_back(Baza[0]);
        for (int i = 0; i < rand() % 30 + 20; i++)
        {
            Elementy.emplace_back(Baza[1]);
        }
        for (int i = 0; i < rand() % 30 + 20; i++)
        {
            Elementy.emplace_back(Baza[2]);
        }
    }
    PlayerOne.resetLives();
    PlayerOne.resetPosition();
    for (auto& pi : Elementy)
    {
        int a = rand() % 950 + 50;
        int b = rand() % 550 + 35;
        pi.setPosition(a, b);
    }
}
void Menu(const sf::Sprite& background)
{
    sf::RenderWindow menu(sf::VideoMode(1000, 600), "Menu");
    sf::Texture button_baza;
    if (!button_baza.loadFromFile("Inne/Button.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture title_baza;
    if (!title_baza.loadFromFile("Inne/Title.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture button2_baza;
    if (!button2_baza.loadFromFile("Inne/Button2.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }

    sf::Sprite button;
    button.setTexture(button_baza);
    button.setScale(8, 8);
    button.setPosition(210, 336);

    sf::Sprite title;
    title.setTexture(title_baza);
    title.setScale(6, 6);
    title.setPosition(272, 172);

    sf::Sprite button2;
    button2.setTexture(button2_baza);
    button2.setScale(8, 8);
    button2.setPosition(550, 336);

    while (menu.isOpen())
    {
        sf::Event event;
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                menu.close();
                exit(1);
            }
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(menu);
                if ((mouse_pos.x > button.getGlobalBounds().left) && (mouse_pos.x < button.getGlobalBounds().left + button.getGlobalBounds().width) && (mouse_pos.y > button.getGlobalBounds().top) && (mouse_pos.y < button.getGlobalBounds().top + button.getGlobalBounds().height))
                {
                    menu.close();
                }
            }
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(menu);
                if ((mouse_pos.x > button2.getGlobalBounds().left) && (mouse_pos.x < button2.getGlobalBounds().left + button2.getGlobalBounds().width) && (mouse_pos.y > button2.getGlobalBounds().top) && (mouse_pos.y < button2.getGlobalBounds().top + button2.getGlobalBounds().height))
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

    std::vector<Obiekty> Baza;
    std::vector<Obiekty> Elementy;
    srand(time(NULL));
    std::cout << "Loading" << std::endl;

    sf::Texture background;
    if (!background.loadFromFile("Inne/Ocean.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture we;
    if (!we.loadFromFile("Przeszkody/KSuperHuge.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Sprite pulapka;
    pulapka.setTexture(we);
    pulapka.setPosition(0, 0);
    sf::Texture p;
    if (!p.loadFromFile("Przeszkody/Wrak.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(p, true));
    sf::Texture q;
    if (!q.loadFromFile("Przeszkody/KHuge.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(q, 0, 0));
    sf::Texture w;
    if (!w.loadFromFile("Przeszkody/KSmall.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(w, 0, 0));
    sf::Texture e;
    if (!e.loadFromFile("Przeszkody/P7x13.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(e, 0, 30));
    sf::Texture r;
    if (!r.loadFromFile("Przeszkody/P7x14.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(r, 0, 85));
    sf::Texture t;
    if (!t.loadFromFile("Przeszkody/P11x12.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(t, 75, 0));
    sf::Texture y;
    if (!y.loadFromFile("Przeszkody/P12x7.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(y, 100, 0));
    sf::Texture u;
    if (!u.loadFromFile("Przeszkody/P14x5.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(u, 85, 0));
    sf::Texture i;
    if (!i.loadFromFile("Przeszkody/P24x7.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(i, 100, 0));
    sf::Texture o;
    if (!o.loadFromFile("Przeszkody/P29x7.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(o, 0, 50));
    sf::Texture b;
    if (!b.loadFromFile("Przeszkody/P31x9.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(b, 0, 150));
    sf::Texture n;
    if (!n.loadFromFile("Przeszkody/P43x9.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    Baza.emplace_back(Obiekty(n, 60, 0));
    sf::Texture startb;
    if (!startb.loadFromFile("Inne/StartDoc.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    sf::Texture finishb;
    if (!finishb.loadFromFile("Inne/FinishDoc.png"))
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
    sf::Texture serduszka_baza;
    if (!serduszka_baza.loadFromFile("Inne/full.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture upgrade_baza;
    if (!upgrade_baza.loadFromFile("Inne/Upgrade.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite upgrade;
    upgrade.setTexture(upgrade_baza);
    upgrade.setPosition(100, 33);
    upgrade.setScale(2, 2);

    background.setRepeated(true);
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(1, 1);
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1000, 600));

    sf::Sprite serduszka;
    serduszka.setTexture(serduszka_baza);
    serduszka.setPosition(100, 0);
    serduszka.setScale(2, 2);

    Player PlayerOne(statek);

    sf::Clock clock;

    sf::Sprite start;
    start.setTexture(startb);
    start.setPosition(0, 560);

    sf::Sprite finish;
    finish.setTexture(finishb);
    finish.setPosition(985, 0);
    New_Level(PlayerOne, Elementy, Baza);

    double level = 1;

    std::cout << "Loading complite" << std::endl;

    Menu(backgroundSprite);

    sf::RenderWindow program(sf::VideoMode(1000, 600), "Sea of Traders");

    sf::Clock* czas = new sf::Clock;

    while (program.isOpen())
    {
        program.clear();
        program.draw(backgroundSprite);
        sf::Time elapsed = clock.restart();
        sf::Event event;

        while (program.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                program.close();
        }

        for (auto& pi : Elementy)
        {
            pi.animate(elapsed, level, start, pulapka);
        }

        auto q = Elementy.begin();
        for (unsigned int i = 0; i < Elementy.size(); i++)
        {
            if (Elementy[i].getGlobalBounds().intersects(PlayerOne.getGlobalBounds()))
            {
                if (Elementy[i].cansearch())
                {
                    PlayerOne.addMoney(50);
                    Elementy.erase(q + i);
                }
                else
                {
                    PlayerOne.AddHit();
                    PlayerOne.loseLives();
                    PlayerOne.resetPosition();
                    wait();
                }

            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            if (PlayerOne.retrunMoney() >= 1000)
            {
                PlayerOne.LoseMoney(1000);
                PlayerOne.upgrade(statek1);
            }
            else
            {

            }
        }

        if ((PlayerOne.retrunMoney() >= 1000) && (PlayerOne.returnUpgrade() == false))
        {
            program.draw(upgrade);
        }
        if (PlayerOne.getGlobalBounds().intersects(pulapka.getGlobalBounds()))
        {
            PlayerOne.resetPosition();
        }

        if (PlayerOne.returnLives() == 0)
        {
            std::cout << "Przegrales, dziekuje za gre" << std::endl;
            program.close();
            PlayerOne.ShowStatistic(level);
            int wynik = PlayerOne.retrunMoney() + level * 50 - PlayerOne.returnHit() * 100 + 10 * (czas->getElapsedTime().asSeconds());
            std::cout << "Twoj wynik: " << wynik << std::endl;
            EndGame(wynik);
            return 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            Elementy.clear();
            New_Level(PlayerOne, Elementy, Baza);
            wait();
        }

        PlayerOne.hearts(serduszka);

        for (auto& pi : Elementy)
        {
            program.draw(pi);
        }

        program.draw(start);
        program.draw(finish);
        program.draw(pulapka);
        program.draw(serduszka);
        program.draw(PlayerOne);

        PlayerOne.Animate(elapsed);

        if (finish.getGlobalBounds().intersects(PlayerOne.getGlobalBounds()))
        {
            level++;
            Elementy.clear();
            PlayerOne.addMoney(100);
            New_Level(PlayerOne, Elementy, Baza);
            wait();
        }
        program.display();
    }

}
