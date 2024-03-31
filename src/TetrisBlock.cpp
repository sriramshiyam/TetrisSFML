#include "TetrisBlock.h"
#include <math.h>

TetrisBlock::TetrisBlock(char color)
{
    blockWidth = TetrisConstants::TETRIS_BLOCK_DIMENSION - 0.5f;
    blockHeight = TetrisConstants::TETRIS_BLOCK_DIMENSION - 0.5f;

    x1 = 20 * blockWidth / 100;
    x2 = 80 * blockWidth / 100;
    y1 = 20 * blockHeight / 100;
    y2 = 80 * blockHeight / 100;

    line1Length = sqrt(pow(x1, 2) + pow(y1, 2));
    line2Length = x2 - x1;

    create(blockWidth, blockHeight);
    drawTetrisBlock(color);
}

void TetrisBlock::drawTetrisBlock(char color)
{
    sf::RectangleShape box(sf::Vector2f(blockWidth, blockHeight));

    switch (color)
    {
    case Colors::BLUE:
        box.setFillColor(TetrisConstants::BLUE_COLOR);
        break;
    case Colors::LIGHTBLUE:
        box.setFillColor(TetrisConstants::LIGHTBLUE_COLOR);
        break;
    case Colors::RED:
        box.setFillColor(TetrisConstants::RED_COLOR);
        break;
    case Colors::YELLOW:
        box.setFillColor(TetrisConstants::YELLOW_COLOR);
        break;
    case Colors::GREEN:
        box.setFillColor(TetrisConstants::GREEN_COLOR);
        break;
    case Colors::PURPLE:
        box.setFillColor(TetrisConstants::PURPLE_COLOR);
        break;
    case Colors::ORANGE:
        box.setFillColor(TetrisConstants::ORANGE_COLOR);
        break;
    default:
        break;
    }

    sf::ConvexShape shape1;
    shape1.setPointCount(4);
    shape1.setFillColor(sf::Color(0, 0, 0, 45));

    shape1.setPoint(0, sf::Vector2f(0.0f, 0.0f));
    shape1.setPoint(1, sf::Vector2f(blockWidth, 0.0f));
    shape1.setPoint(2, sf::Vector2f(x2, y1));
    shape1.setPoint(3, sf::Vector2f(x1, y1));

    sf::ConvexShape shape2;
    shape2.setPointCount(4);
    shape2.setFillColor(sf::Color(0, 0, 0, 120));

    shape2.setPoint(0, sf::Vector2f(0.0f, 0.0f));
    shape2.setPoint(1, sf::Vector2f(x1, y1));
    shape2.setPoint(2, sf::Vector2f(x1, y2));
    shape2.setPoint(3, sf::Vector2f(0.0f, blockHeight));

    sf::ConvexShape shape3;
    shape3.setPointCount(4);
    shape3.setFillColor(sf::Color(0, 0, 0, 120));

    shape3.setPoint(0, sf::Vector2f(0.0f, blockHeight));
    shape3.setPoint(1, sf::Vector2f(blockWidth, blockHeight));
    shape3.setPoint(2, sf::Vector2f(x2, y2));
    shape3.setPoint(3, sf::Vector2f(x1, y2));

    sf::ConvexShape shape4;
    shape4.setPointCount(4);
    shape4.setFillColor(sf::Color(0, 0, 0, 45));

    shape4.setPoint(0, sf::Vector2f(blockWidth, 0.0f));
    shape4.setPoint(1, sf::Vector2f(blockWidth, blockHeight));
    shape4.setPoint(2, sf::Vector2f(x2, y2));
    shape4.setPoint(3, sf::Vector2f(x2, y1));

    sf::Vector2f l1Length(line1Length, 1.5f);
    sf::Vector2f l2Length(line2Length, 1.0f);

    sf::RectangleShape line1(l1Length);
    line1.setFillColor(sf::Color::Black);
    line1.setRotation(45.0f);

    sf::RectangleShape line2(l1Length);
    line2.setFillColor(sf::Color::Black);
    line2.setPosition(sf::Vector2f(0.0f, blockHeight));
    line2.setRotation(-45.0f);

    sf::RectangleShape line3(l1Length);
    line3.setFillColor(sf::Color::Black);
    line3.setPosition(sf::Vector2f(x2, y2));
    line3.setRotation(45.0f);

    sf::RectangleShape line4(l1Length);
    line4.setFillColor(sf::Color::Black);
    line4.setPosition(sf::Vector2f(x2, y1));
    line4.setRotation(-45.0f);

    sf::RectangleShape line5(l2Length);
    line5.setFillColor(sf::Color::Black);
    line5.setPosition(sf::Vector2f(x1, y1));

    sf::RectangleShape line6(l2Length);
    line6.setFillColor(sf::Color::Black);
    line6.setPosition(sf::Vector2f(x1, y1));
    line6.setRotation(90);

    sf::RectangleShape line7(l2Length);
    line7.setFillColor(sf::Color::Black);
    line7.setPosition(sf::Vector2f(x2, y1));
    line7.setRotation(90);

    sf::RectangleShape line8(l2Length);
    line8.setFillColor(sf::Color::Black);
    line8.setPosition(sf::Vector2f(x1, y2));

    draw(box);
    draw(shape1);
    draw(shape2);
    draw(shape3);
    draw(shape4);
    draw(line1);
    draw(line2);
    draw(line3);
    draw(line4);

    draw(line5);
    draw(line6);
    draw(line7);
    draw(line8);
}
