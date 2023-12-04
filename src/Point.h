//
// Created by user on 03.12.2023.
//

#ifndef PARTICLE_V1_POINT_H
#define PARTICLE_V1_POINT_H

class Point {
public:
    Point() = default;
    Point(double init_x,double init_y, double init_z){
        x = init_x;
        y = init_y;
        z = init_z;
    }
    double x = 0;
    double y = 0;
    double z = 0;
};

#endif //PARTICLE_V1_POINT_H
