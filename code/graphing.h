#include <iostream>
#include <vector>
#include <cmath>

struct Coord {
    double y = 0;
    double x = 0;
    double z = 0;
};

struct Order {
    Coord pos;
    Coord end;
};

class Graphing {
    private:
        Order get_order(Coord a, Coord b, double a_val, double b_val);
    public:
        Graphing(int height, int width);
        std::vector<Coord> line(Coord a, Coord b, double step_size);
};

Graphing::Graphing(int height, int width) {
    height = height;
    width = width;
}

Order Graphing::get_order(Coord a, Coord b, double a_val, double b_val) {
    Order order;
    
    if (a_val < b_val) {
        order.pos = a;
        order.end = b;
    }
    else {
        order.pos = b;
        order.end = a;
    }

    return order;
}

std::vector<Coord> Graphing::line(Coord a, Coord b, double step_size) {
    double rise = a.y - b.y;
    double run = a.x - b.x;

    std::vector<Coord> coords;
    
    if (run != 0) { // If no division by 0
        double gradient = rise/run;

        double grad_abs = abs(gradient);

        if (grad_abs <= 1) { // If the line is 45 degrees or less
            Order order = get_order(a, b, a.x, b.x);

            while (order.pos.x < order.end.x) {
                Coord coord;
                coord.x = round(order.pos.x);
                coord.y = round(order.pos.y);
                coords.push_back(coord);

                order.pos.x += step_size;
                order.pos.y += step_size * gradient;
            }
        }
        else { // If the line is above 45 degrees
            Order order = get_order(a, b, a.y, b.y);

            while (order.pos.y < order.end.y) {
                Coord coord;
                coord.x = round(order.pos.x);
                coord.y = round(order.pos.y);
                coords.push_back(coord);

                order.pos.y += step_size;
                order.pos.x += step_size / gradient;
            }
        }

    
    }
    else {
        Order order = get_order(a, b, a.y, b.y);

        while (order.pos.y < order.end.y) {
            Coord coord;
            coord.x = round(order.pos.x);
            coord.y = round(order.pos.y);
            coords.push_back(coord);

            order.pos.y += step_size;
        }
    }

    return coords;
}
