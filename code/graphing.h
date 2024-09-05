#include <iostream>
#include <array>
using namespace std;

struct Coord{
    int y = 0;
    int x = 0;
    int z = 0;
};

class Graphing {
    public:
        Graphing(int height, int width);
        array< Coord, 2 >& line(Coord a, Coord b);
};

Graphing::Graphing(int height, int width) {
    height = height;
    width = width;

    int screen_arr[height][width];
}

array< Coord, 2 >& Graphing::line(Coord a, Coord b) {

    array< Coord, 2 > arr = {a, b};

    array< Coord, 2 >& ref = arr;
    return ref;
}