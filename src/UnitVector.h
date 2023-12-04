//
// Created by user on 03.12.2023.
//

#ifndef PARTICLE_V1_UNITVECTOR_H
#define PARTICLE_V1_UNITVECTOR_H

class  UnitVector{
public:
    UnitVector(){
        i = 0;
        j = 0;
        k = 0;
    }
    UnitVector(double init_i,double init_j,double init_k){
        i = init_i;
        j = init_j;
        k = init_k;
    }
    double i;
    double j;
    double k;
};

#endif //PARTICLE_V1_UNITVECTOR_H
