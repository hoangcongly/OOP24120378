#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"

class chessGame: public sf::Drawable
{
private:
    Board board;
    std::array<Piece,16> whitePieces;
    std::array<Piece,16> blackPieces;
    Piece* selectedPieces;
    std::vector<sf::RectangleShape> possibleMovesSquares;
    std::string lastMove;
    sf::RectangleShape infoRestart;
    sf::Font font;

    // Chuyển sf::Text thành con trỏ
    std::unique_ptr<sf::Text> textRestart;
    std::unique_ptr<sf::Text> textTurn;
    std::unique_ptr<sf::Text> textSituation;
    std::unique_ptr<sf::Text> textLastMove;

    bool selected;
    bool playerTurn;
    bool playerTurnCheck;
    bool mate;
    int turn;

    void createMoveSquares();
    void calcPossibleMoves();
    void calcKingMoves(Piece* tmpPiece);
    void calcQueenMoves(Piece* tmpPiece);
    void calcRookMoves(Piece* tmpPiece);
    void calcBishopMoves(Piece* tmpPiece);
    void calcKnightMoves(Piece* tmpPiece);
    void calcPawnMoves(Piece* tmpPiece);
    void calcCastling(Piece* tmpPiece);
    void eraseMoves(Piece* tmpPiece);
    void checkMate();
    void updateInfo();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    chessGame(sf::Color bordCol1 = sf::Color::White, sf::Color bordCol2 = sf::Color::Black);
    bool getSelected() { return selected; }
    bool getMate() { return mate; }
    bool selectPiece(int pos);
    void moveSelected(int pos);
    void restart();

    virtual ~chessGame() noexcept override = default;
};

#endif // CHESSGAME_H
