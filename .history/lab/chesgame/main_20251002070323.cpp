#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window;
    window.create({800, 600}, "Hello SFML");

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
