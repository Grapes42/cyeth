std::vector<Coord> cube(Coord center, double width, double height, double depth) {
    height = height/2;
    width = width/2;
    depth = depth/2;

    std::vector<Coord> coords = {
        Coord(center.y-height, center.x-width, center.z-depth, 1), // Top left front
        Coord(center.y+height, center.x-width, center.z-depth, 1), // Bottom left front
        Coord(center.y-height, center.x+width, center.z-depth, 1), // Top right front
        Coord(center.y+height, center.x+width, center.z-depth, 1), // Bottom right front

        Coord(center.y-height, center.x-width, center.z+depth, 1), // Top left back
        Coord(center.y+height, center.x-width, center.z+depth, 1), // Bottom left back
        Coord(center.y-height, center.x+width, center.z+depth, 1), // Top right back
        Coord(center.y+height, center.x+width, center.z+depth, 1) // Bottom right back
    };

    std::cout << "cube at func: " << std::endl;
    for (Coord coord : coords) {
        std::cout << "y: " << coord.y 
                  << ", x: " << coord.x
                  << ", z: " << coord.z
                  << ", w: " << coord.w
                  << std::endl;
    }
    std::cout << "\n\n\n";

    std::vector<Coord> &ref = coords;
    return ref;
}