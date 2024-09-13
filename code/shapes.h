std::vector<Coord> cube(Coord center, double width, double height, double depth) {
    height /= 2;
    width /= 2;
    depth /= 2;

    Coord top_left_front =     {center.points[y]-height, center.points[x]-width, center.points[z]-depth};
    Coord bottom_left_front =  {center.points[y]+height, center.points[x]-width, center.points[z]-depth};
    Coord top_right_front =    {center.points[y]-height, center.points[x]+width, center.points[z]-depth};
    Coord bottom_right_front = {center.points[y]+height, center.points[x]+width, center.points[z]-depth};

    Coord top_left_back =      {center.points[y]-height, center.points[x]-width, center.points[z]+depth};
    Coord bottom_left_back =   {center.points[y]+height, center.points[x]-width, center.points[z]+depth};
    Coord top_right_back =     {center.points[y]-height, center.points[x]+width, center.points[z]+depth};
    Coord bottom_right_back =  {center.points[y]+height, center.points[x]+width, center.points[z]+depth};

    std::vector<Coord> coords = {
        top_left_front, bottom_left_front, top_right_front, bottom_right_front,
        top_left_back, bottom_left_back, top_right_back, bottom_right_back
    };

    return coords;
}