#include "Maze.h"

/**
 * @brief Initializes the entire maze to 0. Sets the perimeter of the maze
 */
void fp::Maze::initializeMaze(){
    maze.fill({});
    for (int x = 0; x < 16; x++){
        for (int y = 0; y < 16; y++){
            if (x == 0){
                setWallWest(x, y);
                fp::API::setWall(x, y, 'w');
            }
            if (y == 0){
                setWallSouth(x, y);
                fp::API::setWall(x, y, 's');
            }
            if (x == 15){
                setWallEast(x, y);
                fp::API::setWall(x, y, 'e');
            }
            if (y == 15){
                setWallNorth(x, y);
                fp::API::setWall(x, y, 'n');
            }
        }
    }
    
}

/**
 * @brief Method to return if wall is present on north of cell i.e. index 0
 * @param robot_x X co-ordinate of the robot in maze
 * @param robot_y Y co-ordinate of the robot in maze
 * @return 1 if there is a wall on north of that cell else 0
 */
int fp::Maze::getWallNorth(int robot_x, int robot_y){
    return maze.at(robot_x*16 + robot_y).at(0);
}

/**
 * @brief Method to return if wall is present on south  of cell i.e. index 1
 * @param robot_x X co-ordinate of the robot in maze
 * @param robot_y Y co-ordinate of the robot in maze
 * @return 1 if there is a wall on south of that cell else 0
*/
int fp::Maze::getWallSouth(int robot_x, int robot_y){
    return maze.at(robot_x*16 + robot_y).at(1);
}

/**
 * @brief Method to return if wall is present on east of cell i.e. index 2
 * @param robot_x X co-ordinate of the robot in maze
 * @param robot_y Y co-ordinate of the robot in maze
 * @return 1 if there is a wall on east of that cell else 0
*/
int fp::Maze::getWallEast(int robot_x, int robot_y){
    return maze.at(robot_x*16 + robot_y).at(2);
}

/**
 * @brief Method to return if wall is present on west of cell i.e. index 3
 * @param robot_x X co-ordinate of the robot in maze
 * @param robot_y Y co-ordinate of the robot in maze
 * @return 1 if there is a wall on west of that cell else 0
*/
int fp::Maze::getWallWest(int robot_x, int robot_y){
    return maze.at(robot_x*16 + robot_y).at(3);
}

/**
 * @brief Method to set wall at the north of current cell
 * @param robot_x X co-ordinate of the current cell of robot in maze
 * @param robot_y Y co-ordinate of the current cell of robot in maze
*/
void fp::Maze::setWallNorth(int robot_x, int robot_y){
    maze.at(robot_x*16 + robot_y).at(0) = 1;
}

/**
 * @brief Method to set wall at the south of current cell
 * @param robot_x X co-ordinate of the current cell of robot in maze
 * @param robot_y Y co-ordinate of the current cell of robot in maze
*/
void fp::Maze::setWallSouth(int robot_x, int robot_y){
    maze.at(robot_x*16 + robot_y).at(1) = 1;
}

/**
 * @brief Method to set wall at the east of current cell
 * @param robot_x X co-ordinate of the current cell of robot in maze
 * @param robot_y Y co-ordinate of the current cell of robot in maze
*/
void fp::Maze::setWallEast(int robot_x, int robot_y){
    maze.at(robot_x*16 + robot_y).at(2) = 1;
}

/**
 * @brief Method to set wall at the west of current cell
 * @param robot_x X co-ordinate of the current cell of robot in maze
 * @param robot_y Y co-ordinate of the current cell of robot in maze
*/
void fp::Maze::setWallWest(int robot_x, int robot_y){
    maze.at(robot_x*16 + robot_y).at(3) = 1;
}

/**
 * @brief Method to update the maze as walls are encountered by the robot facing in a particular direction
 * @param robot_x X co-ordinate of the current cell of robot in maze
 * @param robot_y Y co-ordinate of the current cell of robot in maze
 * @param direction Direction the robot is currently facing
*/
void fp::Maze::updateMaze(int robot_x, int robot_y, char direction){
    // Robot facing north
    if (direction == 'N' || direction == 'n'){
        if (fp::API::wallFront()){
            fp::API::setWall(robot_x, robot_y, 'n');
            setWallNorth(robot_x, robot_y);
       }
        if (fp::API::wallRight()){
            fp::API::setWall(robot_x, robot_y, 'e');
            setWallEast(robot_x, robot_y);
        }
        if (fp::API::wallLeft()){
            fp::API::setWall(robot_x, robot_y, 'w');
            setWallWest(robot_x, robot_y);
        }
    }
    
    // Robot facing east
    else if (direction == 'E' || direction == 'e'){
        if (fp::API::wallFront()){
            fp::API::setWall(robot_x, robot_y, 'e');
            setWallEast(robot_x, robot_y);
        }
        if (fp::API::wallRight()){
            fp::API::setWall(robot_x, robot_y, 's');
            setWallSouth(robot_x, robot_y);
        }
        if (fp::API::wallLeft()){
            fp::API::setWall(robot_x, robot_y, 'n');
            setWallNorth(robot_x, robot_y);
        }
    }
    
    // Robot facing South
    else if (direction == 'S' || direction == 's'){
        if (fp::API::wallFront()){
            fp::API::setWall(robot_x, robot_y, 's');
            setWallSouth(robot_x, robot_y);
        }
        if (fp::API::wallRight()){
            fp::API::setWall(robot_x, robot_y, 'w');
            setWallWest(robot_x, robot_y);
        }
        if (fp::API::wallLeft()){
            fp::API::setWall(robot_x, robot_y, 'e');
            setWallEast(robot_x, robot_y);
        }
    }
    
    //Robot facing West
    else if (direction == 'W' || direction == 'w'){
        if (fp::API::wallFront()){
            fp::API::setWall(robot_x, robot_y, 'w');
            setWallWest(robot_x, robot_y);
        }
        if (fp::API::wallRight()){
            fp::API::setWall(robot_x, robot_y, 'n');
            setWallNorth(robot_x, robot_y);
        }
        if (fp::API::wallLeft()){
            fp::API::setWall(robot_x, robot_y, 's');
            setWallSouth(robot_x, robot_y);
        }
    }
}
