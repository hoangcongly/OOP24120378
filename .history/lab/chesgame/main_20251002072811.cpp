#include <SFML/Graphics.hpp>

int main() {
    // Tạo cửa sổ 800x600 với tên "Cờ vua SFML"
    sf::RenderWindow window({800, 600}, "Cờ vua SFML");

    // Vòng lặp chính
    while (window.isOpen()) {
        // Lấy sự kiện
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Xóa màn hình với màu đen
        window.clear(sf::Color::Black);

        // Vẽ xong -> hiển thị
        window.display();
    }

    return 0;
}
