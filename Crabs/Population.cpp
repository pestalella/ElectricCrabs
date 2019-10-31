#include "pch.h"
#include "Population.h"

#include <iostream>

Population::Population()
{
    
}


Population::~Population()
{
}

Population Population::generateInitialPopulation()
{
    Population newPop;
    for (int i = 0; i < 3; ++i)
    {
        auto newCircuit = Circuit::generateRandomCircuit(4, 4);
        std::cout << "--- Circuit " << i << " ---" << std::endl;
        std::cout << newCircuit.toSPICEString();
        newPop.circuits.push_back(newCircuit);
    }
    return newPop;
}
