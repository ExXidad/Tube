//
// Created by xidad on 18.08.2020.
//

#ifndef TUBE_LINE_H
#define TUBE_LINE_H

#include "Tube.h"

#include "Node.h"

typedef Eigen::Hyperplane<double, 2> Line2;
typedef Eigen::Vector2d Vec2;

class Node;

class Line
{
public:
    Node *n1, *n2;

    Line2 line;

    //double length() {return}
};


#endif //TUBE_LINE_H
