#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "pieceTextures.h"
#include <memory>

class Piece : public sf::Drawable
{
private:
    std::unique_ptr<sf::Sprite> m_sprite;
    sf::Texture m_texture;
    std::vector<int> possibleMoves;
    std::vector<int> dangerMoves;

    char m_type;
    bool m_player;
    int m_position;
    int enPassant;
    bool m_moved;

    void setTexture();  // gán texture cho m_sprite
    void move();        // cập nhật vị trí sprite

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        if(m_sprite) target.draw(*m_sprite, states);
    }

public:
    Piece(char type='P', bool player=true, int pos=-1, bool moved=false)
: m_type(type), m_player(player), m_position(pos), m_moved(moved), enPassant(-1)
{
    m_sprite = std::make_unique<sf::Sprite>();
    setTexture(); // gán texture sau khi tạo sprite
}

    void setPiece(char type, bool player, int pos, bool moved=false)
    {
        m_type = type;
        m_player = player;
        m_position = pos;
        m_moved = moved;
        setTexture();
        move();
    }

    void setType(char ch)
    {
        m_type = ch;
        setTexture();
    }

    char getType() const { return m_type; }

    void setPlayer(bool bl)
    {
        m_player = bl;
        setTexture();
    }

    bool getPlayer() const { return m_player; }

    void setPosition(int pos)
    {
        m_position = pos;
        move();
    }

    int getPosition() const { return m_position; }

    void setMoved(bool moved) { m_moved = moved; }
    bool getMoved() const { return m_moved; }

    void setEnPassant(int x) { enPassant = x; }
    int getEnPassant() const { return enPassant; }

    std::vector<int>& getPossibleMoves() { return possibleMoves; }
    std::vector<int>& getDangerMoves() { return dangerMoves; }

    std::string toString() const;
};

#endif // PIECE_H
