#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

class Board: public sf::Drawable
{
private:
    std:: array<sf::RectangleShape,64> m_boardSquares;
    virtual void draw(sf::RenderTarget&target, sf::RenderStates states) const;
public:
    Board(sf:: Color col1=sf::Color::White, sf:: Color col2=sf::Color::Black);
    void load(sf::Color col1 = sf::Color::White, sf::Color col2 = sf::Color::Black);
};

#endif// BOARD_H