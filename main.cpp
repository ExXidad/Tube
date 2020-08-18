#include "Tube.h"
#include "Graphics.h"

int main()
{
    Graphics graphics;

    Tube tube(20);

    tube.drawTube(&graphics);

    graphics.display();
    graphics.keepWindowOpened();
    return 0;
}