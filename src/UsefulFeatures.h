//
// Created by user on 04.12.2023.
//

#ifndef PARTICLE_V1_USEFULFEATURES_H
#define PARTICLE_V1_USEFULFEATURES_H

#include <iostream>
#include <cmath>
#include "Point.h"

// Генератор случайных чисел от 0 до 1 равномерно распределенных.
double rand_small();

double rand_in(double min, double difference);

// Функция поворота, использовались стандартные матрицы поворота
// для перехода в новую систему координат и наоборот
Point rotation(Point point,Point origin,double phi,double psi,double eps);

double rutherford_section(int element_number,double energy, double angel);

#endif //PARTICLE_V1_USEFULFEATURES_H
