//
// Created by user on 03.12.2023.
//

#include "Plane.h"
#include "UsefulFeatures.h"

Plane::Plane(Comparison x, Comparison y, Comparison z, double new_h, double new_w, const Angles &init_angles) {
    origin.x = rand_in(x.min(),x.difference());
    origin.y = rand_in(y.min(),z.difference());
    origin.z = rand_in(z.min(),z.difference());
    sizes.h = new_h;
    sizes.w = new_w;
    angles = init_angles;
}