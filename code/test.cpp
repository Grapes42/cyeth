#include <iostream>

struct Coord {
    double points[4] = {0, 0, 0, 0};
    double &y = points[0];
    double &x = points[1];
    double &z = points[2];
    double &w = points[3];
};

int main() {
    Coord coord;

    for (int i=0; i<4; ++i) {
        coord.points[i]++;
    };

    coord.z++;

    for (int i=0; i<4; ++i) {
        std::cout << coord.points[i];
    }

    std::cout << std::endl << coord.y << coord.x << coord.z << coord.w;
}