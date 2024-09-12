class Coord {
    public:  
        std::array<double, 4> points = {0, 0, 0, 1};
        double y;
        double x;
        double z;
        double w;
        Coord(double y_in, double x_in, double z_in, double w_in);
};

Coord::Coord(double y_in, double x_in, double z_in, double w_in) {
    double &y = points[0];
    double &x = points[1];
    double &z = points[2];
    double &w = points[3];

    y = y_in;
    x = x_in;
    z = z_in;
    w = w_in;
}

enum Axis {
    y,
    x,
    z,
    w
};

const double PI = 3.14159;