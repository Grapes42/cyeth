class Projection {
    public:
        void use_perspective_matrix(
            double fov, double aspect_ratio, double near, double far
        );
        std::vector<Coord> project(std::vector<Coord> coords_3d);
        std::array<std::array<double, 4>, 4> matrix;
};

void Projection::use_perspective_matrix(
    double fov, double aspect_ratio, double near, double far
) {
    double f = 1 / tan(fov * 0.5 * PI / 180); // Convert FOV to rads

    std::array<std::array<double, 4>, 4> perspective_matrix = {{
        {f / aspect_ratio, 0, 0, 0},
        {0, f, 0, 0},
        {0, 0, (far + near) / (near - far), (2 * far * near) / (near - far)},
        {0, 0, -1, 0}
    }};

    matrix = perspective_matrix;
}

std::vector<Coord> Projection::project(std::vector<Coord> coords_3d) {
    std::vector<Coord> coords_2d;
 
    for (Coord coord_3d : coords_3d) {
        Coord coord_2d;

        for (int i=0; i<4; ++i) {
            coord_2d.points[i] = 0;

            for (int j=0; j<4; ++j) {
                coord_2d.points[i] += matrix[i][j] * coord_3d.points[j];
            }
        }

        if (coord_2d.points[w] != 0) {
            coord_2d.points[y] /= coord_2d.points[w];
            coord_2d.points[x] /= coord_2d.points[w]; 
            coord_2d.points[z] /= coord_2d.points[w]; 
            coord_2d.points[w] = 1;
        }

        coords_2d.push_back(coord_2d);
    }



    return coords_2d;
}