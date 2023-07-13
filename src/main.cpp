#include "main.hpp"

int main(){
    int nb_try = 100;
    float list_time[nb_try];

    for (int i = 0; i < nb_try; i++){

    //Create the map
    bool map[MAP_WIDTH][MAP_HEIGHT];
    for(int x = 0; x < MAP_WIDTH; x++){
        for(int y = 0; y < MAP_HEIGHT; y++){
            /*
            if (sqrt((x-200)*(x-200) + (y-100)*(y-100)) < 80 && sqrt((x-200)*(x-200) + (y-100)*(y-100)) > 60 && y > 100){
                map[x][y] = false;
            }
            else{
                map[x][y] = true;
            }
            */
            // Generate random map from numbrer between 0 and 1
            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            if (r < 0.2){
                map[x][y] = false;
            }
            else{
                map[x][y] = true;
            }
        }
    }

    //std::cout << "Map created" << std::endl;

    //Create the A* object
    PStar astar;
    //std::cout << "A* object created" << std::endl;

    //Set the map
    astar.set_map(map);
    //std::cout << "Map set" << std::endl;

    //Calculate the path
    // Chrono this function

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<Point> path = astar.calculate_path(1, 1, 298, 198);

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    list_time[i] = elapsed.count();

    //std::cout << "Elapsed time : " << elapsed.count() << " s\n";
    //std::cout << "Path length : " << path.size() << std::endl;
    
    //std::cout << "Showing map..." << std::endl;
    
    /*
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
    */

    std::cout << "Progress : "<< i << "/" << nb_try << std::endl;
    }

    // Get mean and std
    float mean = 0;
    for (int i = 0; i < nb_try; i++){
        mean += list_time[i];
    }
    mean /= nb_try;

    float std = 0;
    for (int i = 0; i < nb_try; i++){
        std += (list_time[i] - mean)*(list_time[i] - mean);
    }
    std /= nb_try;
    std = sqrt(std);

    std::cout << "Mean : " << mean << " s "<< std::endl;
    std::cout << "Std : " << std << " s "<< std::endl;

    return 0;
}
