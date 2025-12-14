#include "chessGame.h"

chessGame::chessGame(sf::Color bordCol1, sf::Color bordCol2)
: board(bordCol1, bordCol2), selected(false), playerTurn(true), mate(false), turn(1)
{
    // Load font (SFML 3.x)
    if (!font.openFromFile("Textures/arial.ttf")) {
        std::cerr << "Không load được font!" << std::endl;
    }

    // Khởi tạo sf::Text sau khi font đã load
    textRestart.setFont(font);
    textRestart.setString("Restart");
    textRestart.setCharacterSize(20);
    textRestart.setFillColor(sf::Color::Red);

    textTurn.setFont(font);
    textTurn.setString("Turn");
    textTurn.setCharacterSize(20);
    textTurn.setFillColor(sf::Color::White);

    textSituation.setFont(font);
    textSituation.setString("Situation");
    textSituation.setCharacterSize(20);
    textSituation.setFillColor(sf::Color::White);

    textLastMove.setFont(font);
    textLastMove.setString("Last Move");
    textLastMove.setCharacterSize(20);
    textLastMove.setFillColor(sf::Color::White);
}
