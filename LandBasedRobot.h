#pragma once
#include <iostream>
#include <string>

namespace fp{
/**
 * @brief Abstract class with virtual methods for the derived classes to inheret from
 */
class LandBasedRobot{
protected:
    /// Name of the robot
    std::string name_;
    /// Driving speed of the robot
    double speed_;
    /// Width of the base of the robot
    double width_;
    /// Length of the base of the robot
    double length_;
    /// Height of the base of the robot
    double height_;
    /// Payload of the arm
    double capacity_;
    /// X coordinate of the robot in the maze
    int x_;
    /// Y coordinate of the robot in the maze
    int y_;
    /// Direction the robot is facing in the maze
    char direction_;
    
public:
    
    /**
     * @brief Default constructor to initialize attribute values
     */
    LandBasedRobot(): name_{"NONE"}, speed_{0.0}, width_{0.0}, length_{0.0}, height_{0.0}, capacity_{0.0}, x_{0}, y_{0}{
        std::cout << "LandBasedRobot default constructor\n";
        }
    
        /**
         * @brief Constructor to set all the object attributes 
         * @param name The name you want to set it to
         * @param speed The speed you want to set it to
         * @param width The width you want to set it to
         * @param length The length you want to set it to
         * @param height The height you want to set it to
         * @param capacity The capacity you want to set it to
         * @param x The x value you want to set it to
         * @param y The y value you want to set it to
         * @param dir The direction you want to set it to
         */
    LandBasedRobot(std::string name, double speed, double width, double length, double height, double capacity, int x, int y, char dir)
        : name_{name}, x_{x}, y_{y}, speed_{speed}, width_{width}, length_{length}, height_{height}, capacity_{capacity}, direction_{dir}{
            std::cout << "LandBasedRobot constructor called\n";
        }
        
    /**
     * @brief Destructor for the base class
     */
    ~LandBasedRobot(){
            std::cout << "called destructor LandBasedRobot\n";
        }
        
        // Method prototypes
        virtual char GetDirection() = 0;
        virtual void MoveForward() = 0;
        virtual void TurnLeft() = 0;
        virtual void TurnRight() = 0;
        
        // Accessors
        /**
         * @brief Getter method to get the name of the robot
         * @return Name of the robot
         */
        std::string getName() const{
            return name_;
        }
        
        /**
         * @brief Getter method to get the speed of the robot
         * @return Speed of the robot
         */
        double getSpeed() const{
            return speed_;
        }
        
        /**
         * @brief Getter method to get the width of the base of the robot
         * @return Width of the base of the robot
         */
        double getWidth() const{
            return width_;
        }
        
        /**
         * @brief Getter method to get the length of the base of the robot
         * @return Length of the base of the robot
         */
        double getLength() const{
            return length_;
        }
        
        /**
         * @brief Getter method to get the height of the base of the robot
         * @return Height of the base of the robot
         */
        double getHeight() const{
            return height_;
        }
        
        /**
         * @brief Getter method to get the payload of the robot arm
         * @return Payload of the arm
         */
        double getCapacity() const{
            return capacity_;
        }
        
        /**
         * @brief Getter method to get the X coordinate of the robot in the maze
         * @return X coordinate of the robot in the maze
         */
        int getX() const{
            return x_;
        }
        
        /**
         * @brief Getter method to get the Y coordinate of the robot in the maze
         * @return Y coordinate of the robot in the maze
         */
        int getY() const{
            return y_;
        }
        
        // Mutators
        /**
         * @brief Setter method to set the name of the robot
         * @param name The name you want to set it to
         */
        void setName(std::string name){
            name_ = name;
        }
        
        /**
         * @brief Setter method to set the speed of the robot
         * @param speed The speed you want to set it to
         */
        void setSpeed(double speed){
            speed_ = speed;
        }
        
        /**
         * @brief Setter method to set the width of the base of the robot
         * @param width The width of the base you want to set it to
         */
        void setWidth(double width){
            width_ = width;
        }
        
        /**
         * @brief Setter method to set the length of the base of the robot
         * @param length The length of the base you want to set it to
         */
        void setLength(double length){
            length_ = length;
        }
        
        /**
         * @brief Setter method to set the height of the base of the robot
         * @param height The height of the base you want to set it to
         */
        void setHeight(double height){
            height_ = height;
        }
        
        /**
         * @brief Setter method to set the payload of the robot arm
         * @param capacity The payload you want to set it to
         */
        void setCapacity(double capacity){
            capacity_ = capacity;
        }
        
        /**
         * @brief Setter method to set the X coordinate of the robot in the maze
         * @param x The x value you want to set it to
         */
        void setX(int x){
            x_ = x;
        }
        
        /**
         * @brief Setter method to set the Y coordinate of the robot in the maze
         * @param y The y value you want to set it to
         */
        void setY(int y){
            y_ = y;
        }
        
        /**
         * @brief Setter method to set the direction of the robot in the maze
         * @param dir The direction you want to set it to
         */
        void setDirection(char dir){
            direction_ = dir;
        }
    };
}
