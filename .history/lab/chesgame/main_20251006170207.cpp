#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <optional>
#include <iostream>

int main() {
    sf::Window window(sf::VideoMode(800, 600), "SFML 3 Test");

    while (window.isOpen()) {
        std::optional<sf::Event> event = window.pollEvent();

        if (event.has_value()) {
            if (event->is<sf::Event::Closed>()) {
                std::cout << "Window closed event detected.\n";
                window.close();
            }

            if (event->is<sf::Event::MouseButtonPressed>()) {
                const auto& mouse = event->get<sf::Event::MouseButtonEvent>();
                std::cout << "Mouse clicked at (" << mouse.x << ", " << mouse.y << ")\n";
            }
        }
    }

    return 0;
}
