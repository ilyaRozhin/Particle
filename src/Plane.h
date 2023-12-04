//
// Created by user on 03.12.2023.
//
#ifndef PARTICLE_V1_PLANE_H
#define PARTICLE_V1_PLANE_H

#include "Point.h"
#include "UnitVector.h"
#include "Comparison.h"
#include "Angles.h"
#include "Sizes.h"

// Класс Plane вспомогательный класс для решения основной задачи.
// Представляет собой модель плоскости прямоугольного вида в
// некотором заданном ограниченном пространстве. На данной плоскости генерируются
// частицы разного вида. Может быть повернута относительно
// направляющего вектора (единичный вектор e_z) и ортогональных ему (e_x,e_y).

class Plane {
public:
    Plane(Comparison x, Comparison y, Comparison z, double h, double w, const Angles &angles);
    Point get_origin(){return origin;}
    Angles get_angles(){return angles;}
    Sizes get_sizes(){return sizes;}
private:
    Point origin;
    Sizes sizes;
    Angles angles;
};

#endif //PARTICLE_V1_PLANE_H
