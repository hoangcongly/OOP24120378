#include "chessGame.h"

chessGame::chessGame(sf::Color bordCol1= sf::Color::White, sf::Color bordCol2= sf::Color::Black)
: board(bordCol1,bordCol2)
{
    font.loadFromFile("Textures/arial.ttf");

}