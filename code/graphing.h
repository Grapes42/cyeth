class Graphing {
    private:
        void order_first(Coord &a, Coord &b, Axis axis);
    public:
        std::vector<Coord> line(Coord a, Coord b, double step_size);
        void add_coord(std::vector<Coord> &coord, Coord pos);
};

void Graphing::order_first(Coord &a, Coord &b, Axis axis) {
    bool swap = false;

    if (a.points[axis] > b.points[axis]) {
        Coord old_a = a;
        a.points = b.points;
        b.points = old_a.points;
    }
}

void Graphing::add_coord(std::vector<Coord> &coords, Coord pos) {
    Coord rounded = {round(pos.points[y]), round(pos.points[x]),
                     round(pos.points[z]), round(pos.points[w])};
    coords.push_back(rounded);
}

std::vector<Coord> Graphing::line(Coord a, Coord b, double step_size) {
    double rise = a.points[y] - b.points[y];
    double run = a.points[x] - b.points[x];

    std::vector<Coord> coords;

    // If gradient wont result in 0 division
    // I.e. if not a perfectly vertical line
    if (run != 0) {
        double gradient = rise/run;
        double grad_abs = abs(gradient);

        // If line is 45 degrees or shallower
        if (grad_abs <= 1) {
            order_first(a, b, x);

            while (a.points[x] <= b.points[x]) {
                add_coord(coords, a);
                a.points[x] += step_size;
                a.points[y] += step_size * gradient;
            }
        }
        // If line is steeper than 45 degrees
        else {
            order_first(a, b, y);

            while (a.points[y] <+ b.points[y]) {
                add_coord(coords, a);
                a.points[y] += step_size;
                a.points[x] += step_size / gradient;
            }
        }
    }
    else {
        order_first(a, b, y);

        while (a.points[y] <= b.points[y]) {
            add_coord(coords, a);
            a.points[y] += step_size;
        }
    }

    return coords;
}