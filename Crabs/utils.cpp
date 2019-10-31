#include "pch.h"

#include <algorithm>
#include <cmath>
#include <chrono>

#include "utils.h"

namespace Utils {
    std::uniform_real_distribution<> resistorValues(-3, 6);  // from 1E-3 to 1E6
    std::uniform_real_distribution<> capacitorValues(-12, -2);  // from 1E-12 to 1E-2

    rng_type rng;

    void initRandom()
    {
        rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    }

    double randomCapacitorValue()
    {
        return capacitorValues(rng);
    }

    double randomResistorValue()
    {
        return resistorValues(rng);
    }

    double scaledToPrefix(double value)
    {
        static double scaleFactors[] = { 1E15, 1E12, 1E9, 1E6, 1E3, 1, 1E-3, 1E-6, 1E-9, 1E-12 };
        int exponent = static_cast<int>(floor(log10(value)));
        int idx = std::max(0, std::min(27, exponent + 15)) / 3; // min is 15 (femto)
        return value*scaleFactors[idx];
    }
    
    char valueToPrefix(double value)
    {
        char prefixes[] = "fpnum kMGT";

        int exponent = static_cast<int>(floor(log10(value)));
        int idx = std::max(0, std::min(27, exponent + 15)) / 3; // min is 15 (femto)

        return prefixes[idx];
    }


}