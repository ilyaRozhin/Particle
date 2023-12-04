//
// Created by user on 04.12.2023.
//

#include "UsefulFeatures.h"

double rand_small(){
    return (double)(rand()) / RAND_MAX;
}
double rand_in(double min, double difference){
    return min + (double)(rand()) / RAND_MAX*difference;
}
Point rotation(Point point,Point origin,double phi,double psi,double eps){
    double x = point.x * (cos(phi)*cos(psi) - sin(phi)*sin(eps)*sin(psi)) -
               - point.y * (sin(phi)*cos(eps)) +
               + point.z * (cos(phi)*cos(psi) + cos(psi)*sin(phi)*sin(eps)) + origin.x;
    double y = point.x * (cos(psi)*sin(phi) - cos(phi)*sin(eps)*sin(psi)) +
               + point.y * (cos(phi)*cos(eps)) +
               + point.z * (sin(phi)*cos(psi) - cos(psi)*cos(phi)*sin(eps)) + origin.y;
    double z = point.x * (-sin(psi)*cos(eps)) +
               + point.y * sin(eps) +
               + point.z * (cos(eps)*cos(psi)) + origin.z;
    return Point(x,y,z);
}
double rutherford_section(int element_number,double energy, double angle){
    return 1.62*10e-20*pow((double)(element_number),2)/(tan(angle/2)*pow(energy,2));
}