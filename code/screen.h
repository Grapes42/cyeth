#include <iostream>
#include <vector>
#include <map>

class Screen {
    public:
        Screen(int h, int w, int m);
        void fill(char c);
        void print();
        void write(std::vector<Coord> coords, std::vector<char> chars);
    private:
        std::vector<std::vector<char>> arr;
        int height;
        int width;
        int max_depth;
};

Screen::Screen(int h, int w, int m) {
    height = h;
    width = w;
    max_depth = m;
    arr.resize(height, std::vector<char>(width, ' '));
}

void Screen::fill(char c) {
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            arr[y][x] = c;
        }
    }
}

void Screen::print() {
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            std::cout << arr[y][x];
        }
        std::cout << std::endl;
    }
}

void Screen::write(std::vector<Coord> coords, std::vector<char> chars) {

    for (Coord coord : coords) {
        arr[coord.y][coord.x] = chars[0];
    }
}