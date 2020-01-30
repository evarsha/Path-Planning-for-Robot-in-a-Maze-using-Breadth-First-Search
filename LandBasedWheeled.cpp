#include "LandBasedWheeled.h"
#include "../API/API.h"

/**
 * @brief Get the direction of the robot in the maze
 */
char fp::LandBasedWheeled::GetDirection(){
    return direction_;
}

/**
 * @brief Move the robot forward
 */
void fp::LandBasedWheeled::MoveForward(){
    fp::API::moveForward();
    x_ += (fp::LandBasedWheeled::GetDirection() == 'E'  ? 1 : (fp::LandBasedWheeled::GetDirection() == 'W'  ? -1 : 0));
    y_ += (fp::LandBasedWheeled::GetDirection() == 'N' ? 1 : (fp::LandBasedWheeled::GetDirection() == 'S' ? -1 : 0));
}

/**
 * @brief Rotate the robot 90°counter-clockwise.
 */
void fp::LandBasedWheeled::TurnLeft(){
    fp::API::turnLeft();
    if(fp::LandBasedWheeled::GetDirection() == 'N')
        direction_ = 'W';
    else if (fp::LandBasedWheeled::GetDirection() == 'E')
        direction_ = 'N';
    else if (fp::LandBasedWheeled::GetDirection() == 'S')
        direction_ = 'E';
    else if (fp::LandBasedWheeled::GetDirection() == 'W')
        direction_ = 'S';
}

/**
 * @brief Rotate the robot 90° clockwise.
 */
void fp::LandBasedWheeled::TurnRight(){
    fp::API::turnRight();
    if(fp::LandBasedWheeled::GetDirection() == 'N')
        direction_ = 'E';
    else if (fp::LandBasedWheeled::GetDirection() == 'E')
        direction_ = 'S';
    else if (fp::LandBasedWheeled::GetDirection() == 'S')
        direction_ = 'W';
    else if (fp::LandBasedWheeled::GetDirection() == 'W')
        direction_ = 'N';
}

/**
 * @brief The robot can increase its speed, which is translated by the number of cells in the maze that the robot can traverse in each step.
 * @param speed Number of steps it can traverse in each step
 */
void fp::LandBasedWheeled::SpeedUp(int speed){
    std::cout << "Entered LandBasedWheeled::SpeedUp\n";
}
