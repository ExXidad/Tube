//
// Created by mi on 25.06.2020.
//

#ifndef QTREE_GRAPHICS_H
#define QTREE_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Tube.h"
#include "Node.h"
#include "Line.h"

typedef sf::Vector2f Vector2f;
typedef Eigen::Hyperplane<double, 2> Line2;
typedef Eigen::Vector2d Vec2;

class Node;
class Line;

class Graphics {
private:
    sf::RenderWindow *window;

public:
    Graphics();

    ~Graphics();

    void addPoint(const Vec2 &point, const sf::Color &color = sf::Color::White, const bool &filled = false,
                  const int &dotRadius = 2);

    void addPoints(const std::vector<Vec2> &points, const sf::Color &color = sf::Color::White,
                   const bool &filled = false, const int &dotRadius = 2);

    void addPoly(const std::vector<Vec2> &points, const sf::Color &color = sf::Color::White);
    void addPoly(const std::vector<Node> &nodes, const sf::Color &color = sf::Color::White);

    void addNode(const Node &node);

    void addNodes(const std::vector<Node> &nodes);

    void display();

    void keepWindowOpened();
};


#endif //QTREE_GRAPHICS_H
