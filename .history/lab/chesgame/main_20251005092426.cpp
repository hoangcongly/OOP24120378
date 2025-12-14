#include "chessGame.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "chess Test");
    chessGame game(&window);
    game.run();
    return 0;
}
