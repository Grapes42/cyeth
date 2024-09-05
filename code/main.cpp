#include <iostream>
#include <vector>
#include "graphing.h"
using namespace std;

int main() {
    Graphing graphing(10, 10);

    Coord a;
    Coord b;

    a.y = -1;
    a.x = -1;

    b.y = 1;
    a.x = 1;

    vector<Coord> line = graphing.line(a, b);

    /*
    cout << line[0].y << endl
         << line[0].x << endl
         << line[0].z << endl;
    */
}