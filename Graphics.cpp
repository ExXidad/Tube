//
// Created by mi on 25.06.2020.
//

#include "Graphics.h"

Graphics::Graphics()
{
    double windowWidth = 800;
    double windowHeight = 800;

    sf::ContextSettings settings;
    settings.majorVersion = 3.1;
    settings.antialiasingLevel = 8;

    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "QuadTree",
                                  sf::Style::Default, settings);

    window->clear(sf::Color::Black);

    sf::View view(Vector2f(0, 0), Vector2f(windowWidth, windowHeight));
    window->setView(view);
}


Graphics::~Graphics()
{
    delete window;
}

void Graphics::keepWindowOpened()
{
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event))
            if (event.type == sf::Event::Closed) {
                window->close();
                break;
            }
    }
}

void Graphics::addPoint(const Vec2 &point, const sf::Color &color,
                        const bool &filled, const int &dotRadius)
{
    sf::CircleShape pointShape;

    pointShape.setPosition( Vector2f(point[0], -point[1]) - Vector2f(dotRadius, dotRadius));
    pointShape.setFillColor(color);

    if (filled) pointShape.setFillColor(color); else pointShape.setFillColor(sf::Color::Transparent);

    pointShape.setOutlineColor(color);
    pointShape.setOutlineThickness(1);
    pointShape.setRadius(dotRadius);

    window->draw(pointShape);
}

void Graphics::addPoints(const std::vector<Vec2> &points, const sf::Color &color,
                         const bool &filled, const int &dotRadius)
{
    for (auto &point : points) {
        addPoint(point, color, filled, dotRadius);
    }
}

void Graphics::display()
{
    window->display();
}

void Graphics::addPoly(const std::vector<Vec2> &points, const sf::Color &color)
{
    sf::VertexArray lines(sf::LinesStrip, points.size());

    for (int i = 0; i < points.size(); ++i) {
        lines[i].position = Vector2f(points[i][0], -points[i][1]);
        lines[i].color = color;
    }

    window->draw(lines);
}

void Graphics::addPoly(const std::vector<Node> &nodes, const sf::Color &color)
{
    sf::VertexArray lines(sf::LinesStrip, nodes.size());

    for (int i = 0; i < nodes.size(); ++i) {
        lines[i].position = Vector2f(nodes[i].point[0], -nodes[i].point[1]);
        lines[i].color = color;
    }

    window->draw(lines);
}

void Graphics::addNode(const Node &node)
{
    addPoint(node.point);
}

void Graphics::addNodes(const std::vector<Node> &nodes)
{
    for (const auto &node : nodes) {
        addNode(node);
    }
}
