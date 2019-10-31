#pragma once

#include "Circuit.h"

#include <vector>

class Population
{
public:
    Population();
    ~Population();

    static Population generateInitialPopulation();

private:
    std::vector<Circuit> circuits;
};

