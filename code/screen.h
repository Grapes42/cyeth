#include <iostream>

class Screen {
    public:
        Screen(int height, int width);
        void clear();
        void print();
    private:
        char** arr;
        int height;
        int width;
};

Screen::Screen(int height, int width) {
    this->height = height;
    this->width = width;

    arr = new char*[height];
    for (int i=0; i<height; i++) {
        arr[i] = new char[width];
    }
}

void Screen::clear() {
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            arr[y][x] = '.';
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