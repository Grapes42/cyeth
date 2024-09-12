class Screen {
    public:
        Screen(int h, int w, double min, double max);
        void print();
        void fill(char c);
        void write(std::vector<Coord> coords, char c);
    private:
        std::vector<std::vector<char>> vec;
        int height;
        int width;
        double min_depth;
        double max_depth;
};

Screen::Screen(int h, int w, double min, double max) {
    height = h;
    width = w;
    min_depth = min;
    max_depth = max;

    vec.resize(height, std::vector<char>(width, ' '));
}

void Screen::print() {
    for (int y=0; y<height; ++y) {
        for (int x=0; x<height; ++x) {
            std::cout << vec[y][x];
        }
        std::cout << std::endl;
    }
}

void Screen::fill(char c) {
    for (int y=0; y<height; ++y) {
        for (int x=0; x<height; ++x) {
            vec[y][x] = c;
        }
    }
}

void Screen::write(std::vector<Coord> coords, char c) {
    for (Coord coord : coords) {
        vec[coord.points[y]][coord.points[x]] = c;
    }
}