cmake_minimum_required(VERSION 3.26)
project(particle_v1)

set(CMAKE_CXX_STANDARD 17)

add_executable(particle_v1 main.cpp
        src/Particle.cpp
        src/Particle.h
        src/Point.h
        src/Angles.h
        src/UnitVector.h
        src/Probability.h
        src/Comparison.h
        src/Plane.cpp
        src/Plane.h
        src/Sizes.h
        src/UsefulFeatures.h
        src/UsefulFeatures.cpp
        src/TypeParticle.h)
