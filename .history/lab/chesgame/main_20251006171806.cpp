#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"

int main() {
    chessGame chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));

    sf::RenderWindow window({768, 512}, "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        sf::Event event; // vẫn còn, nhưng enum bên trong đã đổi

        while (window.pollEvent(event)) {
            if (event.is<sf::Event::Closed>())
                window.close();

            if (event.is<sf::Event::MouseButtonPressed>()) {
                auto mouse = event.get<sf::Event::MouseButtonPressed>();

                if (mouse.button == sf::Mouse::Button::Left) {
                    if ((0 <= mouse.x) && (mouse.x <= 512) &&
                        (0 <= mouse.y) && (mouse.y <= 512)) {

                        unsigned int buttonPos =
                            (mouse.x / 64) + ((mouse.y / 64) * (8 * (512 / window.getSize().y)));

                        if (!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    } 
                    else if ((517 <= mouse.x) && (mouse.x <= 763) &&
                             (5 <= mouse.y) && (mouse.y <= 45)) {
                        chess.restart();
                    }
                }
            }
        }

        window.clear();
        window.draw(chess);
        window.display();
    }
}
