class Object3D {
    public:
        std::vector<Coord> coords;
        Coord center;
        void move(double amount, Axis axis);      
};

void Object3D::move(double amount, Axis axis) {
    center.points[axis] += amount;
    
    for (Coord coord : coords) {
        coord.points[axis] += amount;
    }
}