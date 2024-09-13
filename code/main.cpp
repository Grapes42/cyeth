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
    int height = 100;
    int width = 100;

    double min = .1;
    double max = 100;

    std::vector<Coord> coords;
    std::vector<Coord> coords_projected;

    // Defining objects
    Graphing graphing;
    Screen screen(height, width, min, max);

    Projection projection;
    projection.use_perspective_matrix(45, 1, min, max);

    std::cout << "matrix" << std::endl;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            std::cout << projection.matrix[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    Object3D cube;

    cube.center = {0, 0, 5, 1};
    cube.coords = define_cube(cube.center, 10, 10, 10);

    std::cout << "pre projection:" << std::endl;
    for (Coord coord : cube.coords) {
        std::cout << "y: " << coord.points[y]
                  << ", x: " << coord.points[x]
                  << ", z: " << coord.points[z]
                  << ", w: " << coord.points[w]
                  << std::endl;
    }
    screen.write(cube.coords, '3');
    screen.print();

    std::cout << "post projection:" << std::endl;
    coords_projected = projection.project(cube.coords);
    for (Coord coord : coords_projected) {
        std::cout << "y: " << coord.points[y]
                  << ", x: " << coord.points[x]
                  << ", z: " << coord.points[z]
                  << ", w: " << coord.points[w]
                  << std::endl;
    }
    screen.fill(' ');
    screen.write(coords_projected, ':');
    screen.print();



    return 0;
}