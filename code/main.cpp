#include <iostream>
#include <array>
#include "graphing.h"
using namespace std;

int main() {
    Graphing graphing(10, 10);

    array< Coord, 2 > arr = graphing.line();

    cout << arr[0].x << endl;
}