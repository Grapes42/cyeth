#include <iostream>
#include <vector>
#include "graphing.h"
#include "screen.h"

void print_arr(char arr[5][5], int height, int width);

int main() {
    int height = 10;
    int width = 10;

    Graphing graphing(height, width);
    Screen screen(height, width);

    //screen.clear();
    screen.print();


    /*
    Coord a;
    Coord b;

    a.y = -1;
    a.x = -1;

    b.y = 1;
    b.x = 1;

    vector<Coord> line = graphing.line(a, b);
    */


    /*
    cout << line[0].y << endl
         << line[0].x << endl
         << line[0].z << endl;
    */
}


void print_arr(char arr[5][5], int height, int width) {
    for (int y=height-1; y >= 0; y--) {
        for (int x=width-1; x >= 0; x--) {
            std::cout << arr[y][x];
        }
        std::cout << endl;
    }
}