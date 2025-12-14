#include <SFML/Graphics.hpp>

int main() {
    // Khởi tạo VideoMode với kích thước cửa sổ
    sf::VideoMode mode({800u, 600u});  

    // Tạo cửa sổ với tiêu đề
    sf::RenderWindow window(mode, "Cờ vua SFML");

    // Vòng lặp chính
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}
