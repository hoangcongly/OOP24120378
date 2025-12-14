#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Chess Game SFML");

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({200.f, 200.f});

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
