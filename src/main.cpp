#include "main.hpp"

inline bool operator < (const Node& lhs, const Node& rhs){//We need to overload "<" to put our struct into a set
    return lhs.fCost < rhs.fCost;
}

int main(){
    //Create the map
    bool map[MAP_WIDTH][MAP_HEIGHT];
    for(int x = 0; x < MAP_WIDTH; x++){
        for(int y = 0; y < MAP_HEIGHT; y++){
            if (sqrt((x-100)*(x-100) + (y-100)*(y-100)) < 80 && sqrt((x-100)*(x-100) + (y-100)*(y-100)) > 60 && y > 100){
                map[x][y] = false;
            }
            else{
                map[x][y] = true;
            }
        }
    }

    std::cout << "Map created" << std::endl;

    //Create the A* object
    Astar astar;
    std::cout << "A* object created" << std::endl;

    //Set the map
    astar.set_map(map);
    std::cout << "Map set" << std::endl;

    //Calculate the path
    // Chrono this function

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<Node> path =astar.calculate_path(0, 0, 299, 199);

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "Elapsed time : " << elapsed.count() << " s\n";
    std::cout << "Path length : " << path.size() << std::endl;
    
    std::cout << "Showing map..." << std::endl;
    
    // Save path to file
    std::ofstream myfile;
    myfile.open ("path.txt");
    for (auto node : path){
        myfile << node.x << " " << node.y << std::endl;
    }
    myfile.close();

    myfile.open("map.txt");
    // Save all the false
    for(int x = 0; x < MAP_WIDTH; x++){
        for(int y = 0; y < MAP_HEIGHT; y++){
            if (map[x][y] == false){
                myfile << x << " " << y << std::endl;
            }
        }
    }
    myfile.close();

    return 0;
}
