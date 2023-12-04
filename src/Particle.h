//
// Created by user on 03.12.2023.
//


#ifndef PARTICLE_V1_PARTICLE_H
#define PARTICLE_V1_PARTICLE_H

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Point.h"
#include "Angles.h"
#include "UnitVector.h"
#include "Probability.h"
#include "Comparison.h"
#include "Plane.h"
#include "TypeParticle.h"

using namespace std;

// Объявление класса Частица (Paritcle)
// Наборы геттеров сеттеров для работы с private полями
// Наиболее важные методы diffusion, update_point и все что связано с инициализацией

class Particle {
public:
    Particle(Plane &plane, const Probability &probability, const Comparison &energy_values);

    Point get_coordinates() {return point;}
    Angles get_angels() {return angles;}
    UnitVector get_vector() {return guide_vector;}
    string get_type() {return type_particle;}
    double get_module() const {return module_speed;}
    double get_energy() const {return energy;}
    bool get_tracking() const {return tracking;}

    void set_coordinates(const Point &point);
    void set_angels(const Angles &angles);
    void set_energy(double new_energy);
    void set_guide_vector(const UnitVector &new_vector);
    void set_module(double new_module);
    void set_tracking(bool on_off) {tracking = on_off;}

    void diffusion(double step_modeling, int element_number);
    void update_point(double step_modeling);

private:
    Point point;
    Point old_point;
    Angles angles;
    UnitVector guide_vector;

    double module_speed;
    double mass;
    double atom_mass;
    double energy;
    double length_way;

    TypeParticle type_particle;
    bool tracking;

    void init_angles();
    void init_type(const Probability &probability);
    void init_energy(Comparison energy);
    void init_guide_vector(Point origin,Angles angles);
    void init_coordinates(Plane &plane);
};


#endif //PARTICLE_V1_PARTICLE_H
