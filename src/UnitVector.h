//
// Created by user on 03.12.2023.
//

#ifndef PARTICLE_V1_UNITVECTOR_H
#define PARTICLE_V1_UNITVECTOR_H

class  UnitVector{
public:
    UnitVector() = default;
    UnitVector(double init_i,double init_j,double init_k){
        i = init_i;
        j = init_j;
        k = init_k;
    }
    double i = 0;
    double j = 0;
    double k = 0;
};

#endif //PARTICLE_V1_UNITVECTOR_H
