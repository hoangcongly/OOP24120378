#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    // VideoMode giờ nhận Vector2u
    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "SFML 3 Window");

    while (window.isOpen()) {
        // pollEvent trả về std::optional<sf::Event>
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
