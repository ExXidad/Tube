//
// Created by mi on 18.08.2020.
//

#ifndef TUBE_TUBE_H
#define TUBE_TUBE_H

#include <iostream>
#include <Eigen/Geometry>
#include <vector>
#include <cmath>

#include "Graphics.h"
#include "Node.h"
#include "Line.h"

typedef Eigen::Hyperplane<double, 2> Line2;
typedef Eigen::Vector2d Vec2;

class Graphics;
class Node;
class Line;

class Tube {
private:
    std::vector<Line> lines;
    std::vector<Node> nodes;

    double pi = atan(1) * 4;

protected:

public:
    Tube(const int &n);

    void drawTube(Graphics *graphics);
};


#endif //TUBE_TUBE_H
