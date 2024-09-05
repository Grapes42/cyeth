#include <iostream>
#include <array>
#include "graphing.h"
using namespace std;

int main() {
    Graphing graphing(10, 10);

    Coord a;
    Coord b;

    array< Coord, 2 > arr = graphing.line(a, b);

    cout << arr[0].x << endl;
}