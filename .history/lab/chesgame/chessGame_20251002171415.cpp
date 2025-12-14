#include "chessGame.h"

chessGame::chessGame(sf::Color bordCol1, sf::Color bordCol2)
: board(bordCol1, bordCol2), selected(false), playerTurn(true), mate(false), turn(1)
{
    // Load font
    if (!font.openFromFile("Textures/arial.ttf")) {
        std::cerr << "Không load được font!" << std::endl;
    }

    // Khởi tạo text bằng unique_ptr
    textRestart = std::make_unique<sf::Text>("Restart", font, 20);
    textRestart->setFillColor(sf::Color::Red);

    textTurn = std::make_unique<sf::Text>("Turn", font, 20);
    textTurn->setFillColor(sf::Color::White);

    textSituation = std::make_unique<sf::Text>("Situation", font, 20);
    textSituation->setFillColor(sf::Color::White);

    textLastMove = std::make_unique<sf::Text>("Last Move", font, 20);
    textLastMove->setFillColor(sf::Color::White);
}
