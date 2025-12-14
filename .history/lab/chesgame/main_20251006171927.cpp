#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"

int main() {
    chessGame chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));

    // ✅ SFML 3.0.0: VideoMode cần sf::Vector2u
    sf::RenderWindow window(sf::VideoMode({768, 512}), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {

        for (sf::Event event; window.pollEvent(event);) {

            if (event.is<sf::Event::Closed>())  // ✅ Cách mới trong SFML 3
                window.close();

            // ✅ Kiểm tra chuột nhấn theo kiểu mới
            if (event.is<sf::Event::MouseButtonPressed>()) {
                const auto& mouse = event.get<sf::Event::MouseButtonPressed>();

                if (mouse.button == sf::Mouse::Left) {

                    // Lấy vị trí chuột từ MouseButtonPressed
                    int x = mouse.position.x;
                    int y = mouse.position.y;

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
