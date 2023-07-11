#ifndef PSTAR_HPP
#define PSTAR_HPP

#include "main.hpp"
#define MAP_WIDTH 300
#define MAP_HEIGHT 200

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
        int map_cost[MAP_WIDTH][MAP_HEIGHT];
        bool map[MAP_WIDTH][MAP_HEIGHT];
        bool get_cost(Point p);
};

#endif // PSTAR_HPP