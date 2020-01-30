#pragma once
#include <vector>
#include <list>
#include "../API/API.h"
#include "../Maze/Maze.h"
#include "../LandBasedWheeled/LandBasedWheeled.h"
#include "../LandBasedTracked/LandBasedTracked.h"
#include <cstdlib>

namespace fp{
/**
 * @brief Class to get the robot to traverse the maze using BFS
*/
    class Algorithm{
    public:
        /// Array of possible maze indexes the robot will follow to reach the goal
        std::vector<int> pathArr;
        /// Variable to check if path was found in a maze
        bool foundPath = false;
        /// Array to see what positions in the maze were part of the actual path
        std::array<int, 256> visitedPosition;
        bool checkGoal(int x, int y, fp::Maze& maze);
        void solve(std::shared_ptr<fp::LandBasedRobot> robot, fp::Maze& maze);
        void step(std::shared_ptr<fp::LandBasedRobot> r, fp::Maze& maze);
        void generatePath(int current, fp::Maze& m, std::shared_ptr<fp::LandBasedRobot> r);
        void moveRobot(std::shared_ptr<fp::LandBasedRobot> robot, fp::Maze& maze);
        void colorCenter(char color, fp::Maze& m);
    };
}
