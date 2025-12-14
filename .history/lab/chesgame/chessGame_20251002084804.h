#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"

class chessGame: public sf::Drawable
{
private:
    Board board;
    std::array<Piece,16> pieces;
public:
    virtual ~chessGame() noexcept override = default;
};

#endif //CHESSGAME_H