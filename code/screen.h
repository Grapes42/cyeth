#include <iostream>
#include <vector>

class Screen {
    public:
        Screen(int height, int width);
        void clear();
        void print() const;
    private:
        std::vector<std::vector<char>> arr;
        int height;
        int width;
};

Screen::Screen(int height, int width) {
    arr.resize(height, std::vector<char>(width, '.'));
}

void Screen::clear() {
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            arr[y][x] = '.';
        }
    }
}

void Screen::print() const {
        for (const auto& row : arr) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }