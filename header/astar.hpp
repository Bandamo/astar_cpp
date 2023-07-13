#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "main.hpp"
#define MAP_WIDTH 900
#define MAP_HEIGHT 600

#define USE_SQRT 1

struct Node{
    int x;
    int y;
    int parentX;
    int parentY;
    long gCost;
    long hCost;
    float fCost;
};

class Astar{
    public:
        Astar();
        ~Astar();

        std::vector<Node> calculate_path(int startX, int startY, int endX, int endY);
        void set_map(bool map[MAP_WIDTH][MAP_HEIGHT]);

    private:
        bool map[MAP_WIDTH][MAP_HEIGHT];
        float heuristic(Node current, Node end);
        bool is_valid(int x, int y);
};

#endif
