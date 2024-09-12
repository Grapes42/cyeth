#include <iostream>
#include <vector>
#include <array>
#include <cmath>

#include "data_types.h"
#include "graphing.h"
#include "screen.h"
#include "object_3d.h"
#include "shapes.h"
#include "projection.h"


int main() {
    int height = 20;
    int width = 20;

    // Defining objects
    Graphing graphing(height, width);
    Screen screen(height, width, 1, 10);
    Projection projection;
    projection.perspective_projection_matrix(90, 1, 1, 20);

    std::vector<char> chars = {'.', ',', '-', '+', '#'};

    Coord center;
    std::vector<Coord> coords = cube(center, 1, 1, 1);

    std::cout << "cube at creation: " << std::endl;
    for (Coord coord : coords) {
        std::cout << "y: " << coord.y 
                  << ", x: " << coord.x
                  << ", z: " << coord.z
                  << ", w: " << coord.w
                  << std::endl;
    }
    std::cout << "\n\n\n";

    coords = projection.project(coords);

    for (Coord coord : coords) {
        for (int i=0; i<4; ++i) {
            coord.points[i] = round(coord.points[i]);
        }
    }

    for (Coord coord : coords) {
        std::cout << "y: " << coord.y << "x: " << coord.x << std::endl;
    }

    screen.fill(' ');
    screen.write(coords, chars);
    screen.print();
    
}