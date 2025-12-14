#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>
#include "chessGame.h"

int main() {
    chessGame chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));

    sf::RenderWindow window(sf::VideoMode(768, 512), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        // pollEvent() bây giờ trả về std::optional<sf::Event>
        while (auto event = window.pollEvent()) {

            // Đóng cửa sổ
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Kiểm tra click chuột
            if (auto mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouse->button == sf::Mouse::Button::Left) {
                    if ((0 <= mouse->x) && (mouse->x <= 512) &&
                        (0 <= mouse->y) && (mouse->y <= 512)) {

                        unsigned int buttonPos =
                            (mouse->x / 64) + ((mouse->y / 64) * (8 * (512 / window.getSize().y)));

                        if (!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    }
                    else if ((517 <= mouse->x) && (mouse->x <= 763) &&
                             (5 <= mouse->y) && (mouse->y <= 45)) {
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
