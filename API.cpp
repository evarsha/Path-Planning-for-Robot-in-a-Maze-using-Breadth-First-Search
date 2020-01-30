#include "API.h"
#include <cstdlib>
#include <iostream>

/**
 * @brief Method to get the width of the maze
 * @return Width of the maze
*/
int fp::API::mazeWidth() {
    std::cout << "mazeWidth" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
    
}

/**
 * @brief Method to get the height of the maze
 * @return Height of the maze
*/
int fp::API::mazeHeight() {
    std::cout << "mazeHeight" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
    
}

/**
 * @brief Method to check if wall exists in front of the robot
 * @return True if yes, else false
*/
bool fp::API::wallFront() {
    std::cout << "wallFront" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
    
}

/**
 * @brief Method to check if wall exists to the right of the robot
 * @return True if yes, else false
*/
bool fp::API::wallRight() {
    std::cout << "wallRight" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
    
}

/**
 * @brief Method to check if wall exists to the left of the robot
 * @return True if yes, else false
*/
bool fp::API::wallLeft() {
    std::cout << "wallLeft" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
    
}

/**
 * @brief Moves the robot forward by one cell
 */
void fp::API::moveForward() {
    std::cout << "moveForward" << std::endl;
    std::string response;
    std::cin >> response;
    if (response != "ack") {
        std::cerr << response << std::endl;
        throw;
    }
    
}

/**
 * @brief Turns the robot 90 degrees to the right
*/
void fp::API::turnRight() {
    std::cout << "turnRight" << std::endl;
    std::string ack;
    std::cin >> ack;
    
}

/**
 * @brief Turns the robot 90 degrees to the left
 */
void fp::API::turnLeft() {
    std::cout << "turnLeft" << std::endl;
    std::string ack;
    std::cin >> ack;
    
}

/**
 * @brief Displays a wall at the given position
 * @param x X co-ordinate of the cell
 * @param y Y co-ordinate of the cell
 * @param direction Direction of the wall (n, e, s or w)
 */
void fp::API::setWall(int x, int y, char direction) {
    std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
    
}

/**
 * @brief Clears the wall at the given position
 * @param x X co-ordinate of the cell
 * @param y Y co-ordinate of the cell
 * @param direction Direction of the wall (n, e, s or w)
*/
void fp::API::clearWall(int x, int y, char direction) {
    std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
    
}

/**
 * @brief Sets color of the cell at the given position
 * @param x X co-ordinate of the cell
 * @param y Y co-ordinate of the cell
 * @param color Character of the desired color
*/
void fp::API::setColor(int x, int y, char color) {
    std::cout << "setColor " << x << " " << y << " " << color << std::endl;
    
}

/**
 * @brief Clears the color of the cell at the given position
 * @param x X co-ordinate of the cell
 * @param y Y co-ordinate of the cell
*/
void fp::API::clearColor(int x, int y) {
    std::cout << "clearColor " << x << " " << y << std::endl;
    
}

/**
 * @brief Clears color of all the cells
*/
void fp::API::clearAllColor() {
    std::cout << "clearAllColor" << std::endl;
    
}

/**
 * @brief Sets text of the cell at the given position
 * @param x X co-ordinate of the cell
 * @param y Y co-ordinate of the cell
 * @param text Desired text
*/
void fp::API::setText(int x, int y, const std::string& text) {
    std::cout << "setText " << x << " " << y << " " << text << std::endl;
    
}

/**
 * @brief Clears text of the cell at the given position
 * @param x X co-ordinate of the cell
 * @param y Y co-ordinate of the cell
*/
void fp::API::clearText(int x, int y) {
    std::cout << "clearText " << x << " " << y << std::endl;
    
}

/**
 * @brief Clears text of all the cells
*/
void fp::API::clearAllText() {
    std::cout << "clearAllText" << std::endl;
    
}

/**
 * @brief Method to check if the reset button was pressed
 * @return True if reset button was pressed, else false
*/
bool fp::API::wasReset() {
    std::cout << "wasReset" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
    
}

/**
 * @brief Method to allow the robot to be moved back to the start of the maze
*/
void fp::API::ackReset() {
    std::cout << "ackReset" << std::endl;
    std::string ack;
    std::cin >> ack;
    
}
