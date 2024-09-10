#include <iostream>
#include <vector>
#include <array>
#include <map>

#include "graphing.h"
#include "screen.h"

int main() {
    int height = 10;
    int width = 10;

    // Defining objects
    Graphing graphing(height, width);
    Screen screen(height, width, 1, 10);

    Coord a;
    Coord b;

    a.y = 2;
    a.x = 2;
    a.z = 2;

    b.y = 8;
    b.x = 8;
    b.z = 2;

    std::vector<char> chars = {'.', ',', '-', '+', '#'};

    std::vector<Coord> coords = graphing.line(a, b, .2);

    for (Coord coord : coords) {
        std::cout << "y: " << coord.y << "x: " << coord.x << std::endl;
    }

    screen.fill(' ');
    screen.write(coords, chars);
    screen.print();
    
}