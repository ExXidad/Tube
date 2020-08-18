//
// Created by mi on 18.08.2020.
//

#include "Tube.h"

Tube::Tube(const int &n)
{
    nodes.resize(n);
    lines.resize(n - 1);

    double degStep = 40 * pi / 180;
    double lenStep = 10 * degStep;

    nodes[0].point = Vec2(0, 0);
    nodes[0].nextAngle = degStep;
    nodes[0].nextLength = 20;

    for (int i = 1; i < n; ++i) {
        nodes[i].point = nodes[i - 1].point + nodes[i - 1].nextLength *
                                              Vec2(cos(nodes[i - 1].nextAngle), sin(nodes[i - 1].nextAngle));

        nodes[i].nextAngle = nodes[i - 1].nextAngle + degStep;
        nodes[i].nextLength = nodes[i - 1].nextLength + lenStep;

        lines[i - 1].line = Line2::Through(nodes[i - 1].point, nodes[i].point);
        lines[i - 1].n1 = &nodes[i - 1];
        lines[i - 1].n2 = &nodes[i];

        nodes[i].prevLine = &lines[i - 1];
        nodes[i - 1].nextLine = &lines[i - 1];
    }
}

void Tube::drawTube(Graphics *graphics)
{
    graphics->addNodes(nodes);
    graphics->addPoly(nodes);
}
