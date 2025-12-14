#include <SFML/Graphics.hpp>

int main()
{
    const int size = 80; // kích thước mỗi ô cờ
    const int boardSize = 8;

    sf::RenderWindow window(sf::VideoMode({size * boardSize, size * boardSize}), "Chess Board SFML");

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        // Vẽ bàn cờ 8x8
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                sf::RectangleShape square({(float)size, (float)size});
                square.setPosition({(float)(j * size), (float)(i * size)});

                // Màu đen – trắng xen kẽ
                if ((i + j) % 2 == 0)
                    square.setFillColor(sf::Color::White);
                else
                    square.setFillColor(sf::Color::Black);

                window.draw(square);
            }
        }

        window.display();
    }

    return 0;
}
