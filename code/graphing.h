#include <iostream>
#include <vector>
#include <cmath>

struct Coord {
    double y = 0;
    double x = 0;
    double z = 0;
};

enum Axis {
    y,
    x
};

class Graphing {
    private:
        void add_coord(std::vector<Coord> &coords, Coord pos);
        void order_first(Coord &a, Coord &b, Axis axis);
    public:
        Graphing(int height, int width);
        std::vector<Coord> line(Coord a, Coord b, double step_size);
};

Graphing::Graphing(int height, int width) {
    height = height;
    width = width;
}

void Graphing::add_coord(std::vector<Coord> &coords, Coord pos) {
    Coord rounded = {round(pos.y), round(pos.x), round(pos.z)};
    coords.push_back(rounded);
}

void Graphing::order_first(Coord &a, Coord &b, Axis axis) {
    bool swap = false;
    switch (axis) {
        case y:
            if (a.y > b.y) {
                swap = true;
            }
            break;
        case x:
            if (a.x > b.x) {
                swap = true;
            }
            break;
    }

    if (swap) {
        Coord old_a = a;
        a = b;
        b = old_a;
    }
}

std::vector<Coord> Graphing::line(Coord a, Coord b, double step_size) {
    double rise = a.y - b.y;
    double run = a.x - b.x;

    std::vector<Coord> coords;

    if (run != 0) {
        double gradient = rise/run;
        double grad_abs = abs(gradient);

        if (grad_abs <= 1) {
            order_first(a, b, x);

            while (a.x < b.x) {
                add_coord(coords, a);
                a.x += step_size;
                a.y += step_size * gradient;
            }
        }
        else {
            order_first(a, b, y);

            while (a.y < b.y) {
                add_coord(coords, a);
                a.y += step_size;
                a.x += step_size / gradient;
            }
        }
    }
    else {
        order_first(a, b, y);

        while (a.y < b.y) {
            add_coord(coords, a);
            a.y += step_size;
        }
    }

    std::cout << "coords" << std::endl;
    for (Coord coord : coords) {
        std::cout << coord.z << std::endl;
    }

    return coords;
}
