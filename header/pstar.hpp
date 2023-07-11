#ifndef PSTAR_HPP
#define PSTAR_HPP

#include "main.hpp"
#define MAP_WIDTH 300
#define MAP_HEIGHT 200

struct NodePstar{
    int x;
    int y;
    NodePstar* parent;
    float cost;
};

struct Point{
    int x;
    int y;
};

class PStar{
    public:
        PStar();
        ~PStar();

        std::vector<Point> calculate_path(int startX, int startY, int endX, int endY);
        void set_map(bool map[MAP_WIDTH][MAP_HEIGHT]);

    private:
        NodePstar map[MAP_WIDTH][MAP_HEIGHT];
        bool get_cost(Point p);
};

#endif // PSTAR_HPP