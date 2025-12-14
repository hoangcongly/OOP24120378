#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"

int main() {
    std::cout << "Chess game started\n";
    chessGame chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));

    sf::RenderWindow window(sf::VideoMode({768, 512}), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {

        for (auto event = window.pollEvent(); event.has_value(); event = window.pollEvent()) {
            const auto& e = event.value();

            if (e.is<sf::Event::Closed>())
                window.close();

            if (const auto* mouse = e.getIf<sf::Event::MouseButtonPressed>()) {
                if (mouse->button == sf::Mouse::Button::Left) {
                    int x = mouse->position.x;
                    int y = mouse->position.y;

                    if ((0 <= x) && (x <= 512) && (0 <= y) && (y <= 512)) {
                        unsigned int buttonPos = (x / 64) + ((y / 64) * (8 * (512 / window.getSize().y)));

                        if (!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    }
                    else if ((517 <= x) && (x <= 763) && (5 <= y) && (y <= 45)) {
                        chess.restart();
                    }
                }
            }
        }

        window.draw(chess);
        window.display();
    }
}
