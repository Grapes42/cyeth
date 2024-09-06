#include <iostream>
#include <vector>
using namespace std;

struct Coord {
    int y = 0;
    int x = 0;
    int z = 0;
};

class Graphing {
    public:
        Graphing(int height, int width);
        vector<Coord> line(Coord a, Coord b);
};

Graphing::Graphing(int height, int width) {
    height = height;
    width = width;
}

vector<Coord> Graphing::line(Coord a, Coord b) {
    double rise = a.y - b.y;
    double run = a.x - b.x;

    if (run != 0) {
        double gradient = rise/run;

        cout << gradient << endl; 
    }



    vector<Coord> line = {a, b};
    return line;
}

