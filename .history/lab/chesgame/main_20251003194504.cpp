#include "chessGame.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Test");
    ChessGame game(&window);
    game.run();
    return 0;
}
