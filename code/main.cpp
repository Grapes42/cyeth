#include <iostream>
#include <array>
#include <vector>
#include <cmath>

#include "data_types.h"
#include "object_3d.h"
#include "graphing.h"
#include "screen.h"

int main() {
    int height = 20;
    int width = 20;

    double min = .1;
    double max = 10;

    std::vector<Coord> coords;

    // Defining objects
    Graphing graphing;
    Screen screen(height, width, min, max);

    screen.print();

    Coord a = {0, 0, 0, 1};
    Coord b = {10, 10, 0, 1};

    coords = graphing.line(a, b, .2);

    screen.write(coords, '3');

    screen.print();

}