#include <SFML/Graphics.hpp>
#include "chessGame.h"

int main() {
    chessGame chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));

    sf::RenderWindow window(sf::VideoMode({768, 512}), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        std::optional<sf::Event> optEvent = window.pollEvent();
        while (optEvent.has_value()) {
            const sf::Event& event = optEvent.value();

            if (event.is<sf::Event::Closed>()) {
                window.close();
            }

            if (event.is<sf::Event::MouseButtonPressed>()) {
                const auto& mouse = event.mouseButton; // ✅
                if (mouse.button == sf::Mouse::Button::Left) {
                    if ((0 <= mouse.x) && (mouse.x <= 512) && (0 <= mouse.y) && (mouse.y <= 512)) {
                        unsigned int buttonPos = (mouse.x / 64) + ((mouse.y / 64) * 8);
                        if (!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    } else if ((517 <= mouse.x) && (mouse.x <= 763) && (5 <= mouse.y) && (mouse.y <= 45)) {
                        chess.restart();
                    }
                }
            }

            optEvent = window.pollEvent(); // tiếp tục lấy sự kiện tiếp theo
        }

        window.draw(chess);
        window.display();
    }

    return 0;
}
