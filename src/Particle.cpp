//
// Created by user on 03.12.2023.
//

#define _USE_MATH_DEFINES

#include "Particle.h"
#include "UsefulFeatures.h"
#include <cmath>

Particle::Particle(Plane &plane, const Probability &probability, const Comparison &energy_values) {
    init_type(probability);
    init_energy(energy_values);
    init_coordinates(plane);
    init_angles();
    init_guide_vector(plane.get_origin(),plane.get_angles());
}

void Particle::set_coordinates(const Point &new_point) {
    point = new_point;
}

void Particle::set_angels(const Angles &new_angles) {
    angles = new_angles;
}

void Particle::set_energy(double new_energy) {
    energy = new_energy;
}

void Particle::set_guide_vector(const UnitVector &new_vector) {
    guide_vector = new_vector;
}

void Particle::set_module(double new_module) {
    module_speed = new_module;
}

void Particle::init_type(const Probability &probability) {
    while (true) {
        if(probability.electron<=rand_small()){
            type_particle = TypeParticle::ELECTRON;
            mass = 9.1093837e-31;
            atom_mass = 5.48579909067e-4;
            break;
        }
        if(probability.proton<=rand_small()){
            type_particle = TypeParticle::PROTON;
            mass = 1.67262192e-27;
            atom_mass = 1.007276466;
            break;
        }
        if(probability.neutron<=rand_small()){
            type_particle = TypeParticle::NEUTRON;
            mass = 1.67492749e-24;
            atom_mass =1.008664915;
            break;
        }
    }
}

void Particle::init_angles() {
    angles.epsilon = rand_small()*M_PI;
    angles.psi = rand_small()*M_PI;
    angles.phi = 0;
}

void Particle::init_energy(Comparison values_energy) {
    energy = rand_in(values_energy.min(),values_energy.difference());
    module_speed = sqrt(2*energy/mass);
}

// Функция предназначена для инициализации направляющего вектора генерируемой частицы
// Предполагается, что местом генерации выбрана некоторая конечная плоскость прямоугольной формы
void Particle::init_guide_vector(Point origin, Angles panel_angles) {
    Point point_z  = rotation(Point(1,0,0),
                              origin,panel_angles.phi,panel_angles.psi,panel_angles.epsilon);
    point_z = rotation(point_z,origin,angles.phi,angles.psi,angles.epsilon);
    UnitVector new_guide_vector = UnitVector(point_z.x-origin.x,point_z.y-origin.y,point_z.z-origin.z);
    guide_vector = new_guide_vector;
}

// С помощью данной функции в прямоугольной области выбираем случайную точку
// Далее после череды поворотов, координаты точки изменяются
void Particle::init_coordinates(Plane &plane) {
    Point origin = plane.get_origin();
    Sizes sizes = plane.get_sizes();
    Point rand_point(rand_in(0,sizes.w),rand_in(0,sizes.h),0);
    Angles plane_angles = plane.get_angles();
    point = rotation(rand_point,origin,
                     plane_angles.phi,plane_angles.psi,plane_angles.epsilon);
    old_point = point;
}

// Функция рассеяния моделирует столкновение с некоторой частицей
// В случайный момент времени, который определяется с помощью
// Соотношения Резерфорда и длине пробега частицы
void Particle::diffusion(double step_modeling, int element_number) {
    bool elastic = (rand_small() >= 0.5);

    double angle = rand_small() * 360;
    double average_length = (atom_mass/6.02e23) * 10e-29 * rutherford_section(element_number,energy,angle);
    double length = (-1) * average_length * log(1-rand_small());

    length_way += module_speed * step_modeling;
    if(length_way > length){
        if(rand_small() >= 0.5){
            angles.epsilon = angle;
        } else {
            angles.psi = angle;
        }
    }
    if(elastic){
        energy = energy * 0.9;
        module_speed = sqrt(energy*2);
    }
}

void Particle::update_point(double step_modeling) {
    double step_length = step_modeling * module_speed;
    old_point = point;
    point.x += guide_vector.i * step_length;
    point.y += guide_vector.j * step_length;
    point.z += guide_vector.k * step_length;
    if (angles.psi!=0 || angles.epsilon!=0){
        Point point_z  = rotation(Point(guide_vector.i,guide_vector.j,guide_vector.k),
                                  point,angles.phi,angles.psi,angles.epsilon);
        UnitVector new_guide_vector = UnitVector(point_z.x-point.x,point_z.y-point.y,point_z.z-point.z);
        guide_vector = new_guide_vector;
    }
}