//
// Created by xidad on 18.08.2020.
//

#ifndef TUBE_NODE_H
#define TUBE_NODE_H

#include "Tube.h"
#include "Line.h"

typedef Eigen::Hyperplane<double, 2> Line2;
typedef Eigen::Vector2d Vec2;

class Line;

class Node
{
public:
    Vec2 point, velocity, acceleration;

    Line *prevLine = nullptr, *nextLine = nullptr;
    Node *prevNode = nullptr, *nextNode = nullptr;

    double nextAngle;
    double nextLength;

};


#endif //TUBE_NODE_H
