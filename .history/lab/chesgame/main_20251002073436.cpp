#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cờ vua SFML");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Xóa màn hình bằng màu xanh dương
        window.clear(sf::Color::Blue);

        // Vẽ 1 hình tròn đỏ
        sf::CircleShape circle(100);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(200, 200);
        window.draw(circle);

        // Hiển thị lên cửa sổ
        window.display();
    }

    return 0;
}
