//
// Created by user on 03.12.2023.
//

#ifndef PARTICLE_V1_POINT_H
#define PARTICLE_V1_POINT_H

class Point {
public:
    Point(){
        x = 0;
        y = 0;
        z = 0;
    }
    Point(double init_x,double init_y, double init_z){
        x = init_x;
        y = init_y;
        z = init_z;
    }
    double x;
    double y;
    double z;
};

#endif //PARTICLE_V1_POINT_H
