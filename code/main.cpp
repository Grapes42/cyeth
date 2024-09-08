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
    Screen screen(height, width, 10);

    Coord a;
    Coord b;

    a.y = 2;
    a.x = 2;

    b.y = 1;
    b.x = 1;

    std::vector<char> chars = {'.', ',', '-', '+', '#'};

    std::vector<Coord> coords = {a, b};

    screen.fill(' ');
    screen.write(coords, chars);
    screen.print();
    
}