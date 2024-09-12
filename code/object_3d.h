class Object3D {
    public:
        std::vector<Coord> coords;
        Coord center;
        void move(double amount, Axis axis);
};

void Object3D::move(double amount, Axis axis) {
    switch(axis) {
        case y:
            for (Coord coord : coords) {
                coord.y += amount;
            }
            break;
        case x:
            for (Coord coord : coords) {
                coord.x += amount;
            }
        case z:
            for (Coord coord : coords) {
                coord.z += amount;
            }
    }
}
