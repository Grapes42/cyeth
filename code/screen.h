#include <iostream>
#include <vector>
#include <map>
#include <cmath>

class Screen {
    public:
        Screen(int h, int w, int min, int max);
        void fill(char c);
        void print();
        void write(std::vector<Coord> coords, std::vector<char> chars);
    private:
        std::vector<std::vector<char>> arr;
        int height;
        int width;
        int min_depth;
        int max_depth;
};

Screen::Screen(int h, int w, int min, int max) {
    height = h;
    width = w;
    min_depth = min;
    max_depth = max;

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
    double depth_range = max_depth - min_depth;
    double char_range = chars.size();
    
    double magic_num = char_range / depth_range;
    std::cout << "magic num: " << magic_num << std::endl;

    for (Coord coord : coords) {
        int z = round(magic_num * coord.z - min_depth);
        std::cout << "z" << z << std::endl;
        arr[coord.y][coord.x] = chars[z];

        if (z == -1) {
            arr[coord.y][coord.x] = 'z';
        }
    }
}