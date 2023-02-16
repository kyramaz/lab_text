#include <shapes.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

int get_random_number(int min, int max)
{
    int num = min + rand() % (max - min + 1);
    return num;
}

int main()
{
    int con = 0;
    bool Flag = false;
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    string str1 = "Hello world!";
    string str2 = "";

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    sf::Font font;
    font.loadFromFile("Georgia.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setString(str2);
    text.setStyle(sf::Text::Bold);
    text.setPosition(360,280);
    text.setFillColor(sf::Color::Red);

    sf::Clock clock;
    sf::RectangleShape circle;
    circle.setFillColor(sf::Color::Red);
    circle.setSize(sf::Vector2f(50,50));

    while (window.isOpen())
    {
        int time = clock.getElapsedTime().asSeconds();
        cout << time << endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        if (str1[time] == *"\0")
        {
            return 0;
        }

        if (time == con && Flag == false)
        {
            str2 += str1[time];
            text.setString(str2);
            if (str1[time] == 32)
            {
                time += 1;
                
            }
            Flag = true;
        }
        
        if (time > con)
        {
            Flag = false;
            con = time;
        }
        
        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }

    return 0;
}