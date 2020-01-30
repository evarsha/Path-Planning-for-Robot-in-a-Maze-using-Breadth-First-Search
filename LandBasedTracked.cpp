#include "LandBasedTracked.h"
#include "../API/API.h"

/**
 * @brief Get the direction of the robot in the maze
*/
char fp::LandBasedTracked::GetDirection(){
    return direction_;
}

/**
 * @brief Move the robot forward
*/
void fp::LandBasedTracked::MoveForward(){
    fp::API::moveForward();
    x_ += (fp::LandBasedTracked::GetDirection() == 'E'  ? 1 : (fp::LandBasedTracked::GetDirection() == 'W'  ? -1 : 0));
    y_ += (fp::LandBasedTracked::GetDirection() == 'N' ? 1 : (fp::LandBasedTracked::GetDirection() == 'S' ? -1 : 0));
}

/**
 * @brief Rotate the robot 90°counter-clockwise.
*/
void fp::LandBasedTracked::TurnLeft(){
    fp::API::turnLeft();
    if(fp::LandBasedTracked::GetDirection() == 'N')
        direction_ = 'W';
    else if (fp::LandBasedTracked::GetDirection() == 'E')
        direction_ = 'N';
    else if (fp::LandBasedTracked::GetDirection() == 'S')
        direction_ = 'E';
    else if (fp::LandBasedTracked::GetDirection() == 'W')
        direction_ = 'S';
}

/**
 * @brief Rotate the robot 90° clockwise.
*/
void fp::LandBasedTracked::TurnRight(){
    fp::API::turnRight();
    if(fp::LandBasedTracked::GetDirection() == 'N')
        direction_ = 'E';
    else if (fp::LandBasedTracked::GetDirection() == 'E')
        direction_ = 'S';
    else if (fp::LandBasedTracked::GetDirection() == 'S')
        direction_ = 'W';
    else if (fp::LandBasedTracked::GetDirection() == 'W')
        direction_ = 'N';
}
