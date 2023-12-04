//
// Created by user on 03.12.2023.
//

#ifndef PARTICLE_V1_COMPARISON_H
#define PARTICLE_V1_COMPARISON_H

// Comparison - класс для удобной работы с отрезками значений параметров, переменных.
// difference - разница между наибольшим и наименьшим значением.
// max, min - максимальное и минимальное значения соответственно.

class Comparison {
public:
    Comparison(double max, double min): max_value(max),min_value(min)
    {};
    double difference() const{return max_value - min_value;}
    double min() const {return min_value;}
    double max() const {return max_value;}
private:
    double max_value;
    double min_value;
};

#endif //PARTICLE_V1_COMPARISON_H
