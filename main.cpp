//
//  main.cpp
//  Final_Project_Group_8
//
//  Created by Jevay Aggarwal on 11/16/19.
//  Copyright © 2019 Jevay Aggarwal. All rights reserved.
//

#include "src/LandBasedRobot/LandBasedRobot.h"
#include "src/LandBasedTracked/LandBasedTracked.h"
#include "src/LandBasedWheeled/LandBasedWheeled.h"
#include "src/Algorithm/Algorithm.h"
#include "src/Maze/Maze.h"
#include <iostream>

int main(){
    std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>("Husky", 2, 0, 10, 10, 10, 0, 0, 'N', 0);
    fp::Maze m;
    m.initializeMaze();
    fp::Algorithm algo;
    algo.solve(wheeled, m);
    
    return 0;
}
