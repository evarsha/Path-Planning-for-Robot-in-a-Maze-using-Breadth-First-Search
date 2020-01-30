#pragma once
#include <iostream>
#include <string>
#include "../LandBasedRobot/LandBasedRobot.h"
namespace fp{
/**
 * @brief Concrete class that derives from LandBasedRobot
 *
 */
class LandBasedTracked : public LandBasedRobot{
protected:
    /// Type of track mounted on the robot
    std::string track_type;
    
public:
    
    /**
     * @brief Default constructor to initialize attribute values
     */
    LandBasedTracked()
    : LandBasedRobot(){
        track_type = "";
        std::cout << "LandBasedTracked default constructor\n";
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
     * @param track The track type you want to set it to
     */
    LandBasedTracked(std::string name, double speed, double width, double length, double height, double capacity, int x, int y, char dir, std::string track)
    : LandBasedRobot(name, speed, width, length, height, capacity, x, y, dir){
        track_type = track;
        std::cout << "LandBasedTracked constructor called\n";
    }
        
        /**
         * @brief Destructor for the dervied class LandBasedWheeled
         */
        ~LandBasedTracked(){
            std::cout << "called destructor LandBasedTracked\n";
        }
        
        // Method prototypes
        virtual char GetDirection() override;
        virtual void MoveForward() override;
        virtual void TurnLeft() override;
        virtual void TurnRight() override;
        
        // Accessors
        /**
         * @brief Getter method to get the number of wheels
         * @return Number of wheels mounted on the robot
         */
        std::string getTrackType() const{
            return track_type;
        }
        
        // Mutators
        /**
         * @brief Setter method to set the number of wheels for the robot
         * @param track The track type you want to set it 
         */
        void setWheelNum(std::string track){
            track_type = track;
        }
    };
}
