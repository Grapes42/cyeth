#include <iostream>
#include <array>
#include <vector>
#include <cmath>

#include "data_types.h"
#include "projection.h"
#include "object_3d.h"
#include "graphing.h"
#include "screen.h"
#include "shapes.h"

int main() {
    int height = 20;
    int width = 20;

    double min = .1;
    double max = 10;

    std::vector<Coord> coords;

    // Defining objects
    Graphing graphing;
    Screen screen(height, width, min, max);

    Coord center = {5, 5, 5, 1};
    coords = cube(center, 5, 5, 5);

    screen.write(coords, '3');

    screen.print();

}