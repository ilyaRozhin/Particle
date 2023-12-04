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
    double c_ps = cos(psi);
    double c_ph = cos(phi);
    double c_ep = cos(eps);
    double s_ps = sin(psi);
    double s_ph = sin(phi);
    double s_ep = sin(eps);
    double x1 = point.x;
    double y1 = point.y;
    double z1 = point.z;
    double x = x1 * (c_ph*c_ps - s_ph*s_ep*s_ps) -
               - y1 * (s_ph*c_ep) +
               + z1 * (c_ph*c_ps + c_ps*s_ph*s_ep) + origin.x;
    double y = x1 * (c_ps*s_ph - c_ph*s_ep*s_ps) +
               + y1 * (c_ph*c_ep) +
               + z1 * (s_ph*c_ps - c_ps*c_ph*s_ep) + origin.y;
    double z = x1 * (-s_ps*c_ep) +
               + y1 * s_ep +
               + z1 * (c_ep*c_ps) + origin.z;
    return Point(x,y,z);
}
double rutherford_section(int element_number,double energy, double angle){
    return 1.62 * 10e-20 * pow((double)(element_number),2) / (tan(angle/2)*pow(energy,2));
}