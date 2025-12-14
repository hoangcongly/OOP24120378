#include <SFML/Graphics.hpp>
#include "chessGame.h"

int main() {
    chessGame chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));

    sf::RenderWindow window(sf::VideoMode({768, 512}), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        std::optional<sf::Event> optEvent = window.pollEvent();
        while (optEvent.has_value()) {
            sf::Event event = optEvent.value();

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                auto mouseEvent = event.mouseButton;
                if (mouseEvent.button == sf::Mouse::Button::Left) {
                    if ((0 <= mouseEvent.x) && (mouseEvent.x <= 512) && (0 <= mouseEvent.y) && (mouseEvent.y <= 512)) {
                        unsigned int buttonPos = (mouseEvent.x / 64) + ((mouseEvent.y / 64) * 8);
                        if (!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    } else if ((517 <= mouseEvent.x) && (mouseEvent.x <= 763) && (5 <= mouseEvent.y) && (mouseEvent.y <= 45)) {
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
