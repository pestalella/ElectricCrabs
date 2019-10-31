#pragma once

#include <random>

namespace Utils {
    typedef std::mt19937 rng_type;
    extern rng_type rng;

    void initRandom();
    
    double randomCapacitorValue();
    double randomResistorValue();

    double scaledToPrefix(double value);
    char valueToPrefix(double value);


}