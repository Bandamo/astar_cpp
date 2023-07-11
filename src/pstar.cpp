#include "main.hpp"

PStar::PStar(){
    //Constructor
}

PStar::~PStar(){
    //Destructor
}

void PStar::set_map(bool map[MAP_WIDTH][MAP_HEIGHT]){
    //Set the map
    for(int x = 0; x < MAP_WIDTH; x++){
        for(int y = 0; y < MAP_HEIGHT; y++){
            this->map[x][y].x = x;
            this->map[x][y].y = y;
            this->map[x][y].parent = NULL;
            this->map[x][y].cost = -1;
        }
    }
}

bool PStar::get_cost(Point p){
    //Get the cost of a node
    int tmp_cost = this->map[p.x][p.y].cost;
    int best_cost = MAP_HEIGHT * MAP_WIDTH;
    int cost = MAP_HEIGHT * MAP_WIDTH;
    for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++){
            if (this->map[p.x + dx][p.y + dy].cost < best_cost){
                best_cost = this->map[p.x + dx][p.y + dy].cost;
                if (dx == 0 || dy == 0){
                    cost = best_cost + 10;
                }
                else{
                    cost = best_cost + 14;
                }
                this->map[p.x][p.y].parent = &this->map[p.x + dx][p.y + dy];
            }
        }
    }
    this -> map[p.x][p.y].cost = cost;
    return tmp_cost != cost;
}

std::vector<Point> PStar::calculate_path(int startX, int startY, int endX, int endY){
    Point tmp;
    bool running = true;
    int count = 0;

    bool still_running = true;

    this->map[startX][startY].cost = 0;

    while (running){
        std::cout << "Calculating cost... " << count << std::endl;
        count = 0;
        running = false;
        for (int x = 1; x < MAP_WIDTH-1; x++){
            for (int y = 1; y < MAP_HEIGHT-1; y++){
                tmp.x = x;
                tmp.y = y;
                still_running = this->get_cost(tmp);
                running = running || still_running;
                if (still_running){count ++;}
            }
        }
        // Create heatmap file
        std::ofstream myfile;
        myfile.open ("heatmap.txt");
        for (int x = 0; x < MAP_WIDTH; x++){
            for (int y = 0; y < MAP_HEIGHT; y++){
                myfile << this->map[x][y].cost << " ";
            }
            myfile << std::endl;
        }
        myfile.close();
    }
    std::cout << "Cost calculated" << std::endl;
    std::vector<Point> path;

    NodePstar* current = &this->map[endX][endY];
    while ((*current).x != this->map[startX][startY].x && (*current).y != this->map[startX][startY].y){
        path.push_back({current->x, current->y});
        current = current->parent;
    }
    return path;
}

