#include "Algorithm.h"
#include <iostream>
#include <sstream>

/**
 * @brief Method to check if the current position of the robot is one of the goal positions
 *  @param x X co-ordinate of the robot position in maze
 *  @param y Y co-ordinate of the robot position in maze
 *  @param m The current maze we are working with
 */
bool fp::Algorithm::checkGoal(int x, int y, fp::Maze& m){
    
    if (x == m.getX(119) && y == m.getY(119)){
        return true;
    }
    if (x == m.getX(135) && y == m.getY(135)){
        return true;
    }
    if (x == m.getX(120) && y == m.getY(120)){
        return true;
    }
    if (x == m.getX(136) && y == m.getY(136)){
        return true;
    }
    return false;
    
}

/**
 * @brief Entry to the algorithm class. Checks if the current position is a goal position or if the reset button was pressed.
 * @param robot A shared pointer for the robot that is moving in the maze
 * @param maze A maze object for the maze robot is moving in
 */

void fp::Algorithm::solve(std::shared_ptr<fp::LandBasedRobot> robot, fp::Maze& maze){
    
    // Main algorithm to find the path to the center
    visitedPosition.fill({});
    while(!checkGoal(robot->getX(), robot->getY(), maze)){
        if (fp::API::wasReset()){
            fp::API::ackReset();
            fp::API::clearAllColor();
            maze.initializeMaze();
            for (int i = 0 ; i < 16 ; i++){
                for (int j = 0 ; j < 16 ; j++){
                    fp::API::clearWall(i, j, 'n');
                    fp::API::clearWall(i, j, 'e');
                    fp::API::clearWall(i, j, 's');
                    fp::API::clearWall(i, j, 'w');
                }
            }
            std::abort();
        }
        else{
            API::setColor(0, 0, 'G');
            step(robot, maze);
            foundPath = true;
        }
    }
    if (foundPath){
        colorCenter('G', maze);
        std::cerr << "Successfully found the goal at " << robot->getX() << " " << robot->getY() << std::endl;
    }
    else{
        fp::API::clearAllColor();
        maze.initializeMaze();
        for (int i = 0 ; i < 16 ; i++){
            for (int j = 0 ; j < 16 ; j++){
                fp::API::clearWall(i, j, 'n');
                fp::API::clearWall(i, j, 'e');
                fp::API::clearWall(i, j, 's');
                fp::API::clearWall(i, j, 'w');
            }
        }
        std::cerr << "No path found" << std::endl;
        std::abort();
    }
}

/**
 * @brief Generates path from the current postion to the goal and moves the robot according to that path
 * @param r A shared pointer for the robot that is moving in the maze
 * @param maze A maze object for the maze robot is moving in
 */

void fp::Algorithm::step(std::shared_ptr<fp::LandBasedRobot> r, fp::Maze& maze){
    
    // Get the cell for the current position of the robot
    int currentCell = (16*r->getX())+r->getY();
    
    // Generate a path from the current cell to the destination
    colorCenter('G', maze);
    generatePath(currentCell, maze, r);
    moveRobot(r, maze);
    
    // Color the path robot took in the maze with Cyan otherwise black out unvisited nodes from the possible paths
    for (int i = 1 ; i < 256; i++){
        if (visitedPosition.at(i) == 1){
                fp::API::setColor(i/16, i%16, 'c');
        }
        else{
            fp::API::setColor(i/16, i%16, 'k');
        }
    }
    
}

/**
 * @brief BFS algorithm generating the path from current position to the goal
 * @param current Current position of the robot in the maze
 * @param m A maze object for the maze robot is moving in
 * @param r A shared pointer for the robot that is moving in the maze
 */

void fp::Algorithm::generatePath(int current, fp::Maze& m, std::shared_ptr<fp::LandBasedRobot> r){
    
    current = (16*r->getX())+r->getY();
    int start;
    
    // Variables for the Manhattan Distance to the goal node
    int dll,dlr,dul,dur,min;
    int goal,goal_final;
    
    int count=0;
    
    // Maze value for the center 4 goal co-ordinates
    int goalLL = 119;
    int goalLR = 135;
    int goalUL = 120;
    int goalUR = 136;
    
    bool visited[16][16] = {0};
    int parent[16][16];
    std::vector<int> path;
    std::list<int> queue;
    
    start = current;
    visited[m.getY(current)][m.getX(current)] = true;
    queue.push_back(current);
    while(!queue.empty()){
        current = queue.front();
        std::list<int> adj;
        // If wall not in the south of robot (down)
        if (m.getWallSouth(m.getX(current),m.getY(current)) != 1){
           adj.push_back(16*(m.getX(current))+m.getY(current)-1);
        }
        // If wall not in the east of robot (right)
        if (m.getWallEast(m.getX(current),m.getY(current)) != 1){
           adj.push_back(16*(m.getX(current)+1)+m.getY(current));
        }
        // If wall not in the north of robot (up)
        if (m.getWallNorth(m.getX(current),m.getY(current)) != 1){
           adj.push_back(16*(m.getX(current))+m.getY(current)+1);
        }
        // If wall not in the west of robot (left)
        if (m.getWallWest(m.getX(current),m.getY(current)) != 1){
           adj.push_back(16*(m.getX(current)-1)+m.getY(current));
        }
        
        queue.pop_front();
        for(auto i : adj){
            if(!visited[m.getY(i)][m.getX(i)]){
                visited[m.getY(i)][m.getX(i)] = true;
                queue.push_back(i);
                parent[m.getY(i)][m.getX(i)] = current;
            }
         }
    }
    
    // Dynamically select the goal based on Hamming Distance
    dll = std::abs(m.getX(start)-m.getX(119)) + std::abs(m.getY(start)-m.getY(119));
    dlr = std::abs(m.getX(start)-m.getX(135)) + std::abs(m.getY(start)-m.getY(135));
    dul = std::abs(m.getX(start)-m.getX(120)) + std::abs(m.getY(start)-m.getY(120));
    dur = std::abs(m.getX(start)-m.getX(136)) + std::abs(m.getY(start)-m.getY(136));
    min = dll;
    
    if (dlr<min){
        min = dlr;
    }
    if (dul<min){
        min = dul;
    }
    if (dur<min){
        min = dur;
    }
    if (min == dll){
        goal = goalLL;
    }
    else if (min == dul){
        goal = goalUL;
    }
    else if (min == dur){
        goal = goalUR;
    }
    else{
        goal = goalLR;
    }
    goal_final = goal;
    
    //Loop for bactracking
    while(goal != start){
         path.push_back(parent[m.getY(goal)][m.getX(goal)]);
         goal = path.at(count);
         count+=1;
     }
    
    std::reverse(path.begin(), path.end());
    // Add the goal that was found to the path
    path.push_back(goal_final);
    
    int pathSize = (int)path.size();
    pathArr.clear();
    for (int i = 0 ; i < pathSize; i++){
        pathArr.push_back(path.at(i));
    }
    int i = 0;
    
    // Color the possible path the BFS algorithm generated
    for (i = 0 ; i < pathSize; i++){
        fp::API::setColor(m.getX(pathArr[i]), m.getY(pathArr[i]), 'o');
    }
}

/**
 * @brief Moves the robot in the maze based on the possible path generated
 * @param robot A shared pointer for the robot that is moving in the maze
 * @param maze A maze object for the maze robot is moving in
 */


void fp::Algorithm::moveRobot(std::shared_ptr<fp::LandBasedRobot> robot, fp::Maze& maze){
    
    int past_x, past_y;
    char dir = 'n';
    
    for (int i = 1; i <= pathArr.size(); i++){
        // Reset button pressed
        if (fp::API::wasReset()){
            fp::API::ackReset();
            fp::API::clearAllColor();
            maze.initializeMaze();
            for (int i = 0 ; i < 16 ; i++){
                for (int j = 0 ; j < 16 ; j++){
                    fp::API::clearWall(i, j, 'n');
                    fp::API::clearWall(i, j, 'e');
                    fp::API::clearWall(i, j, 's');
                    fp::API::clearWall(i, j, 'w');
                }
            }
            std::abort();
        }
        else{
            maze.updateMaze(robot->getX(), robot->getY(), robot->GetDirection());
            
            past_x = robot->getX();
            past_y = robot->getY();
            
            visitedPosition.at(robot->getX()*16 + robot->getY()) = 1;
            
            // Updating direction to move to for the next cell
            if (past_x < maze.getX(pathArr[i]) && past_y == maze.getY(pathArr[i])){
                dir = 'e';
            }
            else if (past_y > maze.getY(pathArr[i]) && past_x == maze.getX(pathArr[i])){
                dir = 's';
            }
            else if (past_x > maze.getX(pathArr[i]) && past_y == maze.getY(pathArr[i])){
                dir = 'w';
            }
            else if (past_x == maze.getX(pathArr[i]) && past_y < maze.getY(pathArr[i])){
                dir = 'n';
            }
            else{
                break;
            }
            
            // Move based on current direction, the direction of the next cell relative to the current cell, if wall is found in that direction and if the last position was already in goal
            if (robot->GetDirection() == 'N' && dir == 'n' && maze.getWallNorth(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'N' && dir == 'e' && maze.getWallEast(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnRight();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'N' && dir == 'w' && maze.getWallWest(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnLeft();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'N' && dir == 's' && maze.getWallSouth(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnLeft();
                robot->TurnLeft();
                robot->MoveForward();
            }
            
            else if (robot->GetDirection() == 'S' && dir == 'n' && maze.getWallNorth(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnLeft();
                robot->TurnLeft();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'S' && dir == 'e' && maze.getWallEast(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnLeft();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'S' && dir == 'w' && maze.getWallWest(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnRight();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'S' && dir == 's' && maze.getWallSouth(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->MoveForward();
            }
            
            else if (robot->GetDirection() == 'E' && dir == 'n' && maze.getWallNorth(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnLeft();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'E' && dir == 'e' && maze.getWallEast(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'E' && dir == 'w' && maze.getWallWest(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnLeft();
                robot->TurnLeft();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'E' && dir == 's' && maze.getWallSouth(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnRight();
                robot->MoveForward();
            }
            
            else if (robot->GetDirection() == 'W' && dir == 'n' && maze.getWallNorth(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnRight();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'W' && dir == 'e' && maze.getWallEast(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnLeft();
                robot->TurnLeft();
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'W' && dir == 'w' && maze.getWallWest(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->MoveForward();
            }
            else if (robot->GetDirection() == 'W' && dir == 's' && maze.getWallSouth(past_x, past_y) != 1 && !checkGoal(past_x, past_y, maze)){
                robot->TurnLeft();
                robot->MoveForward();
            }
        }
    }
}

/**
 * @brief Color the goal co-ordinates of the maze
 * @param color The color you want to set them to
 * @param m A maze object for the maze robot is moving in
 */
    
void fp::Algorithm::colorCenter(char color, fp::Maze& m) {
    for (int x = m.getX(119); x <= m.getX(136); x += 1) {
        for (int y = m.getY(119); y <= m.getY(136); y += 1) {
            API::setColor(x, y, color);
        }
    }
}
