#pragma once
#include <iostream>
#include <string>
#include "../LandBasedRobot/LandBasedRobot.h"
namespace fp{
/**
 * @brief Concrete class that derives from LandBasedRobot
 *
 */
class LandBasedWheeled : public LandBasedRobot{
protected:
    /// Number of wheels mounted on the robot
    int wheel_number;
    
public:
    
    /**
     * @brief Default constructor to initialize attribute values
     */
    LandBasedWheeled()
    : LandBasedRobot(){
        wheel_number = 0;
        std::cout << "LandBasedWheeled default constructor\n";
    }
    
    /**
     * @brief Constructor to set all object attributes
     * @param name The name you want to set it to
     * @param speed The speed you want to set it to
     * @param width The width you want to set it to
     * @param length The length you want to set it to
     * @param height The height you want to set it to
     * @param capacity The capacity you want to set it to
     * @param x The x value you want to set it to
     * @param y The y value you want to set it to
     * @param dir The direction you want to set it to
     * @param wheel_num The wheel number you want to set it to
     */
    LandBasedWheeled(std::string name, double speed, double width, double length, double height, double capacity, int x, int y, char dir, int wheel_num)
    : LandBasedRobot(name, speed, width, length, height, capacity, x, y, dir){
        wheel_number = wheel_num;
        std::cout << "LandBasedWheel constructor called\n";
    }
        
        /**
         * @brief Destructor for the dervied class LandBasedWheeled
         */
        ~LandBasedWheeled(){
            std::cout << "called destructor LandBasedWheeled\n";
        }
        
        // Method prototypes
        virtual char GetDirection() override;
        virtual void MoveForward() override;
        virtual void TurnLeft() override;
        virtual void TurnRight() override;
        void SpeedUp(int speed);
        
        // Accessors
        /**
         * @brief Getter method to get the number of wheels
         * @return Number of wheels mounted on the robot
         */
        int getWheelNum() const{
            return wheel_number;
        }
        
        // Mutators
        /**
         * @brief Setter method to set the number of wheels for the robot
         * @param wheelNum The number of wheels you want to set it to
         */
        void setWheelNum(int wheelNum){
            wheel_number = wheelNum;
        }
    };
}
