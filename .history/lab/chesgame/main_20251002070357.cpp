#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window;
    sf::WindowSettings settings;
    settings.title = "Hello SFML";
    settings.size = sf::Vector2u(800, 600);
    window.create(settings);

    while (window.isOpen()) {
        auto eventOpt = window.pollEvent();
        if (eventOpt.has_value()) {
            const sf::Event& event = eventOpt.value();
            if (event.type() == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}
