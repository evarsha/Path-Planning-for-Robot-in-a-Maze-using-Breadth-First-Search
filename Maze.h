#pragma once
#include <array>
#include "../API/API.h"

namespace fp{
/**
 * @brief Class to store and perform functions on the maze robot is moving in
 */
class Maze{
private:
    /// Width of the maze
    static const int WIDTH = 16;
    /// Height of the maze
    static const int HEIGHT = 16;
    /// 2D array to store the array. maze[x][0] refers to wall at north of x cell ; maze[x][1] refers to wall at south of x cell ; maze[x][2] refers to wall at east of x cell ; maze[x][3] refers to wall at west of x cell
    std::array<std::array<int, 4>, 256> maze;
    
public:
    
    /**
     * @brief Getter method to get the X coordinate of the robot in the maze
     * @param index Index for the robot in stored maze
     * @return X coordinate of the robot in the maze
     */
    int getX(int index){
        return index / 16;
    }
    
    /**
     * @brief Getter method to get the Y coordinate of the robot in the maze
     * @param index Index for the robot in stored maze
     * @return Y coordinate of the robot in the maze
     */
    int getY(int index){
        return index % 16;
    }
    
    /**
     * @brief Getter method to get the width of maze
     * @return Width of the maze
     */
    static int getWidth(){
        return WIDTH;
    }
    
    /**
     * @brief Getter method to get the height of maze
     * @return Height of the maze
     */
    static int getHeight(){
        return HEIGHT;
    }
    
    void initializeMaze();
    void updateMaze(int robot_x, int robot_y, char robot_dir);
    
    int getWallNorth(int robot_x, int robot_y);
    int getWallSouth(int robot_x, int robot_y);
    int getWallEast(int robot_x, int robot_y);
    int getWallWest(int robot_x, int robot_y);
    
    void setWallNorth(int robot_x, int robot_y);
    void setWallSouth(int robot_x, int robot_y);
    void setWallEast(int robot_x, int robot_y);
    void setWallWest(int robot_x, int robot_y);
};
}
